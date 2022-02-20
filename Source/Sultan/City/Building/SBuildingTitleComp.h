// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Components/TextRenderComponent.h"
#include "SBuildingTitleComp.generated.h"

/**
 *
 */
UCLASS()
class SULTAN_API USBuildingTitleComp : public UWidgetComponent
{
	GENERATED_BODY()
public:
	USBuildingTitleComp();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperSpriteComponent* Bg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTextRenderComponent* Title;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};

