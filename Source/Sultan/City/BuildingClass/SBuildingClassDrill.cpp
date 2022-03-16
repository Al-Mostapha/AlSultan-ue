// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassDrill.h"

FString ASBuildingClassDrill::IL_BuildingTitle = "buildDes_name_121";

ASBuildingClassDrill::ASBuildingClassDrill() {


	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassDrill::OnClicked);
	
}




void ASBuildingClassDrill::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/jiaochang.jiaochang'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassDrill::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassDrill::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}

void ASBuildingClassDrill::setBuildingActionBtnList() {

}
void ASBuildingClassDrill::initBuilding() {

}