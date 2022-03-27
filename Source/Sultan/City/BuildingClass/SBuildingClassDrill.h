// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassDrill.generated.h"



USTRUCT() struct FBuildingLvlDataDrill : public FBuildingLvlData {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere) int32 capacity;
};

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassDrill : public ASCityBuilding
{
	GENERATED_BODY()
public:
	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataDrill> LvlData;

	/* Btn Building List */
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompArena;

	/* Btn Function  Building List */
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedArena();

	
	ASBuildingClassDrill();

	void setSprite();
	virtual void BeginPlay() override;
	UFUNCTION()
		void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);
};
