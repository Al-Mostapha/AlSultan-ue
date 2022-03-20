// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassOMiliTent.h"

FString ASBuildingClassOMiliTent::IL_BuildingTitle = "buildDes_name_201";

ASBuildingClassOMiliTent::ASBuildingClassOMiliTent() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassOMiliTent::OnClicked);

	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompDetail  = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));

	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompDetail->SetupAttachment(RootComponent);
}

void ASBuildingClassOMiliTent::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT(""));
	Sprite->SetSprite(BuildingSprite);

}

void ASBuildingClassOMiliTent::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassOMiliTent::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOMiliTent::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOMiliTent::OnBtnClickedUpgrade);

}

void ASBuildingClassOMiliTent::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOMiliTent::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}




void ASBuildingClassOMiliTent::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassOMiliTent::setBuildingActionBtnList() {

}

void ASBuildingClassOMiliTent::initBuilding() {}
