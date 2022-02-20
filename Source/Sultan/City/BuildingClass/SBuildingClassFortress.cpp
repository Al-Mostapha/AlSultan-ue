// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassFortress.h"


FString ASBuildingClassFortress::IL_BuildingTitle = "buildDes_name_120";

ASBuildingClassFortress::ASBuildingClassFortress() {


	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassFortress::OnClicked);
}




void ASBuildingClassFortress::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/zhanzhengbaolei.zhanzhengbaolei'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassFortress::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassFortress::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassFortress::setBuildingActionBtnList() {

}