// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassInstitute.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassInstitute : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	ASBuildingClassInstitute();

	/* Btn Building List */
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompResearch;


	/* Btn Function  Building List */
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedResearch();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);


	void setSprite();
    void BeginPlay() override;
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
};
