// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassEmbassy.generated.h"


USTRUCT() struct FBuildingLvlDataEmbassy : public FBuildingLvlData {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere) int32 helpCount;
		UPROPERTY(EditAnywhere) int32 reduceTime;
		UPROPERTY(EditAnywhere) int32 reinforcements;
};

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassEmbassy : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataEmbassy> LvlData;

	/* Btn Building List */
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompHelp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompReinforce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompParliament;


	/* Btn Function  Building List */
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedHelp();
	UFUNCTION() void OnBtnClickedReinforce();
	UFUNCTION() void OnBtnClickedParliament();

	
	ASBuildingClassEmbassy();

	void setSprite();
	virtual void BeginPlay() override;
	UFUNCTION()
		void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);
};
