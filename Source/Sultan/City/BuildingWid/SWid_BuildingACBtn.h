// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "SWid_BuildingACBtn.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API USWid_BuildingACBtn : public UUserWidget
{
	GENERATED_BODY()
public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ILT_BtnTitle;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UTextBlock* BtnTitle;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    UButton* ActionBtn;
	UFUNCTION(BlueprintImplementableEvent)
	void setBtnTitle(const FString& Title);

	static FButtonStyle BtnStyle;
	static void setBtnStyle();
	
};
