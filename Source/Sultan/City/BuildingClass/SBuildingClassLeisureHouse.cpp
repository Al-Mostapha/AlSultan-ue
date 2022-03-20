// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassLeisureHouse.h"


FString ASBuildingClassLeisureHouse::IL_BuildingTitle = "buildDes_name_111";

ASBuildingClassLeisureHouse::ASBuildingClassLeisureHouse() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassLeisureHouse::OnClicked);

	BtnCompPyramid = BtnListComp.Add(EBuildingBtnAction::BBA_PYRAMID, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompPyramid")));
	BtnCompFriend  = BtnListComp.Add(EBuildingBtnAction::BBA_FRIEND,  CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompFriend")));

	BtnCompPyramid->SetupAttachment(RootComponent);
	BtnCompFriend->SetupAttachment(RootComponent);
}


void ASBuildingClassLeisureHouse::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/BG_SPR.BG_SPR'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassLeisureHouse::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}

void ASBuildingClassLeisureHouse::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassLeisureHouse::setBuildingActionBtnList() {

}

void ASBuildingClassLeisureHouse::initBuilding() {}

void ASBuildingClassLeisureHouse::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompPyramid->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassLeisureHouse::OnBtnClickedPyramid);

	T = Cast<USWid_BuildingACBtn>(BtnCompFriend->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassLeisureHouse::OnBtnClickedFriend);

}


void  ASBuildingClassLeisureHouse::OnBtnClickedPyramid() {
	GLog->Log(__FUNCTION__);
}
void  ASBuildingClassLeisureHouse::OnBtnClickedFriend() {
	GLog->Log(__FUNCTION__);
}