// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassEmbassy.h"


FString ASBuildingClassEmbassy::IL_BuildingTitle = "buildDes_name_111";

ASBuildingClassEmbassy::ASBuildingClassEmbassy() {

	
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassEmbassy::OnClicked);

	BtnCompParliament = BtnListComp.Add(EBuildingBtnAction::BBA_INTETIOR, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompParliament")));
	BtnCompReinforce  = BtnListComp.Add(EBuildingBtnAction::BBA_REINFORCEMENTS, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompReinforce")));
	BtnCompHelp       = BtnListComp.Add(EBuildingBtnAction::BBA_HELP, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompHelp")));
	BtnCompUpgrade    = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompDetail     = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));

	BtnCompDetail    ->SetupAttachment(RootComponent);
	BtnCompUpgrade   ->SetupAttachment(RootComponent);
	BtnCompHelp      ->SetupAttachment(RootComponent);
	BtnCompReinforce ->SetupAttachment(RootComponent);
	BtnCompParliament->SetupAttachment(RootComponent);
}




void ASBuildingClassEmbassy::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/dashiguan.dashiguan'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassEmbassy::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassEmbassy::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassEmbassy::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassEmbassy::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompHelp->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassEmbassy::OnBtnClickedHelp);

	T = Cast<USWid_BuildingACBtn>(BtnCompReinforce->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassEmbassy::OnBtnClickedReinforce);

	T = Cast<USWid_BuildingACBtn>(BtnCompParliament->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassEmbassy::OnBtnClickedParliament);


}


void ASBuildingClassEmbassy::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassEmbassy::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassEmbassy::OnBtnClickedHelp() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassEmbassy::OnBtnClickedReinforce() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassEmbassy::OnBtnClickedParliament() {
	GLog->Log(__FUNCTION__);
}


void ASBuildingClassEmbassy::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassEmbassy::setBuildingActionBtnList() {

}

void ASBuildingClassEmbassy::initBuilding() {

}