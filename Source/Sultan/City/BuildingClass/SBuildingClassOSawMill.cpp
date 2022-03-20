// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassOSawMill.h"


FString ASBuildingClassOSawMill::IL_BuildingTitle = "buildDes_name_202";

ASBuildingClassOSawMill::ASBuildingClassOSawMill() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassOSawMill::OnClicked);

	BtnCompCollect = BtnListComp.Add(EBuildingBtnAction::BBA_COLLECT_Wod, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompCollect")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));
	BtnCompGoldAcce = BtnListComp.Add(EBuildingBtnAction::BBA_BOOST, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompGoldAcce")));
	BtnCompItemAcce = BtnListComp.Add(EBuildingBtnAction::BBA_RES_Acc_Wod, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompItemAcce")));

	BtnCompCollect->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompDetail->SetupAttachment(RootComponent);
	BtnCompGoldAcce->SetupAttachment(RootComponent);
	BtnCompItemAcce->SetupAttachment(RootComponent);
}

void ASBuildingClassOSawMill::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT(""));
	Sprite->SetSprite(BuildingSprite);

}

void ASBuildingClassOSawMill::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassOSawMill::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompItemAcce->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOSawMill::OnBtnClickedItemAcce);

	T = Cast<USWid_BuildingACBtn>(BtnCompGoldAcce->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOSawMill::OnBtnClickedGoldAcce);

	T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOSawMill::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOSawMill::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompCollect->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOSawMill::OnBtnClickedCollect);

}

void ASBuildingClassOSawMill::OnBtnClickedItemAcce() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOSawMill::OnBtnClickedGoldAcce() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOSawMill::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOSawMill::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOSawMill::OnBtnClickedCollect() {
	GLog->Log(__FUNCTION__);
}



void ASBuildingClassOSawMill::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassOSawMill::setBuildingActionBtnList() {

}

void ASBuildingClassOSawMill::initBuilding() {}