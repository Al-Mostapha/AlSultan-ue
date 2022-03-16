// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassVeteransHall.h"


FString ASBuildingClassVeteransHall::IL_BuildingTitle = "common_text_3129";

ASBuildingClassVeteransHall::ASBuildingClassVeteransHall() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassVeteransHall::OnClicked);
}




void ASBuildingClassVeteransHall::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/jingyingdiantang.jingyingdiantang'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassVeteransHall::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassVeteransHall::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}

void ASBuildingClassVeteransHall::setBuildingActionBtnList() {

}
void ASBuildingClassVeteransHall::initBuilding() {

}
