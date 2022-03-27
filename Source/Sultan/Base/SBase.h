// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "../Network/SNetBase.h"
#include "SBase.generated.h"




/**
 * 
 */
UCLASS()
class SULTAN_API USBase : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "")
	static FString Trans(UPARAM(ref) FString& IdLang);
};
