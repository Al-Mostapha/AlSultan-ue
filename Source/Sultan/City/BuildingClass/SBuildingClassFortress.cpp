// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassFortress.h"


FString ASBuildingClassFortress::IL_BuildingTitle = "buildDes_name_120";
TMap<int32, FBuildingLvlDataFortress> ASBuildingClassFortress::LvlData;

ASBuildingClassFortress::ASBuildingClassFortress() {


	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassFortress::OnClicked);

	
	BtnCompBuildTraps = BtnListComp.Add(EBuildingBtnAction::BBA_BUILD, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompBuildTraps")));
	BtnCompUpgrade    = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompUpgrade")));
	BtnCompDetail     = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDetail")));

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
	setOperatingProgressBar();
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


void ASBuildingClassFortress::setOperatingProgressBar() {


	static TSubclassOf<USWid_BuildingProgBar> ProgBar = LoadObject<UClass>(nullptr, *ProgBarClassPath);

	ProgressBarWid->SetWidgetClass(ProgBar);
	ProgressBarWid->SetDrawSize(FVector2D(260.0, 80.0));
	USWid_BuildingProgBar* Widget = Cast<USWid_BuildingProgBar>(ProgressBarWid->GetWidget());
	if (!Widget)
		return;
	static UTexture2D* IconSprite = LoadObject<UTexture2D>(nullptr, TEXT("Texture2D'/Game/Icon/BuildingProgress/icon_main_build_05.icon_main_build_05'"));
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


void ASBuildingClassFortress::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataFortress BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}

}