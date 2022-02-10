// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SWorldGM.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASWorldGM : public AGameMode
{
	GENERATED_BODY()
public:
		 ASWorldGM();
	void StartPlay();
	
};
