// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassInstitute.h"


FString ASBuildingClassInstitute::IL_BuildingTitle = "buildDes_name_113";

ASBuildingClassInstitute::ASBuildingClassInstitute() {
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassInstitute::OnClicked);

	BtnCompResearch = BtnListComp.Add(EBuildingBtnAction::BBA_HELP, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompHelp")));
	BtnCompUpgrade  = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompDetail   = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));

	BtnCompResearch->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompDetail->SetupAttachment(RootComponent);
}




void ASBuildingClassInstitute::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/xueyuan.xueyuan'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassInstitute::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassInstitute::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassInstitute::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassInstitute::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompResearch->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassInstitute::OnBtnClickedResearch);



}

void ASBuildingClassInstitute::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}
void ASBuildingClassInstitute::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}
void ASBuildingClassInstitute::OnBtnClickedResearch() {
	GLog->Log(__FUNCTION__);
}


void ASBuildingClassInstitute::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}

void ASBuildingClassInstitute::setBuildingActionBtnList() {

}

void ASBuildingClassInstitute::initBuilding() {

}