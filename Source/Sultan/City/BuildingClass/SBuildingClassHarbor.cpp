// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassHarbor.h"



FString ASBuildingClassHarbor::IL_BuildingTitle = "common_text_2478";

ASBuildingClassHarbor::ASBuildingClassHarbor() {


	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassHarbor::OnClicked);



	BtnCompVipMall = BtnListComp.Add(EBuildingBtnAction::BBA_PREMIUM_VIP_MALL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompVipMall")));
	BtnCompDailyReward = BtnListComp.Add(EBuildingBtnAction::BBA_DAILYREWARD, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDailyReward")));
	BtnCompDailyCard = BtnListComp.Add(EBuildingBtnAction::BBA_DAILYSIGN, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDailyCard")));
	BtnCompMonthlyReward = BtnListComp.Add(EBuildingBtnAction::BBA_MONTH_GIFT, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompMonthlyReward")));

	BtnCompVipMall->SetupAttachment(RootComponent);
	BtnCompDailyReward->SetupAttachment(RootComponent);
	BtnCompDailyCard->SetupAttachment(RootComponent);
	BtnCompMonthlyReward->SetupAttachment(RootComponent);

}





void ASBuildingClassHarbor::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/Decore/huochuan.huochuan'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassHarbor::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassHarbor::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompVipMall->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassHarbor::OnBtnClickedVipMall);

	T = Cast<USWid_BuildingACBtn>(BtnCompDailyReward->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassHarbor::OnBtnClickedDailyReward);

	T = Cast<USWid_BuildingACBtn>(BtnCompDailyCard->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassHarbor::OnBtnClickedDailyCard);

	T = Cast<USWid_BuildingACBtn>(BtnCompMonthlyReward->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassHarbor::OnBtnClickedMonthlyReward);

}


void ASBuildingClassHarbor::OnBtnClickedVipMall() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassHarbor::OnBtnClickedDailyReward() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassHarbor::OnBtnClickedDailyCard() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassHarbor::OnBtnClickedMonthlyReward() {
	GLog->Log(__FUNCTION__);
}



void ASBuildingClassHarbor::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassHarbor::setBuildingActionBtnList() {

}



void ASBuildingClassHarbor::initBuilding() {

}

