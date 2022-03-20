// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassWatchTower.h"

FString ASBuildingClassWatchTower::IL_BuildingTitle = "buildDes_name_111";

ASBuildingClassWatchTower::ASBuildingClassWatchTower() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassWatchTower::OnClicked);

	BtnCompDetail   = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));
	BtnCompUpgrade  = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompMilitary = BtnListComp.Add(EBuildingBtnAction::BBA_MILITARYINFO, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompMilitary")));

	BtnCompDetail  ->SetupAttachment(RootComponent);
	BtnCompUpgrade ->SetupAttachment(RootComponent);
	BtnCompMilitary->SetupAttachment(RootComponent);
}




void ASBuildingClassWatchTower::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/liaowangta.liaowangta'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassWatchTower::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassWatchTower::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWatchTower::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWatchTower::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompMilitary->GetUserWidgetObject());
	if (T) 
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWatchTower::OnBtnClickedMilitary);

}


void ASBuildingClassWatchTower::OnBtnClickedDetail() {

	GLog->Log(__FUNCTION__);

}

void ASBuildingClassWatchTower::OnBtnClickedUpgrade() {

	GLog->Log(__FUNCTION__);

}

void ASBuildingClassWatchTower::OnBtnClickedMilitary() {

	GLog->Log(__FUNCTION__);

}
void ASBuildingClassWatchTower::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassWatchTower::setBuildingActionBtnList() {

}

void ASBuildingClassWatchTower::initBuilding() {

}
