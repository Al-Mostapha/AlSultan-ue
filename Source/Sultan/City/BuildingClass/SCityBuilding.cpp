// Fill out your copyright notice in the Description page of Project Settings.


#include "SCityBuilding.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Components/InputComponent.h"

UDataTable* ASCityBuilding::CityBuildingPos = NULL;

ASCityBuilding::ASCityBuilding() {

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	Sprite->SetTranslucentSortPriority(0);
	RootComponent = Sprite;
	BuildingLvl = CreateDefaultSubobject<USBuildingLvlComp>(TEXT("BuildingLvl"));
	BuildingLvl->SetupAttachment(RootComponent);
	BuildingName = CreateDefaultSubobject<USBuildingNameComp>(TEXT("BuildingName"));
	BuildingName->SetupAttachment(RootComponent);
	BuildingNotif = CreateDefaultSubobject<USBuildingNotifComp>(TEXT("BuildingNotif"));
	BuildingNotif->SetupAttachment(RootComponent);
	BuildingTitle = CreateDefaultSubobject<USBuildingTitleComp>(TEXT("BuildingTitle"));
	BuildingTitle->SetupAttachment(RootComponent);
	ActionBtnWid = CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BuildingActionWid"));
	ActionBtnWid->SetupAttachment(RootComponent);
	BtnActionPanelBg = CreateDefaultSubobject<UWidgetComponent>(TEXT("BtnActionPanelBg"));
	BtnActionPanelBg->SetRelativeLocation(FVector(0, -1000, -166));
	BtnActionPanelBg->SetRelativeRotation(FRotator(0, 90, 0));
	BtnActionPanelBg->SetupAttachment(RootComponent);
}

void ASCityBuilding::BeginPlay()
{
	Super::BeginPlay();
	static TSubclassOf<USBuildingActionBtnsWid> ActionWid = LoadObject<UClass>(nullptr, TEXT("/Game/City/CityOld/BuildingWidgets/BuildingActionBtns/BP_BAB_Castle.BP_BAB_Castle_C"));
	BtnActionPanelBg->SetWidgetClass(ActionWid);
}

void ASCityBuilding::setSprite(class UPaperSprite* PSprite) {

	//Sprite->SetSprite(PSprite);

	//OnReleased.AddDynamic(this, &ASCityBuilding::OnSelected);
	//OnInputTouchEnd.AddDynamic(this, &ASCityBuilding::OnSelected);
	//OnClicked.AddDynamic(this, &ASCityBuilding::OnSelected);

}

void ASCityBuilding::OnSelected(UPrimitiveComponent* Target, FKey ButtonPressed) {
	GLog->Log("fdsafsdfdsfdsf");
}

void ASCityBuilding::setBuildingActionBtnList() {

}

void ASCityBuilding::initBuilding() {

}


void ASCityBuilding::addActionBtnComp() {

	static TArray<float> AngleRengeStart = { 90, 75, 60, 45, 30, 15, 0, -15, -30 };
	static float Reduis = 220.0f;
	float startingAngle = 0, x, y;
	float btnCount = float(BtnListComp.Num());
	int32 index = 0;

	if (AngleRengeStart.IsValidIndex(btnCount - 1)) {
		startingAngle = AngleRengeStart[btnCount - 1];
		GLog->Log(FString::Printf(TEXT(" Angle Start Angle %f And Btn count = %f"), startingAngle, btnCount));
	}

	for (auto& Btn : BtnListComp) {

		
		FBuildingActionBtn* ActBtn = FBuildingActionBtn::BuildingActionBtns.Find(Btn.Key);
		if (!Btn.Value)
			continue;
		if (!ActBtn)
			continue;

		Btn.Value->SetWidgetClass(ActBtn->WP_Button);

		x = FMath::Sin(FMath::DegreesToRadians(startingAngle + 90 + index * 30)) * Reduis;
		y = FMath::Cos(FMath::DegreesToRadians(startingAngle + 90 + index * 30)) * Reduis;
		USWid_BuildingACBtn* ActBtnWid = Cast<USWid_BuildingACBtn>(Btn.Value->GetUserWidgetObject());
		Btn.Value->SetRelativeLocation(FVector(x, 10, y));

		if (!ActBtnWid)
			continue;
		ActBtnWid->ActionBtn->SetStyle(USWid_BuildingACBtn::BtnStyle);
		ActBtnWid->BtnTitle->SetText(FText::FromString(USBase::Trans(ActBtn->IL_Btn)));
		Btn.Value->SetDrawSize(FVector2D(100, 120));
		index++;
	}

}