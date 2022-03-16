// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassWatchTower.h"

FString ASBuildingClassWatchTower::IL_BuildingTitle = "buildDes_name_111";

ASBuildingClassWatchTower::ASBuildingClassWatchTower() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassWatchTower::OnClicked);
}




void ASBuildingClassWatchTower::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/liaowangta.liaowangta'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassWatchTower::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassWatchTower::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassWatchTower::setBuildingActionBtnList() {

}

void ASBuildingClassWatchTower::initBuilding() {

}
