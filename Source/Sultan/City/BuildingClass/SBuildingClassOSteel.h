// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassOSteel.generated.h"


USTRUCT() struct FBuildingLvlDataSteel : public FBuildingLvlData {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) int32 capacity;
	UPROPERTY(EditAnywhere) int32 output;
	UPROPERTY(EditAnywhere) int32 addOutputCostGold;
};


/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassOSteel : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataSteel> LvlData;

	ASBuildingClassOSteel();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompItemAcce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompGoldAcce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompCollect;

	UFUNCTION() void OnBtnClickedItemAcce();
	UFUNCTION() void OnBtnClickedGoldAcce();
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedCollect();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);


	void setSprite();
	virtual void BeginPlay() override;
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);

};
