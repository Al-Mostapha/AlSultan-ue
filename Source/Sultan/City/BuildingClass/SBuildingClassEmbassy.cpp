// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassEmbassy.h"


FString ASBuildingClassEmbassy::IL_BuildingTitle = "buildDes_name_111";

ASBuildingClassEmbassy::ASBuildingClassEmbassy() {

	
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassEmbassy::OnClicked);
}




void ASBuildingClassEmbassy::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/dashiguan.dashiguan'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassEmbassy::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassEmbassy::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassEmbassy::setBuildingActionBtnList() {

}

void ASBuildingClassEmbassy::initBuilding() {

}