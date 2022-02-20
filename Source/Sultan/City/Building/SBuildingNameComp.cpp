// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingNameComp.h"

// Sets default values for this component's properties
USBuildingNameComp::USBuildingNameComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Bg   = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	Name = CreateDefaultSubobject<UTextRenderComponent>(TEXT("NameText"));
	// ...
	SetTranslucentSortPriority(2);
	Bg->SetupAttachment(this);
	Bg->SetRelativeLocation(FVector(0 , 10, -96));
	Bg->SetTranslucentSortPriority(2);


	Name->SetupAttachment(this);
	Name->SetRelativeLocation(FVector(0, 12, -96));
	Name->SetTranslucentSortPriority(3);
	Name->SetRelativeRotation(FRotator(0, 90, 0));

	Name->SetText(FText::FromString(TEXT("Test")));
	//220, 215, 180
	Name->SetTextRenderColor(FColor(220, 215, 180));
	Name->SetWorldSize(18.0);

	Name->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	Name->SetVerticalAlignment(EVerticalTextAligment::EVRTA_TextCenter);
	
	
/**	BuildingName->Bg->SetupAttachment(RootComponent);

	BuildingName->Bg->SetRelativeLocation(FVector(128, 10, 15));*/
}


// Called when the game starts
void USBuildingNameComp::BeginPlay()
{
	Super::BeginPlay();
	Bg->SetSprite(LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/NormalUi/5/title_main_build_01.title_main_build_01'")));
	// ...

}


// Called every frame
void USBuildingNameComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

