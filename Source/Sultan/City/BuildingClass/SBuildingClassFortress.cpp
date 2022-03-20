// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassFortress.h"


FString ASBuildingClassFortress::IL_BuildingTitle = "buildDes_name_120";

ASBuildingClassFortress::ASBuildingClassFortress() {


	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassFortress::OnClicked);

	
	BtnCompBuildTraps = BtnListComp.Add(EBuildingBtnAction::BBA_BUILD, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompBuildTraps")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));

	BtnCompDetail->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompBuildTraps->SetupAttachment(RootComponent);

}




void ASBuildingClassFortress::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/zhanzhengbaolei.zhanzhengbaolei'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassFortress::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassFortress::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassFortress::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassFortress::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompBuildTraps->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassFortress::OnBtnClickedBuildTraps);

}


void ASBuildingClassFortress::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}
void ASBuildingClassFortress::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}
void ASBuildingClassFortress::OnBtnClickedBuildTraps() {
	GLog->Log(__FUNCTION__);
}


void ASBuildingClassFortress::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassFortress::setBuildingActionBtnList() {

}
void ASBuildingClassFortress::initBuilding() {

}