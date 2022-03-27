// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassWorkshop.generated.h"



USTRUCT() struct FBuildingLvlDataWorkshop : public FBuildingLvlData {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere) ECArmyType unlockedSoldier;
};


/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassWorkshop : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataWorkshop> LvlData;

	ASBuildingClassWorkshop();

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompTrain;

	/*
		Btn Function  Building List
	*/
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedTrain();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);

	void setSprite();
	virtual void BeginPlay() override;
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
	void setOperatingProgressBar();
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);

};
