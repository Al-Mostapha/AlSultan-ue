// Fill out your copyright notice in the Description page of Project Settings.



#include "SCityGM.h"
#include "Engine/World.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "SCityFloor.h"
#include "SCityPlayerCont.h"
#include "../SGameMain.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "SCityBuilding.h"

#include "../World/SWorldFloor.h"

class UCameraComponent;
void ASCityGM::initCamera() {

	
}


ASCityGM::ASCityGM() {
	PlayerControllerClass = ASCityPlayerCont::StaticClass();
	
}

void ASCityGM::StartPlay() {

	Super::StartPlay();


	buildCompleteBuilding();

	return;


	buildCityFloor();
	buildCityBuilding();
	buildCityFixedBuilding();
	buildCityFixedDecore();
	buildCityResBuilding();
	buildCityOuterBuilding();


}



void ASCityGM::buildCityFloor() {


	ASCityFloor::CityFloorParts = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityFloorPartsLvl1DT.CityFloorPartsLvl1DT'"));



	if (!ASCityFloor::CityFloorParts) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityFloorPart*> CityPartArr;
	ASCityFloor::CityFloorParts->GetAllRows<FCityFloorPart>(FString(TEXT("City Parts")), CityPartArr);
	ASCityFloor* OneCityFloor;

	for (FCityFloorPart* OnePart : CityPartArr) {
		FVector Vect(OnePart->x, OnePart->y, OnePart->z);
		FRotator Rot(OnePart->yaw, OnePart->roll, 0);
		OneCityFloor = GetWorld()->SpawnActor<ASCityFloor>(ASCityFloor::StaticClass(), Vect, Rot);
		OneCityFloor->setSprite(OnePart->Sprite);
	}



}


void ASCityGM::buildCityBuilding() {

	ASCityBuilding::CityBuildingPos = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DTCityBuildingPos.DTCityBuildingPos'"));



	if (!ASCityBuilding::CityBuildingPos) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityBuildingPos*> CityBuildingPosArr;
	ASCityBuilding::CityBuildingPos->GetAllRows<FCityBuildingPos>(FString(TEXT("City Parts")), CityBuildingPosArr);
	ASCityBuilding* OneCityBuilding;

	for (FCityBuildingPos* OneCityBuildingPos : CityBuildingPosArr) {

		OneCityBuilding = GetWorld()->SpawnActor<ASCityBuilding>(ASCityBuilding::StaticClass(), OneCityBuildingPos->Vect, OneCityBuildingPos->Rot);
		UPaperSprite* Temp = LoadObject<class UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/bubingying_war.bubingying_war'"));

		OneCityBuilding->setSprite(Temp);

		//OneCityBuildingPos->setSprite(OneCityBuildingPos->Sprite);
	}


}


void ASCityGM::buildCityFixedBuilding() {
	
	UDataTable* FixedBuilding = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DTCityFixedBuildingPos.DTCityFixedBuildingPos'"));

	if (!FixedBuilding) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityFixedBuildingPosAndSp*> CityFixedBuildingArr;
	FixedBuilding->GetAllRows<FCityFixedBuildingPosAndSp>(FString(TEXT("City Parts")), CityFixedBuildingArr);
	ASCityBuilding* OneCityBuilding;

	for (FCityFixedBuildingPosAndSp* OneCityBuildingPos : CityFixedBuildingArr) {

		OneCityBuilding = GetWorld()->SpawnActor<ASCityBuilding>(ASCityBuilding::StaticClass(), OneCityBuildingPos->Vect, OneCityBuildingPos->Rot);
		OneCityBuilding->setSprite(OneCityBuildingPos->Sprite);

		//OneCityBuildingPos->setSprite(OneCityBuildingPos->Sprite);
	}
	

}

void ASCityGM::buildCityFixedDecore() {


	UDataTable* FixedBuildingDecore = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DTCityDecore.DTCityDecore'"));


	if (!FixedBuildingDecore) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityFixedBuildingPosAndSp*> CityFixedBuildingArr;
	FixedBuildingDecore->GetAllRows<FCityFixedBuildingPosAndSp>(FString(TEXT("City Parts")), CityFixedBuildingArr);
	ASCityFloor* OneCityBuilding;

	for (FCityFixedBuildingPosAndSp* OneCityBuildingPos : CityFixedBuildingArr) {

		OneCityBuilding = GetWorld()->SpawnActor<ASCityFloor>(ASCityFloor::StaticClass(), OneCityBuildingPos->Vect, OneCityBuildingPos->Rot);
		OneCityBuilding->setSprite(OneCityBuildingPos->Sprite);
	}


}

void ASCityGM::buildCityResBuilding() {

	ASCityBuilding::CityBuildingPos = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DTCityBuildingResOutPos.DTCityBuildingResOutPos'"));



	if (!ASCityBuilding::CityBuildingPos) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityBuildingPos*> CityBuildingPosArr;
	ASCityBuilding::CityBuildingPos->GetAllRows<FCityBuildingPos>(FString(TEXT("City Parts")), CityBuildingPosArr);
	ASCityBuilding* OneCityBuilding;

	for (FCityBuildingPos* OneCityBuildingPos : CityBuildingPosArr) {

		OneCityBuilding = GetWorld()->SpawnActor<ASCityBuilding>(ASCityBuilding::StaticClass(), OneCityBuildingPos->Vect, OneCityBuildingPos->Rot);
		UPaperSprite* Temp = LoadObject<class UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingAcc/res_tile.res_tile'"));
		OneCityBuilding->setSprite(Temp);
	}
}


void ASCityGM::buildCityOuterBuilding() {

	ASCityBuilding::CityBuildingPos = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DTCItyBuildingOutPos.DTCItyBuildingOutPos'"));

	if (!ASCityBuilding::CityBuildingPos) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityBuildingPos*> CityBuildingPosArr;
	ASCityBuilding::CityBuildingPos->GetAllRows<FCityBuildingPos>(FString(TEXT("City Parts")), CityBuildingPosArr);
	ASCityBuilding* OneCityBuilding;

	for (FCityBuildingPos* OneCityBuildingPos : CityBuildingPosArr) {

		OneCityBuilding = GetWorld()->SpawnActor<ASCityBuilding>(ASCityBuilding::StaticClass(), OneCityBuildingPos->Vect, OneCityBuildingPos->Rot);
		UPaperSprite* Temp = LoadObject<class UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingAcc/inner_city_building_tile.inner_city_building_tile'"));
		OneCityBuilding->setSprite(Temp);
	}
}


void ASCityGM::buildCompleteBuilding() {

	UDataTable* TestTable = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/NewDataTable.NewDataTable'"));

	if (!TestTable) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityBuildingData*> CityBuildingPosArr;
	TestTable->GetAllRows<FCityBuildingData>(FString(TEXT("City Parts")), CityBuildingPosArr);

	for (FCityBuildingData* OneCityBuildingPos : CityBuildingPosArr) {

		ASCityBuilding* Test = GetWorld()->SpawnActor<ASCityBuilding>(OneCityBuildingPos->BuildingClass, FVector::ZeroVector, FRotator::ZeroRotator);
		Test->setSprite(OneCityBuildingPos->FloorSprite);
		Test->WidgitComp->SetWidgetClass(OneCityBuildingPos->BuildingProg);
		//Test->WidgitComp
	}
}


void ASCityGM::BeginPlay() {

	Super::BeginPlay();

	PRINT_STRING(FString::Printf(TEXT("Trattttttt")))

}




