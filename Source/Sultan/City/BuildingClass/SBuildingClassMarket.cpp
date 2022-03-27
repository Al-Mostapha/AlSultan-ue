// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassMarket.h"

FString ASBuildingClassMarket::IL_BuildingTitle = "buildDes_name_112";
TMap<int32, FBuildingLvlDataMarket> ASBuildingClassMarket::LvlData;

ASBuildingClassMarket::ASBuildingClassMarket() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassMarket::OnClicked);

	
	BtnCompAuction = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompAuction")));
	BtnCompTrade   = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompTrade")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompUpgrade")));
	BtnCompDetail  = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDetail")));

	BtnCompDetail ->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompTrade  ->SetupAttachment(RootComponent);
	BtnCompAuction->SetupAttachment(RootComponent);

}




void ASBuildingClassMarket::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/shichang.shichang'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassMarket::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}



void ASBuildingClassMarket::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassMarket::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassMarket::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompTrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassMarket::OnBtnClickedTrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompAuction->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassMarket::OnBtnClickedAuction);

}


void ASBuildingClassMarket::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}
void ASBuildingClassMarket::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}
void ASBuildingClassMarket::OnBtnClickedTrade() {
	GLog->Log(__FUNCTION__);
}
void ASBuildingClassMarket::OnBtnClickedAuction() {
	GLog->Log(__FUNCTION__);
}



void ASBuildingClassMarket::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassMarket::setBuildingActionBtnList() {

}


void ASBuildingClassMarket::initBuilding() {}

void ASBuildingClassMarket::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataMarket BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}

}