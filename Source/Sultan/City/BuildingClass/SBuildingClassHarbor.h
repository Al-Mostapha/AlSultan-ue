// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassHarbor.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassHarbor : public ASCityBuilding
{
	GENERATED_BODY()
public:
	void initBuilding() override;
};
