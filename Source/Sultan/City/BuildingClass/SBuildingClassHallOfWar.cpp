// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassHallOfWar.h"

FString ASBuildingClassHallOfWar::IL_BuildingTitle = "buildDes_name_122";

ASBuildingClassHallOfWar::ASBuildingClassHallOfWar() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassHallOfWar::OnClicked);

	BtnCompCounterAttack = BtnListComp.Add(EBuildingBtnAction::BBA_COUNTER_SYS, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompCounterAttack")));
	BtnCompMedalExchange = BtnListComp.Add(EBuildingBtnAction::BBA_MILITARY_POINT, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompMedalExchange")));
	BtnCompAlncWar       = BtnListComp.Add(EBuildingBtnAction::BBA_ALLIANCEBATTLE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompAlncWar")));
	BtnCompUpgrade       = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompDetail        = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));

	BtnCompDetail        ->SetupAttachment(RootComponent);
	BtnCompUpgrade       ->SetupAttachment(RootComponent);
	BtnCompAlncWar       ->SetupAttachment(RootComponent);
	BtnCompMedalExchange ->SetupAttachment(RootComponent);
	BtnCompCounterAttack ->SetupAttachment(RootComponent);
}




void ASBuildingClassHallOfWar::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/zhanzhengdating.zhanzhengdating'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassHallOfWar::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassHallOfWar::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassHallOfWar::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassHallOfWar::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompAlncWar->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassHallOfWar::OnBtnClickedAlncWar);

	T = Cast<USWid_BuildingACBtn>(BtnCompMedalExchange->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassHallOfWar::OnBtnClickedMedalExchange);

	T = Cast<USWid_BuildingACBtn>(BtnCompCounterAttack->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassHallOfWar::OnBtnClickedCounterAttack);
}



void ASBuildingClassHallOfWar::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassHallOfWar::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassHallOfWar::OnBtnClickedAlncWar() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassHallOfWar::OnBtnClickedMedalExchange() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassHallOfWar::OnBtnClickedCounterAttack() {
	GLog->Log(__FUNCTION__);
}



void ASBuildingClassHallOfWar::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}



void ASBuildingClassHallOfWar::setBuildingActionBtnList() {

}

void ASBuildingClassHallOfWar::initBuilding() {

}