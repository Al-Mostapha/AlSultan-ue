// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassWorkshop.h"

FString ASBuildingClassWorkshop::IL_BuildingTitle = "buildDes_name_119";

ASBuildingClassWorkshop::ASBuildingClassWorkshop() {
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassWorkshop::OnClicked);
}




void ASBuildingClassWorkshop::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/chebingying.chebingying'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassWorkshop::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassWorkshop::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassWorkshop::setBuildingActionBtnList() {

}

void ASBuildingClassWorkshop::initBuilding() {

}
