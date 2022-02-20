// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingProgComp.h"

USBuildingProgComp::USBuildingProgComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetTranslucentSortPriority(4);
	// ...
	/**ProgressBar->SetupAttachment(this);
	ProgressBar->SetRelativeLocation(FVector(0, 10, -96));
	ProgressBar->SetTranslucentSortPriority(2);
	*/



	/**	BuildingName->Bg->SetupAttachment(RootComponent);

		BuildingName->Bg->SetRelativeLocation(FVector(128, 10, 15));*/
}


// Called when the game starts
void USBuildingProgComp::BeginPlay()
{
	Super::BeginPlay();
	//Bg->SetSprite(LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/NormalUi/5/title_main_build_01.title_main_build_01'")));
	// ...

}


// Called every frame
void USBuildingProgComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

