// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassLeisureHouse.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassLeisureHouse : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	ASBuildingClassLeisureHouse();

	/*
		Btn Building List
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompPyramid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompFriend;

	/*
		Btn Function  Building List
	*/
	UFUNCTION() void OnBtnClickedPyramid();
	UFUNCTION() void OnBtnClickedFriend();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);

	void setSprite();
	virtual void BeginPlay() override;
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
};
