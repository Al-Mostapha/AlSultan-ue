// Fill out your copyright notice in the Description page of Project Settings.


#include "SWorldFloor.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "SWorldCoord.h"


uint8 ASWorldFloor::WorldFloorBaseSkin[1200][1200];
FUnitsInTheWorld ASWorldFloor::UnitsInTheWorld[WORLD_WIDTH_IN_UNIT][WORLD_HEIGHT_IN_UNIT];

FWorldTiledMap ASWorldFloor::CurrentWorldMap;


void ASWorldFloor::BeginPlay() {

	Super::BeginPlay();
}

ASWorldFloor::ASWorldFloor(){

	Floor = CreateDefaultSubobject<class UPaperSpriteComponent>(TEXT("PaperSprite"));
	RootComponent = Floor;
	Layer_1 = CreateDefaultSubobject<class UPaperSpriteComponent>(TEXT("Layer_1"));
	Layer_2 = CreateDefaultSubobject<class UPaperSpriteComponent>(TEXT("Layer_2"));
	Water = CreateDefaultSubobject<class UPaperSpriteComponent>(TEXT("Water"));
	Layer_1->SetupAttachment(RootComponent);
	Layer_2->SetupAttachment(RootComponent);
	Water->SetupAttachment(RootComponent);
	Water->SetCollisionProfileName("BlockAllDynamic");
	Floor->SetTranslucentSortPriority(0);
	Layer_1->SetTranslucentSortPriority(1);
	//Sprite->SetupAttachment(RootComponent);
	/**int WorldFloorType = (int)WorldFloorBaseSkin[xCoord][yCoord];
	Sprite->SetSprite(WorldFloorSprite[=WorldFloorType]);*/
};




bool ASWorldFloor::setWorldFloor(int32 xCoord, int32 yCoord, UWorld* WorldLvl) {
	



	return true;
};




bool ASWorldFloor::addWorldFloor(int32 xCoord, int32 yCoord, UWorld* WorldLvl) {

	
	int32 xReal = USWorldCoord::getRealCoordX(xCoord);
	int32 yReal = USWorldCoord::getRealCoordY(yCoord);
	
	FUnitsInTheWorld* UnitInWorld = &ASWorldFloor::UnitsInTheWorld[xReal][yReal];
	if (UnitInWorld->bInWorld)
		return false;
	FWorldUnitTileType& WorldFloorType = CurrentWorldMap.MapTile[yReal * 1201 + xReal];
	FVector Vect(USWorldCoord::getUnitPosX(xCoord, yCoord), 0, USWorldCoord::getUnitPosY(xCoord, yCoord));
	FRotator Rot(0, 0, 0);
	UnitInWorld->UnitFloor = WorldLvl->SpawnActor<ASWorldFloor>(ASWorldFloor::StaticClass(), Vect , Rot);
	UnitInWorld->UnitFloor->xReal = xReal;
	UnitInWorld->UnitFloor->yReal = yReal;
	UnitInWorld->UnitFloor->addWorldFloorLayers(WorldFloorType);
	UnitInWorld->bInWorld = true;
	return true;
};


bool ASWorldFloor::addWorldFloorLayers(FWorldUnitTileType& WorldFloorType) {
	
	
	if(WorldFloorType.Land <= CurrentWorldMap.SpriteList.Num())
		Floor->SetSprite(CurrentWorldMap.SpriteList[WorldFloorType.Land].Sprite);
	if(WorldFloorType.Layer0 <= CurrentWorldMap.SpriteList.Num())
		Layer_1->SetSprite(CurrentWorldMap.SpriteList[WorldFloorType.Layer0].Sprite);
	if(WorldFloorType.Layer1 <= CurrentWorldMap.SpriteList.Num())
		Layer_2->SetSprite(CurrentWorldMap.SpriteList[WorldFloorType.Layer1].Sprite);
	if(WorldFloorType.Layer2 <= CurrentWorldMap.SpriteList.Num())
		Water->SetSprite(CurrentWorldMap.SpriteList[WorldFloorType.Layer2].Sprite);
		
	return true;
}

void  ASWorldFloor::Clicked(AActor* TouchedActor, FKey ButtonPressed) {

	PRINT_STRING(FString::Printf(TEXT(" UnitClicked %d %d"), xReal, yReal))
}

void ASWorldFloor::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT(" UnitClicked %d %d"), xReal, yReal));
}


void ASWorldFloor::destroyWorldFloor(int32 xCoord, int32 yCoord) {

    int32 xRealL = USWorldCoord::getRealCoordX(xCoord);
    int32 yRealL = USWorldCoord::getRealCoordY(yCoord);
	FUnitsInTheWorld& UnitInW = ASWorldFloor::UnitsInTheWorld[xRealL][yRealL];

	if (!UnitInW.bInWorld)
		return;
	if (!UnitInW.UnitFloor)
		return;
	if(!UnitInW.UnitFloor->IsPendingKillPending())
		UnitInW.UnitFloor->Destroy();

	//ASWorldFloor::UnitsInTheWorld[xRealL][yRealL].UnitFloor = nullptr;

}

void ASWorldFloor::Destroy() {
	Super::Destroy();
	FUnitsInTheWorld& UnitInW = ASWorldFloor::UnitsInTheWorld[xReal][yReal];
	UnitInW.bInWorld = false;
	GLog->Log(" Destroyed 123");
}