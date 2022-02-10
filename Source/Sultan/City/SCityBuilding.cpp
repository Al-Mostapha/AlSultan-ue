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
	BuildingLvl->SetTranslucentSortPriority(1);

	BuildingName = CreateDefaultSubobject<USBuildingNameComp>(TEXT("BuildingName"));
	BuildingName->SetupAttachment(RootComponent);
	BuildingName->SetTranslucentSortPriority(2);

	BuildingNotif = CreateDefaultSubobject<USBuildingNotifComp>(TEXT("BuildingNotif"));
	BuildingNotif->SetupAttachment(RootComponent);
	BuildingNotif->SetTranslucentSortPriority(3);


	BuildingProgress = CreateDefaultSubobject<USBuildingProgComp>(TEXT("BuildingProgress"));
	BuildingProgress->SetupAttachment(RootComponent);
	BuildingProgress->SetTranslucentSortPriority(4);

	

	WidgitComp = CreateDefaultSubobject<USBuildingBtnComp>(TEXT("BuildingWidget"));
	WidgitComp->SetupAttachment(RootComponent);
	WidgitComp->SetWidgetSpace(EWidgetSpace::World);
	WidgitComp->SetVisibility(true);
	WidgitComp->SetTranslucentSortPriority(5);
	WidgitComp->SetRelativeLocation(FVector(0, 5, -96));
	WidgitComp->SetRelativeRotation(FRotator(0, 90, 0));

	
}

void ASCityBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASCityBuilding::setSprite(class UPaperSprite* PSprite) {

	Sprite->SetSprite(PSprite);
	Sprite->OnClicked.AddDynamic(this, &ASCityBuilding::OnSelected);
	//OnReleased.AddDynamic(this, &ASCityBuilding::OnSelected);
	//OnInputTouchEnd.AddDynamic(this, &ASCityBuilding::OnSelected);
	//OnClicked.AddDynamic(this, &ASCityBuilding::OnSelected);

}


void ASCityBuilding::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	/**PlayerInputComponent->BindAxis("DragX", this, &ASCityBuilding::DragX);
	PlayerInputComponent->BindAxis("DragY", this, &ASCityBuilding::DragY);
	PlayerInputComponent->BindAction("Click", IE_Pressed, this, &ASCityBuilding::Click);*/
}

void ASCityBuilding::DragX(float Val) {

	//GLog->Log(FString::SanitizeFloat(Val));
	GLog->Log("fdsafsdfdsfdsf");
	AddActorLocalOffset(FVector(10, 0, 0));

}

void ASCityBuilding::DragY(float Val) {

	AddActorLocalOffset(FVector(0, 0, -10*Val));

}

void ASCityBuilding::Click() {

	
	GLog->Log("Click sadsa");
}


void ASCityBuilding::OnSelected(UPrimitiveComponent* Target, FKey ButtonPressed) {
	GLog->Log("fdsafsdfdsfdsf");
}