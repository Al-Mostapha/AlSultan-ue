// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassWarehouse.h"

FString ASBuildingClassWarehouse::IL_BuildingTitle = "buildDes_name_105";

ASBuildingClassWarehouse::ASBuildingClassWarehouse() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassWarehouse::OnClicked);
}




void ASBuildingClassWarehouse::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/cangku.cangku'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassWarehouse::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassWarehouse::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassWarehouse::setBuildingActionBtnList() {

}
