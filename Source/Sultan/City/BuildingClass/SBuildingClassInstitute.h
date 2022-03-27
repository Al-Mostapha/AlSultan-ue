// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassInstitute.generated.h"


USTRUCT() struct FBuildingLvlDataInstitute : public FBuildingLvlData {
	GENERATED_BODY()
		UPROPERTY(EditAnywhere) ECEduType unlockedTechnology;
};


/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassInstitute : public ASCityBuilding
{
	GENERATED_BODY()
public:

	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataInstitute> LvlData;

	ASBuildingClassInstitute();

	/* Btn Building List */
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompResearch;


	/* Btn Function  Building List */
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedResearch();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);


	void setSprite();
    void BeginPlay() override;
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
	void setOperatingProgressBar();
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);

};
