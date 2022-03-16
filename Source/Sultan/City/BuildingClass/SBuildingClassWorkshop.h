// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassWorkshop.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassWorkshop : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	ASBuildingClassWorkshop();

	void setSprite();
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);
	void setBuildingActionBtnList() override;
	void initBuilding() override;
};
