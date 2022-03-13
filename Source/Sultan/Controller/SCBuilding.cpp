// Fill out your copyright notice in the Description page of Project Settings.


#include "SCBuilding.h"

TArray<FBuildingPos> USCBuilding::BuildingPos;

void USCBuilding::initBuildingPos() {

	UDataTable* BuildingPosDT = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DT_BuildingPos.DT_BuildingPos'"));


	USCBuilding::BuildingPos.Empty();

	if (!BuildingPosDT) {
		GLog->Log("Error BuildingPos Not found");
		return;
	}

	TArray<FBuildingPos*> CityBuildingPosArr;
	BuildingPosDT->GetAllRows<FBuildingPos>(FString(TEXT("City Parts")), CityBuildingPosArr);
	for (FBuildingPos* OneBuilding : CityBuildingPosArr) 
		USCBuilding::BuildingPos.Add(*OneBuilding);
	
}