// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassWall.generated.h"



USTRUCT() struct FBuildingLvlDataWall: public FBuildingLvlData {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) int32 defValue;
	UPROPERTY(EditAnywhere) int32 capacity;
};

/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassWall : public ASCityBuilding
{
	GENERATED_BODY()

public:

	static FString IL_BuildingTitle;
	static TMap<int32, FBuildingLvlDataWall> LvlData;

	ASBuildingClassWall();

	UPaperSpriteComponent* Wall1;
	UPaperSpriteComponent* Wall2;
	UPaperSpriteComponent* Wall3;
	UPaperSpriteComponent* Wall4;
	UPaperSpriteComponent* ArrowTower1;
	UPaperSpriteComponent* ArrowTower2;
	UPaperSpriteComponent* WallGate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDetail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompUpgrade;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* BtnCompDefence;

	/*
		Btn Function  Building List
	*/
	UFUNCTION() void OnBtnClickedDetail();
	UFUNCTION() void OnBtnClickedUpgrade();
	UFUNCTION() void OnBtnClickedDefence();
	UFUNCTION() void OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed);


	void setSprite();
	virtual void BeginPlay() override;
	void setBuildingActionBtnList() override;
	void initBuilding() override;
	void bindBtnActionFunction();
	static void getLvlData(TSharedPtr<FJsonObject> JsonValue);
};
