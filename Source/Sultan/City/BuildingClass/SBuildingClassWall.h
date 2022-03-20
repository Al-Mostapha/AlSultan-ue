// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassWall.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassWall : public ASCityBuilding
{
	GENERATED_BODY()

public:

	static FString IL_BuildingTitle;

	ASBuildingClassWall();

	UPaperSpriteComponent* Wall1;
	UPaperSpriteComponent* Wall2;
	UPaperSpriteComponent* Wall3;
	UPaperSpriteComponent* Wall4;
	UPaperSpriteComponent* ArrowTower1;
	UPaperSpriteComponent* ArrowTower2;
	UPaperSpriteComponent* WallGate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingActionBtnsComp* BtnCompDefence;

	/*
		Btn Function  Building List
	*/
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedDefence();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);


	void setSprite();
	virtual void BeginPlay() override;
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
};
