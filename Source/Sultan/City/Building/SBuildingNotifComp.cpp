// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingNotifComp.h"


// Sets default values for this component's properties
USBuildingNotifComp::USBuildingNotifComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Bg = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSpriteBg"));
	Icon = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSpriteIcon"));
	// ...
	Bg->SetupAttachment(this);
	Bg->SetRelativeLocation(FVector(0, 10, 128));
	Bg->SetTranslucentSortPriority(2);
		// ...
	Icon->SetupAttachment(Bg);
	Icon->SetRelativeLocation(FVector(4, 10, 8));
	Icon->SetTranslucentSortPriority(3);

}


// Called when the game starts
void USBuildingNotifComp::BeginPlay()
{
	Super::BeginPlay();
	Bg->SetSprite(LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/Icon/Building/icon_main_build_ring_02.icon_main_build_ring_02'")));
	Icon->SetSprite(LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/Icon/Building/icon_building_training_finish.icon_building_training_finish'")));
	// ...

}


// Called every frame
void USBuildingNotifComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



