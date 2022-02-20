// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassInstitute.h"


FString ASBuildingClassInstitute::IL_BuildingTitle = "buildDes_name_113";

ASBuildingClassInstitute::ASBuildingClassInstitute() {
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassInstitute::OnClicked);
}




void ASBuildingClassInstitute::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/xueyuan.xueyuan'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassInstitute::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassInstitute::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}

void ASBuildingClassInstitute::setBuildingActionBtnList() {

}