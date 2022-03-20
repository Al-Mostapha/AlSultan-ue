// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassWorkshop.h"

FString ASBuildingClassWorkshop::IL_BuildingTitle = "buildDes_name_119";

ASBuildingClassWorkshop::ASBuildingClassWorkshop() {
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassWorkshop::OnClicked);

	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompTrain = BtnListComp.Add(EBuildingBtnAction::BBA_TRAIN, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompTrain")));

	BtnCompDetail->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompTrain->SetupAttachment(RootComponent);
}




void ASBuildingClassWorkshop::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/chebingying.chebingying'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassWorkshop::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassWorkshop::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWorkshop::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWorkshop::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompTrain->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWorkshop::OnBtnClickedTrain);

}


void ASBuildingClassWorkshop::OnBtnClickedDetail() {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassWorkshop::OnBtnClickedUpgrade() {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassWorkshop::OnBtnClickedTrain() {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassWorkshop::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassWorkshop::setBuildingActionBtnList() {

}

void ASBuildingClassWorkshop::initBuilding() {

}
