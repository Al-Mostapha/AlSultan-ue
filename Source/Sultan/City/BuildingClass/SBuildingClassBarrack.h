// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassBarrack.generated.h"



USTRUCT() struct FBuildingLvlDataBarrack : public FBuildingLvlData {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) ECArmyType unlockedSoldier;
};

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassBarrack : public ASCityBuilding
{
	GENERATED_BODY()

public:
	
	ASBuildingClassBarrack();
	UPaperFlipbookComponent* TrainInfantry;


	/*
		Btn Building List
	*/
	static FString IL_BuildingTitle;
    static TMap<int32, FBuildingLvlDataBarrack> LvlData;
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

	void initBuilding() override;

	void setSprite();
	virtual void BeginPlay() override;
	void showTrainSol();
	void hideTrainSol();
	void setBarrackInfantry();
	void bindBtnActionFunction();
	void setOperatingProgressBar() override;
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);
	
};
