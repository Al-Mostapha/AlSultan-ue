// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "SBuildingNotifComp.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API USBuildingNotifComp : public UWidgetComponent
{
	GENERATED_BODY()
public:
		USBuildingNotifComp();
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* Bg;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* Icon;
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
