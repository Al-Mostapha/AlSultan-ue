// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassTreasurePool.h"

FString ASBuildingClassTreasurePool::IL_BuildingTitle = "buildDes_name_111";

ASBuildingClassTreasurePool::ASBuildingClassTreasurePool() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassTreasurePool::OnClicked);

	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompTreaHunt = BtnListComp.Add(EBuildingBtnAction::BBA_WISH, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompTreaHunt")));
	BtnCompEndTrea = BtnListComp.Add(EBuildingBtnAction::BBA_ENDLESSTREASURE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompEndTrea")));

	BtnCompDetail->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompTreaHunt->SetupAttachment(RootComponent);
	BtnCompEndTrea->SetupAttachment(RootComponent);

}




void ASBuildingClassTreasurePool::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/baozangzhichi.baozangzhichi'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassTreasurePool::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassTreasurePool::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T) T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassTreasurePool::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T) T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassTreasurePool::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompTreaHunt->GetUserWidgetObject());
	if (T) T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassTreasurePool::OnBtnClickedTreaHunt);

	T = Cast<USWid_BuildingACBtn>(BtnCompEndTrea->GetUserWidgetObject());
	if (T) T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassTreasurePool::OnBtnClickedEndTrea);

}


void ASBuildingClassTreasurePool::OnBtnClickedDetail() {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassTreasurePool::OnBtnClickedUpgrade() {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassTreasurePool::OnBtnClickedTreaHunt() {

	GLog->Log(__FUNCTION__);

}

void ASBuildingClassTreasurePool::OnBtnClickedEndTrea() {

	GLog->Log(__FUNCTION__);

}

void ASBuildingClassTreasurePool::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassTreasurePool::setBuildingActionBtnList() {

}

void ASBuildingClassTreasurePool::initBuilding() {

}
