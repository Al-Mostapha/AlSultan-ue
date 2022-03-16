// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassLeisureHouse.h"


FString ASBuildingClassLeisureHouse::IL_BuildingTitle = "buildDes_name_111";

ASBuildingClassLeisureHouse::ASBuildingClassLeisureHouse() {
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassLeisureHouse::OnClicked);
}


void ASBuildingClassLeisureHouse::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/BG_SPR.BG_SPR'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassLeisureHouse::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassLeisureHouse::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassLeisureHouse::setBuildingActionBtnList() {

}

void ASBuildingClassLeisureHouse::initBuilding() {}