// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"
#include "Blueprint/UserWidget.h"
#include "SWid_BuildingProgBar.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API USWid_BuildingProgBar : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UProgressBar* ProgBar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* OperationTitle;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* RemainingTime;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UBorder* OperationIcon;

};
