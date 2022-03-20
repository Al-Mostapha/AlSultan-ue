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
	
	ASBuildingClassBarrack();
	UPaperFlipbookComponent* TrainInfantry;


	/*
		Btn Building List
	*/
	static FString IL_BuildingTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingActionBtnsComp* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingActionBtnsComp* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingActionBtnsComp* BtnCompTrain;

	/*
		Btn Function  Building List
	*/
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedTrain();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);

	void initBuilding() override;

	void setSprite();
	virtual void BeginPlay() override;
	
	void showTrainSol();
	void hideTrainSol();
	void setBarrackInfantry();
	void bindBtnActionFunction();
	
};
