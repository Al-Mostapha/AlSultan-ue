// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingTitleComp.h"

// Sets default values for this component's properties
UBuildingTitleComp::UBuildingTitleComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	Bg = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	Title = CreateDefaultSubobject<UTextRenderComponent>(TEXT("NameText"));
	// ...
	SetTranslucentSortPriority(2);
	Bg->SetupAttachment(this);
	Bg->SetRelativeLocation(FVector(0, 10, 64));
	Bg->SetTranslucentSortPriority(2);


	Title->SetupAttachment(this);
	Title->SetRelativeLocation(FVector(0, 12, 64));
	Title->SetTranslucentSortPriority(3);
	Title->SetRelativeRotation(FRotator(0, 90, 0));

	Title->SetText(FText::FromString(TEXT("Test")));
	Title->SetTextRenderColor(FColor::White);
	Title->SetWorldSize(18.0);

	Title->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	Title->SetVerticalAlignment(EVerticalTextAligment::EVRTA_TextCenter);
}


// Called when the game starts
void UBuildingTitleComp::BeginPlay()
{
	Super::BeginPlay();
	Bg->SetSprite(LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/NormalUi/5/title_main_build.title_main_build'")));
	// ...

}

void UBuildingTitleComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
