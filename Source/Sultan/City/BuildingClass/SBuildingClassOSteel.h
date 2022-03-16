// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassOSteel.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassOSteel : public ASCityBuilding
{
	GENERATED_BODY()
		void initBuilding() override;
};
