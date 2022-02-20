// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassTreasurePool.h"

FString ASBuildingClassTreasurePool::IL_BuildingTitle = "buildDes_name_111";

ASBuildingClassTreasurePool::ASBuildingClassTreasurePool() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassTreasurePool::OnClicked);
}




void ASBuildingClassTreasurePool::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/baozangzhichi.baozangzhichi'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassTreasurePool::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassTreasurePool::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassTreasurePool::setBuildingActionBtnList() {

}
