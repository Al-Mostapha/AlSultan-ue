// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassOSawMill.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassOSawMill : public ASCityBuilding
{
	GENERATED_BODY()
		void initBuilding() override;
};
