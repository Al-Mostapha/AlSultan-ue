// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassHallOfWar.generated.h"




USTRUCT() struct FBuildingLvlDataHallOfWar : public FBuildingLvlData {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) int32 capacity;
};

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassHallOfWar : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataHallOfWar> LvlData;

	/* Btn Building List */
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompAlncWar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompMedalExchange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompCounterAttack;

	/* Btn Function  Building List */
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedAlncWar();
	UFUNCTION() void OnBtnClickedMedalExchange();
	UFUNCTION() void OnBtnClickedCounterAttack();

	
	ASBuildingClassHallOfWar();

	void setSprite();
	virtual void BeginPlay() override;
	UFUNCTION()
		void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);
};
