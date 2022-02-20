// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassBlackSmith.h"


FString ASBuildingClassBlackSmith::IL_BuildingTitle = "buildDes_name_115";

ASBuildingClassBlackSmith::ASBuildingClassBlackSmith() {
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassBlackSmith::OnClicked);
}




void ASBuildingClassBlackSmith::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/tiejiangpu.tiejiangpu'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassBlackSmith::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassBlackSmith::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}

void ASBuildingClassBlackSmith::setBuildingActionBtnList() {

}