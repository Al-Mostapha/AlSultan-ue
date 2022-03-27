// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassOIronMine.h"

FString ASBuildingClassOIronMine::IL_BuildingTitle = "buildDes_name_203";
TMap<int32, FBuildingLvlDataIronMine> ASBuildingClassOIronMine::LvlData;

ASBuildingClassOIronMine::ASBuildingClassOIronMine() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassOIronMine::OnClicked);

	BtnCompCollect = BtnListComp.Add(EBuildingBtnAction::BBA_COLLECT_Irn, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompCollect")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompUpgrade")));
	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDetail")));
	BtnCompGoldAcce = BtnListComp.Add(EBuildingBtnAction::BBA_BOOST, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompGoldAcce")));
	BtnCompItemAcce = BtnListComp.Add(EBuildingBtnAction::BBA_RES_Acc_Irn, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompItemAcce")));

	BtnCompCollect->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompDetail->SetupAttachment(RootComponent);
	BtnCompGoldAcce->SetupAttachment(RootComponent);
	BtnCompItemAcce->SetupAttachment(RootComponent);
}

void ASBuildingClassOIronMine::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT(""));
	Sprite->SetSprite(BuildingSprite);

}

void ASBuildingClassOIronMine::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassOIronMine::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompItemAcce->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOIronMine::OnBtnClickedItemAcce);

	T = Cast<USWid_BuildingACBtn>(BtnCompGoldAcce->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOIronMine::OnBtnClickedGoldAcce);

	T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOIronMine::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOIronMine::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompCollect->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassOIronMine::OnBtnClickedCollect);

}

void ASBuildingClassOIronMine::OnBtnClickedItemAcce() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOIronMine::OnBtnClickedGoldAcce() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOIronMine::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOIronMine::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassOIronMine::OnBtnClickedCollect() {
	GLog->Log(__FUNCTION__);
}



void ASBuildingClassOIronMine::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassOIronMine::setBuildingActionBtnList() {

}

void ASBuildingClassOIronMine::initBuilding() {}

void ASBuildingClassOIronMine::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataIronMine BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}

}