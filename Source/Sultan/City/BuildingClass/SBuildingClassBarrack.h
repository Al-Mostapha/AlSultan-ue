// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassBarrack.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassBarrack : public ASCityBuilding
{
	GENERATED_BODY()

public:
	static FString IL_BuildingTitle;
	ASBuildingClassBarrack();
	UPaperFlipbookComponent* TrainInfantry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingActionBtnsComp* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingActionBtnsComp* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingActionBtnsComp* BtnCompTrain;

	void setSprite();
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);
	void showTrainSol();
	void hideTrainSol();
	void setBarrackInfantry();
	void bindBtnActionFunction();

	UFUNCTION()
	void OnBtnClickedDetail();	
	UFUNCTION()
	void OnBtnClickedUpgrade();
	UFUNCTION()
	void OnBtnClickedTrain();
};
