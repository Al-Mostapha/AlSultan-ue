// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassOMiliTent.generated.h"

USTRUCT() struct FBuildingLvlDataMiliTent : public FBuildingLvlData {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere) int32 capacity;
	UPROPERTY(EditAnywhere) int32 trainspeed;
};


/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassOMiliTent : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataMiliTent> LvlData;


	ASBuildingClassOMiliTent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;

	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);


	void setSprite();
	virtual void BeginPlay() override;
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);
};
