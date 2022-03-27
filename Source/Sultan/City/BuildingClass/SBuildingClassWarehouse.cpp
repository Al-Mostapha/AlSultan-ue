// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassWarehouse.h"

FString ASBuildingClassWarehouse::IL_BuildingTitle = "buildDes_name_105";
TMap<int32, FBuildingLvlDataWarehouse> ASBuildingClassWarehouse::LvlData;

ASBuildingClassWarehouse::ASBuildingClassWarehouse() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassWarehouse::OnClicked);

	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDetail")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompUpgrade")));
	BtnCompAlnTreasure = BtnListComp.Add(EBuildingBtnAction::BBA_TRAIN, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompAlnTreasure")));

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

void ASBuildingClassWarehouse::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataWarehouse BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}

}