// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Model/SCityModel.h"
#include "UObject/NoExportTypes.h"
#include "SGameMain.generated.h"

#define WORLD_WIDTH_IN_UNIT  1200
#define WORLD_HEIGHT_IN_UNIT 1200

#define PRINT_STRING(Str) UE_LOG(LogTemp, Warning, TEXT("Debug Print String is %s"), *Str)

#define PRINT_STRUCT(Str){\
	FString DString; FJsonObjectConverter::UStructToJsonObjectString(Str, DString);\
	UE_LOG(LogTemp, Warning, TEXT("Debug Object To Print is %s"), *DString)}

/**
 * 
 */
UCLASS()
class SULTAN_API USGameMain : public UObject
{
	GENERATED_BODY()
public:
	static FCityDS PlayerCity;
};
