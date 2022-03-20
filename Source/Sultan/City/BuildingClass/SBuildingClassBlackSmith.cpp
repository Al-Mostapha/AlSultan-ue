// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassBlackSmith.h"


FString ASBuildingClassBlackSmith::IL_BuildingTitle = "buildDes_name_115";

ASBuildingClassBlackSmith::ASBuildingClassBlackSmith() {
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassBlackSmith::OnClicked);

	BtnCompArtifacts = BtnListComp.Add(EBuildingBtnAction::BBA_ARTIFACT, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompArtifacts")));
	BtnCompStorage = BtnListComp.Add(EBuildingBtnAction::BBA_STORAGEBOX, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompStorage")));
	BtnCompFroge = BtnListComp.Add(EBuildingBtnAction::BBA_FORGING, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompFroge")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));

	BtnCompStorage->SetupAttachment(RootComponent);
	BtnCompArtifacts->SetupAttachment(RootComponent);
	BtnCompFroge->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompDetail->SetupAttachment(RootComponent);

}




void ASBuildingClassBlackSmith::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/tiejiangpu.tiejiangpu'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassBlackSmith::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}



void ASBuildingClassBlackSmith::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBlackSmith::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBlackSmith::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompFroge->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBlackSmith::OnBtnClickedFroge);
	T = Cast<USWid_BuildingACBtn>(BtnCompStorage->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBlackSmith::OnBtnClickedStorage);

	T = Cast<USWid_BuildingACBtn>(BtnCompArtifacts->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBlackSmith::OnBtnClickedArtifacts);

}




/*
	Btn Function  Building List
*/
void ASBuildingClassBlackSmith::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassBlackSmith::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassBlackSmith::OnBtnClickedFroge() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassBlackSmith::OnBtnClickedStorage() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassBlackSmith::OnBtnClickedArtifacts() {
	GLog->Log(__FUNCTION__);
}




void ASBuildingClassBlackSmith::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}

void ASBuildingClassBlackSmith::setBuildingActionBtnList() {

}

void ASBuildingClassBlackSmith::initBuilding() {

}


