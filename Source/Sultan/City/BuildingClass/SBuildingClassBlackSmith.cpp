// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassBlackSmith.h"


FString ASBuildingClassBlackSmith::IL_BuildingTitle = "buildDes_name_115";
TMap<int32, FBuildingLvlDataBlackSmith> ASBuildingClassBlackSmith::LvlData;

ASBuildingClassBlackSmith::ASBuildingClassBlackSmith() {
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassBlackSmith::OnClicked);

	BtnCompArtifacts = BtnListComp.Add(EBuildingBtnAction::BBA_ARTIFACT, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompArtifacts")));
	BtnCompStorage = BtnListComp.Add(EBuildingBtnAction::BBA_STORAGEBOX, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompStorage")));
	BtnCompFroge = BtnListComp.Add(EBuildingBtnAction::BBA_FORGING, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompFroge")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompUpgrade")));
	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDetail")));

	BtnCompStorage->SetupAttachment(RootComponent);
	BtnCompArtifacts->SetupAttachment(RootComponent);
	BtnCompFroge->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompDetail->SetupAttachment(RootComponent);

}




void ASBuildingClassBlackSmith::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/tiejiangpu.tiejiangpu'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassBlackSmith::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
	setOperatingProgressBar();

}



void ASBuildingClassBlackSmith::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBlackSmith::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBlackSmith::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompFroge->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBlackSmith::OnBtnClickedFroge);
	T = Cast<USWid_BuildingACBtn>(BtnCompStorage->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBlackSmith::OnBtnClickedStorage);

	T = Cast<USWid_BuildingACBtn>(BtnCompArtifacts->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBlackSmith::OnBtnClickedArtifacts);

}




/*
	Btn Function  Building List
*/
void ASBuildingClassBlackSmith::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassBlackSmith::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassBlackSmith::OnBtnClickedFroge() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassBlackSmith::OnBtnClickedStorage() {
	GLog->Log(__FUNCTION__);
}

void ASBuildingClassBlackSmith::OnBtnClickedArtifacts() {
	GLog->Log(__FUNCTION__);
}




void ASBuildingClassBlackSmith::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}

void ASBuildingClassBlackSmith::setBuildingActionBtnList() {

}

void ASBuildingClassBlackSmith::initBuilding() {

}

void ASBuildingClassBlackSmith::setOperatingProgressBar() {


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

void ASBuildingClassBlackSmith::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataBlackSmith BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}

}