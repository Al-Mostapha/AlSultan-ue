// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SGameMain.generated.h"

#define WORLD_WIDTH_IN_UNIT  1200
#define WORLD_HEIGHT_IN_UNIT 1200

#define PRINT_STRING(Str) UE_LOG(LogTemp, Warning, TEXT("Debug Print String is %s"), *Str)
/**
 * 
 */
UCLASS()
class SULTAN_API USGameMain : public UObject
{
	GENERATED_BODY()
		
};
