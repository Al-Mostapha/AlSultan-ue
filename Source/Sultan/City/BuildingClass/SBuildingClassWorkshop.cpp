// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassWorkshop.h"

FString ASBuildingClassWorkshop::IL_BuildingTitle = "buildDes_name_119";
TMap<int32, FBuildingLvlDataWorkshop> ASBuildingClassWorkshop::LvlData;

ASBuildingClassWorkshop::ASBuildingClassWorkshop() {
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassWorkshop::OnClicked);

	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDetail")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompUpgrade")));
	BtnCompTrain = BtnListComp.Add(EBuildingBtnAction::BBA_TRAIN, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompTrain")));

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
	setOperatingProgressBar();
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

void ASBuildingClassWorkshop::setOperatingProgressBar() {


	static TSubclassOf<USWid_BuildingProgBar> ProgBar = LoadObject<UClass>(nullptr, *ProgBarClassPath);

	ProgressBarWid->SetWidgetClass(ProgBar);
	ProgressBarWid->SetDrawSize(FVector2D(260.0, 80.0));
	USWid_BuildingProgBar* Widget = Cast<USWid_BuildingProgBar>(ProgressBarWid->GetWidget());
	if (!Widget)
		return;
	static UTexture2D* IconSprite = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Icon/BuildingProgress/icon_main_build_07.icon_main_build_07'"));
	if (IconSprite)
	{
		FSlateBrush Brush;
		Brush.SetResourceObject(IconSprite);
		Brush.ImageSize = FVector2D(IconSprite->GetSizeX(), IconSprite->GetSizeY());
		Widget->OperationIcon->SetBrush(Brush);
	}
	else {

		GLog->Log("((((((((((((((((((((()))))))))))))))))))))))))");
	}
}


void ASBuildingClassWorkshop::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataWorkshop BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}

}
