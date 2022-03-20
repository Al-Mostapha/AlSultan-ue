// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassWarehouse.h"

FString ASBuildingClassWarehouse::IL_BuildingTitle = "buildDes_name_105";

ASBuildingClassWarehouse::ASBuildingClassWarehouse() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassWarehouse::OnClicked);

	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompAlnTreasure = BtnListComp.Add(EBuildingBtnAction::BBA_TRAIN, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompAlnTreasure")));

	BtnCompDetail->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompAlnTreasure->SetupAttachment(RootComponent);


}




void ASBuildingClassWarehouse::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/cangku.cangku'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassWarehouse::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassWarehouse::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWarehouse::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWarehouse::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompAlnTreasure->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWarehouse::OnBtnClickedAlnTreasure);

}


void ASBuildingClassWarehouse::OnBtnClickedDetail() {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassWarehouse::OnBtnClickedUpgrade() {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassWarehouse::OnBtnClickedAlnTreasure() {

	GLog->Log(__FUNCTION__);

}

void ASBuildingClassWarehouse::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassWarehouse::setBuildingActionBtnList() {

}


void ASBuildingClassWarehouse::initBuilding() {

}
