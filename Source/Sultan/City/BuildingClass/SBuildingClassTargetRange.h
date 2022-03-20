// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassTargetRange.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassTargetRange : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;

	ASBuildingClassTargetRange();

	UPaperFlipbookComponent* TrainArcher1;
	UPaperFlipbookComponent* TrainArcher2;
	UPaperFlipbookComponent* TrainArcher3;
	UPaperFlipbookComponent* TrainArcher4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompTrain;

	/*
		Btn Function  Building List
	*/
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedTrain();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);


	void setSprite();
	virtual void BeginPlay() override;
	void showTrainSol();
	void hideTrainSol();
	void setBuildingArcher();
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
};
