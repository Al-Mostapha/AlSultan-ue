// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassOHospital.h"


FString ASBuildingClassOHospital::IL_BuildingTitle = "buildDes_name_206";

ASBuildingClassOHospital::ASBuildingClassOHospital() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassOHospital::OnClicked);

	BtnCompHeal    = BtnListComp.Add(EBuildingBtnAction::BBA_HEAL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompHeal")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompDetail  = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));

	BtnCompHeal->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompDetail->SetupAttachment(RootComponent);
}

void ASBuildingClassOHospital::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT(""));
	Sprite->SetSprite(BuildingSprite);

}

void ASBuildingClassOHospital::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassOHospital::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompHeal->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOHospital::OnBtnClickedHeal);

	T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOHospital::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOHospital::OnBtnClickedUpgrade);


}



void ASBuildingClassOHospital::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOHospital::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOHospital::OnBtnClickedHeal() {
	GLog->Log(__FUNCTION__);
}



void ASBuildingClassOHospital::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassOHospital::setBuildingActionBtnList() {

}

void ASBuildingClassOHospital::initBuilding() {}