// Fill out your copyright notice in the Description page of Project Settings.


#include "SWorldPlayerCont.h"
#include "../SGameMain.h"
#include "PaperSprite.h"
#include "PaperSpriteActor.h"
#include "PaperSpriteComponent.h"
#include "SWorldFloor.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "SWorldUnitSpriteCastle.h"
#include "SWorldUnitSpriteMonster.h"
#include "Floor/SWorldFloorTiles.h"


ASWorldPlayerCont::ASWorldPlayerCont() {
	USWorldFloorTiles::DecompressWorldLayers();
	USWorldFloorTiles::loadFileAndDecompress();

	if (USWorldFloorTiles::AllWorldMaps.Find("WorldMap")) {
		ASWorldFloor::CurrentWorldMap = *(USWorldFloorTiles::AllWorldMaps.Find("WorldMap"));
		GLog->Logf(TEXT("Level is Loaded"));
	}
	else {
	
		GLog->Logf(TEXT("Error Level "));
	}

	
	bShowMouseCursor = true;
	bEnableClickEvents = true;
}




void ASWorldPlayerCont::BeginPlay() {

	Super::BeginPlay();

	ASWorldUnitSpriteCastle::loadBaseCastle();
	FVector cameraPos(USWorldCoord::getUnitPosX(540, 586), 50, USWorldCoord::getUnitPosY(540, 586));
	FRotator CameraRotator(0, -90, 0);
	MainCamera = GetWorld()->SpawnActor<ACameraActor>(ACameraActor::StaticClass(), cameraPos, CameraRotator);
	MainCamera->GetCameraComponent()->bUsePawnControlRotation = false;
	MainCamera->GetCameraComponent()->SetProjectionMode(ECameraProjectionMode::Orthographic);
	MainCamera->GetCameraComponent()->SetMobility(EComponentMobility::Movable);
	MainCamera->GetCameraComponent()->SetHiddenInGame(false);
	MainCamera->GetCameraComponent()->SetOrthoWidth(1024);
	MainCamera->GetCameraComponent()->bConstrainAspectRatio = false;
	SetViewTarget(MainCamera);

	

}


void ASWorldPlayerCont::SetupInputComponent() {

	Super::SetupInputComponent();
	InputComponent->BindAxis("LeftArrow", this, &ASWorldPlayerCont::moveCameraLeft);
	InputComponent->BindAxis("RightArrow", this, &ASWorldPlayerCont::moveCameraRight);
	InputComponent->BindAxis("DownArrow", this, &ASWorldPlayerCont::moveCameraDown);
	InputComponent->BindAxis("UpArrow", this, &ASWorldPlayerCont::moveCameraUp);
	InputComponent->BindAxis("Scroll", this, &ASWorldPlayerCont::zoomCamera);
	InputComponent->BindAction("ShowWorldCorner", IE_Pressed, this, &ASWorldPlayerCont::showWorldCorner);


}

void ASWorldPlayerCont::showWorldCorner() {

	FScreenCornersToWorld ScreenCorners = getScreenCornerCoord();
	destroyUnitsInColumns(ScreenCorners);
	return;

	for (TActorIterator<ASWorldFloor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr) {
			ActorItr->Destroy();
			PRINT_STRING(FString::Printf(TEXT("Test")));
		}
			
	}
	refreshWorldFloor();
	

}

FScreenCornersToWorld ASWorldPlayerCont::getScreenCornerCoord() {
	FScreenCornersToWorld ScreenCorners;
	FVector WorldDir;
	int32 sizeX, sizeY;
	GetViewportSize(sizeX, sizeY);
	GetWorld()->GetGameViewport();
	DeprojectScreenPositionToWorld(0     , 0     , ScreenCorners.TopLeft, WorldDir);
	DeprojectScreenPositionToWorld(sizeX , 0     , ScreenCorners.TopRight, WorldDir);
	DeprojectScreenPositionToWorld(0     , sizeY , ScreenCorners.BottomLeft, WorldDir);
	DeprojectScreenPositionToWorld(sizeX , sizeY , ScreenCorners.BottomRight, WorldDir);


	ScreenCorners.xCoordStart = USWorldCoord::getUnitXCoordFromPos(ScreenCorners.TopLeft.X, ScreenCorners.TopLeft.Z) - 2;
	ScreenCorners.yCoordStart = USWorldCoord::getUnitYCoordFromPos(ScreenCorners.TopLeft.X, ScreenCorners.TopLeft.Z);
	ScreenCorners.widthInUnit = (ScreenCorners.TopRight.X - ScreenCorners.TopLeft.X) / (S_WORLD_UNIT_WIDTH ) + 4;
	ScreenCorners.heightInUnit = (ScreenCorners.TopLeft.Z - ScreenCorners.BottomLeft.Z) / (S_WORLD_UNIT_WIDTH / 2) + 4;

	return ScreenCorners;
}


void ASWorldPlayerCont::refreshWorldFloor() {
	FScreenCornersToWorld ScreenCorners = getScreenCornerCoord();

	static int32 Count = 0;

	
	for (int32 xCoord = 0; xCoord <= ScreenCorners.widthInUnit; xCoord += 1) {
		for (int32 yCoord = 0; yCoord <= ScreenCorners.heightInUnit; yCoord += 1) {

			int32 x = ScreenCorners.xCoordStart + xCoord + yCoord;
			int32 y = ScreenCorners.yCoordStart + xCoord - yCoord; 

			ASWorldFloor::addWorldFloor(x, y, GetWorld());
			ASWorldFloor::addWorldFloor(x + 1, y, GetWorld());


		}
	}
	destroyUnitsInColumns(ScreenCorners);
	destroyUnitsInRaws(ScreenCorners);

}

void ASWorldPlayerCont::destroyUnitsInColumns(FScreenCornersToWorld& ScreenCorner) {

	uint16 heightInUnit = ScreenCorner.heightInUnit + 8;
	int16 xStart = ScreenCorner.xCoordStart -2;
	int16 yStart = ScreenCorner.yCoordStart;
	int16 xEnd = xStart + ScreenCorner.widthInUnit ;
	int16 yEnd = yStart - ScreenCorner.widthInUnit -2;

	for (uint16 raw = 0; raw < heightInUnit; raw++) {
		//left col
		ASWorldFloor::destroyWorldFloor(xStart + raw, yStart + raw);
		ASWorldFloor::destroyWorldFloor(xStart + raw + 1, yStart + raw);

		// right col
		ASWorldFloor::destroyWorldFloor(xEnd + raw, yEnd + raw);
		ASWorldFloor::destroyWorldFloor(xEnd + raw +1, yEnd + raw);

	}

}


void ASWorldPlayerCont::destroyUnitsInRaws(FScreenCornersToWorld& ScreenCorner) {

	uint16 widthInUnit = ScreenCorner.widthInUnit + 8;
	int16 xStart = ScreenCorner.xCoordStart - 2;
	int16 yStart = ScreenCorner.yCoordStart;
	int16 xEnd = xStart + ScreenCorner.heightInUnit + 2;
	int16 yEnd = yStart + ScreenCorner.heightInUnit + 3;

	for (uint16 col = 0; col < widthInUnit; col++) {
		//left col
		ASWorldFloor::destroyWorldFloor(xStart + col, yStart - col);
		ASWorldFloor::destroyWorldFloor(xStart + col + 1, yStart - col);

		// right col
		ASWorldFloor::destroyWorldFloor(xEnd + col, yEnd - col);
		ASWorldFloor::destroyWorldFloor(xEnd + col + 1, yEnd - col);

	}

}