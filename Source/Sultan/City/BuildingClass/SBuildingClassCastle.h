// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassCastle.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassCastle : public ASCityBuilding
{
	GENERATED_BODY()
		void setBuildingActionBtnList() override;
};
