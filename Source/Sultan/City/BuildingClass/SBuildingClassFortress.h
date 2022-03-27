// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassFortress.generated.h"



USTRUCT() struct FBuildingLvlDataFortress : public FBuildingLvlData {

	GENERATED_BODY()
	UPROPERTY(EditAnywhere) ECArmyType unlockedSoldier;
};



/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassFortress : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataFortress> LvlData;

	/* Btn Building List */
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompBuildTraps;


	/* Btn Function  Building List */
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedBuildTraps();

	ASBuildingClassFortress();

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
