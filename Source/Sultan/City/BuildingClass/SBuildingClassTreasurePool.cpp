// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassTreasurePool.h"

FString ASBuildingClassTreasurePool::IL_BuildingTitle = "buildDes_name_111";
TMap<int32, FBuildingLvlDataTreasurePool> ASBuildingClassTreasurePool::LvlData;

ASBuildingClassTreasurePool::ASBuildingClassTreasurePool() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassTreasurePool::OnClicked);

	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDetail")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompUpgrade")));
	BtnCompTreaHunt = BtnListComp.Add(EBuildingBtnAction::BBA_WISH, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompTreaHunt")));
	BtnCompEndTrea = BtnListComp.Add(EBuildingBtnAction::BBA_ENDLESSTREASURE, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompEndTrea")));

	BtnCompDetail->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompTreaHunt->SetupAttachment(RootComponent);
	BtnCompEndTrea->SetupAttachment(RootComponent);

}




void ASBuildingClassTreasurePool::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/baozangzhichi.baozangzhichi'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassTreasurePool::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassTreasurePool::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T) T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassTreasurePool::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T) T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassTreasurePool::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompTreaHunt->GetUserWidgetObject());
	if (T) T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassTreasurePool::OnBtnClickedTreaHunt);

	T = Cast<USWid_BuildingACBtn>(BtnCompEndTrea->GetUserWidgetObject());
	if (T) T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassTreasurePool::OnBtnClickedEndTrea);

}


void ASBuildingClassTreasurePool::OnBtnClickedDetail() {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassTreasurePool::OnBtnClickedUpgrade() {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassTreasurePool::OnBtnClickedTreaHunt() {

	GLog->Log(__FUNCTION__);

}

void ASBuildingClassTreasurePool::OnBtnClickedEndTrea() {

	GLog->Log(__FUNCTION__);

}

void ASBuildingClassTreasurePool::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassTreasurePool::setBuildingActionBtnList() {

}

void ASBuildingClassTreasurePool::initBuilding() {

}

void ASBuildingClassTreasurePool::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataTreasurePool BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}

}
