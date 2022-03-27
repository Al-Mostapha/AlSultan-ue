// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassBlackSmith.generated.h"



USTRUCT() struct FBuildingLvlDataBlackSmith : public FBuildingLvlData {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere) int32 forgeSpeed;
		UPROPERTY(EditAnywhere) int32 steelReduce;
};


/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassBlackSmith : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataBlackSmith> LvlData;
	ASBuildingClassBlackSmith();

	/*
		Starting Btn ist For Building
	*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompFroge;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompStorage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompArtifacts;

	/*
		Btn Function  Building List
	*/
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedFroge();
	UFUNCTION() void OnBtnClickedStorage();
	UFUNCTION() void OnBtnClickedArtifacts();



	void setSprite();
	virtual void BeginPlay() override;
	UFUNCTION()
		void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
	void setOperatingProgressBar();
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);
};
