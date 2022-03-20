// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassEmbassy.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassEmbassy : public ASCityBuilding
{
	GENERATED_BODY()
public:

	/* Btn Building List */
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompHelp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompReinforce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompParliament;


	/* Btn Function  Building List */
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedHelp();
	UFUNCTION() void OnBtnClickedReinforce();
	UFUNCTION() void OnBtnClickedParliament();

	static FString IL_BuildingTitle;
	ASBuildingClassEmbassy();

	void setSprite();
	virtual void BeginPlay() override;
	UFUNCTION()
		void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
};
