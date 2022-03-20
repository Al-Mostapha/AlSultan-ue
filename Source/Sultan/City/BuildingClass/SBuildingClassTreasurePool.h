// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassTreasurePool.generated.h"

/**
 *
 */
UCLASS()
class SULTAN_API ASBuildingClassTreasurePool : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	ASBuildingClassTreasurePool();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompTreaHunt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompEndTrea;

	/*
		Btn Function  Building List
	*/
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedTreaHunt();
	UFUNCTION() void OnBtnClickedEndTrea();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);

	void setSprite();
	virtual void BeginPlay() override;
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
};
