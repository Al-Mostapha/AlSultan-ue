// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassInstitute.h"


FString ASBuildingClassInstitute::IL_BuildingTitle = "buildDes_name_113";
TMap<int32, FBuildingLvlDataInstitute> ASBuildingClassInstitute::LvlData;

ASBuildingClassInstitute::ASBuildingClassInstitute() {
	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassInstitute::OnClicked);

	BtnCompResearch = BtnListComp.Add(EBuildingBtnAction::BBA_HELP, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompHelp")));
	BtnCompUpgrade  = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompUpgrade")));
	BtnCompDetail   = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnCompDetail")));

	BtnCompResearch->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompDetail->SetupAttachment(RootComponent);
}




void ASBuildingClassInstitute::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/xueyuan.xueyuan'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassInstitute::BeginPlay() {

	Super::BeginPlay();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
	setOperatingProgressBar();
}


void ASBuildingClassInstitute::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassInstitute::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassInstitute::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompResearch->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassInstitute::OnBtnClickedResearch);



}

void ASBuildingClassInstitute::OnBtnClickedDetail() {
	GLog->Log(__FUNCTION__);
}
void ASBuildingClassInstitute::OnBtnClickedUpgrade() {
	GLog->Log(__FUNCTION__);
}
void ASBuildingClassInstitute::OnBtnClickedResearch() {
	GLog->Log(__FUNCTION__);
}


void ASBuildingClassInstitute::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}

void ASBuildingClassInstitute::setBuildingActionBtnList() {

}

void ASBuildingClassInstitute::initBuilding() {

}


void ASBuildingClassInstitute::setOperatingProgressBar() {


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


void ASBuildingClassInstitute::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataInstitute BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}
}