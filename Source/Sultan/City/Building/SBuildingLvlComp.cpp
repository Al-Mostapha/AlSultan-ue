// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingLvlComp.h"


// Sets default values for this component's properties
USBuildingLvlComp::USBuildingLvlComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Bg = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	Lvl = CreateDefaultSubobject<UTextRenderComponent>(TEXT("NameText"));
	// ...
	Bg->SetupAttachment(this);
	Bg->SetRelativeLocation(FVector(96, 10, -64 - 8));
	Bg->SetTranslucentSortPriority(2);


	Lvl->SetupAttachment(this);
	Lvl->SetRelativeLocation(FVector(110, 12, -76));
	Lvl->SetTranslucentSortPriority(3);
	Lvl->SetRelativeRotation(FRotator(0, 90, 0));

	Lvl->SetText(FText::FromString(TEXT("1")));
	Lvl->SetTextRenderColor(FColor::White);
	Lvl->SetWorldSize(18.0);

	Lvl->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	Lvl->SetVerticalAlignment(EVerticalTextAligment::EVRTA_TextCenter);

}


// Called when the game starts
void USBuildingLvlComp::BeginPlay()
{
	Super::BeginPlay();
	Bg->SetSprite(LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingAcc/icon_main_build_lv.icon_main_build_lv'")));
	// ...
/**
	AActor* Parent = GetOwner();
	if (Parent) {


	}*/
}


// Called every frame
void USBuildingLvlComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
