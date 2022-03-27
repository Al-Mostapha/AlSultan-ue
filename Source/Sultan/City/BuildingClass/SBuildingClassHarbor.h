// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassHarbor.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassHarbor : public ASCityBuilding
{
	GENERATED_BODY()
public:
	
	ASBuildingClassHarbor();

	/* Btn Building List */
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompVipMall;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDailyReward;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDailyCard;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompMonthlyReward;
	static FString IL_BuildingTitle;

	/* Btn Function  Building List */
	UFUNCTION() void OnBtnClickedVipMall();
	UFUNCTION() void OnBtnClickedDailyReward();
	UFUNCTION() void OnBtnClickedDailyCard();
	UFUNCTION() void OnBtnClickedMonthlyReward();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);

	void setSprite();
	virtual void BeginPlay() override;
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
};
