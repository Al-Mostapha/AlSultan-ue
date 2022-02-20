// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "SBuildingActionBtnsComp.generated.h"





UCLASS()
class SULTAN_API USBuildingActionBtnsComp : public UWidgetComponent
{
	GENERATED_BODY()
public:
	USBuildingActionBtnsComp();
	UFUNCTION(BlueprintImplementableEvent)
	void initView();
};
