// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassMarket.h"

FString ASBuildingClassMarket::IL_BuildingTitle = "buildDes_name_112";

ASBuildingClassMarket::ASBuildingClassMarket() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassMarket::OnClicked);
}




void ASBuildingClassMarket::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/shichang.shichang'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassMarket::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassMarket::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassMarket::setBuildingActionBtnList() {

}
