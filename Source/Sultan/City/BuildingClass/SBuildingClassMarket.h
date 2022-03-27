// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassMarket.generated.h"


USTRUCT() struct FBuildingLvlDataMarket : public FBuildingLvlData {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere) int32 capacity;
		UPROPERTY(EditAnywhere) int32 taxRate;
};


/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassMarket : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataMarket> LvlData;

	ASBuildingClassMarket();

	/*
		Btn List
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompTrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompAuction;

	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedTrade();
	UFUNCTION() void OnBtnClickedAuction();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);


	void setSprite();
	virtual void BeginPlay() override;
	
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);
};
