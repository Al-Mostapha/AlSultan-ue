// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassHallOfWar.h"

FString ASBuildingClassHallOfWar::IL_BuildingTitle = "buildDes_name_122";

ASBuildingClassHallOfWar::ASBuildingClassHallOfWar() {

	
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassHallOfWar::OnClicked);
}




void ASBuildingClassHallOfWar::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/zhanzhengdating.zhanzhengdating'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassHallOfWar::BeginPlay() {

	Super::BeginPlay();
	setSprite();
}

void ASBuildingClassHallOfWar::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}



void ASBuildingClassHallOfWar::setBuildingActionBtnList() {

}