// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassWall.h"



FString ASBuildingClassWall::IL_BuildingTitle = "buildDes_name_102";
TMap<int32, FBuildingLvlDataWall> ASBuildingClassWall::LvlData;

ASBuildingClassWall::ASBuildingClassWall() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassWall::OnClicked);


	Wall1       = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Wall1"));
	Wall2       = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Wall2"));
	Wall3       = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Wall3"));
	Wall4       = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Wall4"));
	ArrowTower1 = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ArrowTower1"));
	ArrowTower2 = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ArrowTower2"));
	WallGate    = Sprite;

	BtnCompDetail  = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDetail")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompUpgrade")));
	BtnCompDefence = BtnListComp.Add(EBuildingBtnAction::BBA_DEFEND, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDefence")));

	BtnCompDetail ->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompDefence->SetupAttachment(RootComponent);
	Wall1->SetupAttachment(RootComponent);
	Wall2->SetupAttachment(RootComponent);
	Wall3->SetupAttachment(RootComponent);
	Wall4->SetupAttachment(RootComponent);
	ArrowTower1->SetupAttachment(RootComponent);
	ArrowTower2->SetupAttachment(RootComponent);

	

}




void ASBuildingClassWall::setSprite() {

	UPaperSprite* WallSprite       = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityNew/CityWall/chengqiang_lv4.chengqiang_lv4'"));
	UPaperSprite* ArrowTowerSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityNew/CityWall/jianta_lv4_base.jianta_lv4_base'"));
	UPaperSprite* WallGateSprite   = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityNew/CityWall/chengmen_lv4.chengmen_lv4'"));

	WallGate->SetSprite(WallGateSprite);
	Wall1->SetSprite(WallSprite);
	Wall2->SetSprite(WallSprite);
	Wall3->SetSprite(WallSprite);
	Wall4->SetSprite(WallSprite);
	ArrowTower1->SetSprite(ArrowTowerSprite);
	ArrowTower2->SetSprite(ArrowTowerSprite);

	Wall1->SetRelativeLocation(FVector(464.0, -3, 185.0));
	ArrowTower1->SetRelativeLocation(FVector(325.0, -2, 174.0));
	Wall2->SetRelativeLocation(FVector(135.0, -1, 24.0));
	Wall3->SetRelativeLocation(FVector(-284.0, 1, -181.0));
	ArrowTower2->SetRelativeLocation(FVector(-449.0, 2, -210.0));
	Wall4->SetRelativeLocation(FVector(-638.0, 3, -357.0));

}


void ASBuildingClassWall::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassWall::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWall::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWall::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompDefence->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassWall::OnBtnClickedDefence);

}


void ASBuildingClassWall::OnBtnClickedDetail() {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassWall::OnBtnClickedUpgrade() {

	GLog->Log(__FUNCTION__);

}


void ASBuildingClassWall::OnBtnClickedDefence() {

	GLog->Log(__FUNCTION__);

}

void ASBuildingClassWall::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassWall::setBuildingActionBtnList() {

}

void ASBuildingClassWall::initBuilding() {}

void ASBuildingClassWall::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataWall BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}

}