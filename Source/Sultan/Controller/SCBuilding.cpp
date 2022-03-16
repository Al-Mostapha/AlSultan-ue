// Fill out your copyright notice in the Description page of Project Settings.


#include "SCBuilding.h"

TArray<FBuildingPos> USCBuilding::BuildingPos;
TMap<ECBuildingType, FBuildingData> USCBuilding::BuildingData;

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
		BuildingPos.Add(*OneBuilding);
	
}


void USCBuilding::initBuildingData() {

	UDataTable* BuildingDataDT = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DT_BuildingData.DT_BuildingData'"));


	if (!BuildingDataDT) {
		GLog->Log("Error BuildingData Not found");
		return;
	}

	TArray<FBuildingData*> CityBuildingDataArr;
	BuildingDataDT->GetAllRows<FBuildingData>(FString(TEXT("City Parts")), CityBuildingDataArr);
	for (FBuildingData* OneBuilding : CityBuildingDataArr)
		BuildingData.Add(OneBuilding->buildingType, *OneBuilding);
	
}