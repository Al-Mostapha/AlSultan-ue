// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "Components/TextRenderComponent.h"
#include "SBuildingNameComp.generated.h"




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SULTAN_API USBuildingNameComp : public UWidgetComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USBuildingNameComp();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSpriteComponent* Bg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextRenderComponent* Name;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
