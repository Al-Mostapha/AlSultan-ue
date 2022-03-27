// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassTreasurePool.generated.h"


USTRUCT(BlueprintType)
struct FTreasurePoolCapacity{


	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Grain;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Lumber;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Iron;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Silver;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Metal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32 Crysrtal;
};

USTRUCT() struct FBuildingLvlDataTreasurePool : public FBuildingLvlData {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere) int32 freeTime;
		UPROPERTY(EditAnywhere) FTreasurePoolCapacity capacity;
};

/**
 *
 */
UCLASS()
class SULTAN_API ASBuildingClassTreasurePool : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataTreasurePool> LvlData;


	ASBuildingClassTreasurePool();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompTreaHunt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompEndTrea;

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
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);
};
