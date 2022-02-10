// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SCityGM.generated.h"

/**
 * 
 */


UCLASS()
class SULTAN_API ASCityGM : public AGameMode
{
	GENERATED_BODY()
		ASCityGM();
		void initCamera();
		void StartPlay();
		virtual void BeginPlay();
		void buildCityBuilding();
		void buildCityFloor();
		void buildCityFixedBuilding();
		void buildCityFixedDecore();
		void buildCityResBuilding();
		void buildCityOuterBuilding();
		void buildCompleteBuilding();

};
