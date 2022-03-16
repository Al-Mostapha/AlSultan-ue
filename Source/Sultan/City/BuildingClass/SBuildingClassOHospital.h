// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassOHospital.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassOHospital : public ASCityBuilding
{
	GENERATED_BODY()
public:
	void initBuilding() override;
};
