// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "../../Base/SBase.h"
#include "../Building/SBuildingNameComp.h"
#include "../Building/SBuildingTitleComp.h"
#include "../Building/SBuildingLvlComp.h"
#include "../Building/SBuildingNotifComp.h"
#include "../BuildingWid/SBuildingActionBtnsWid.h"
#include "../BuildingWid/SWid_BuildingProgBar.h"
#include "../../Config/SCBuilding.h"
#include "../../Config/SCArmy.h"
#include "../../Config/SCEdu.h"
#include "Components/WidgetComponent.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

#include "SCityBuilding.generated.h"


USTRUCT(BlueprintType)
struct FCityBuildingPos : public FTableRowBase {


	GENERATED_BODY()
public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString BuildingPlace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector Vect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FRotator Rot;
};




USTRUCT(BlueprintType)
struct FCityFixedBuildingPosAndSp: public FTableRowBase {


	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FString BuildingPlace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FVector Vect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FRotator Rot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) class UPaperSprite* Sprite;
};


USTRUCT() struct FBuildingLvlData {

	GENERATED_BODY()

	UPROPERTY(EditAnywhere) int32 kingdomLv;
	UPROPERTY(EditAnywhere) int32 kingdomPoint;
	UPROPERTY(EditAnywhere) TArray<FBuildingLvlUpPreCond> preCond;
	UPROPERTY(EditAnywhere) TArray<FBuildingLvlUpCostTool> costTools;
	UPROPERTY(EditAnywhere) FBuildingLvlUpResReq costRes;
	UPROPERTY(EditAnywhere) int32 costTime;
	UPROPERTY(EditAnywhere) int32 exp;
	UPROPERTY(EditAnywhere) int32 power;
};




UCLASS()
class SULTAN_API ASCityBuilding : public APawn
{
	GENERATED_BODY()
public:

	static FString ProgBarClassPath;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) UPaperSpriteComponent* Sprite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingNameComp* BuildingName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingTitleComp* BuildingTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingLvlComp* BuildingLvl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) USBuildingNotifComp* BuildingNotif;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* ActionBtnWid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) UWidgetComponent* ProgressBarWid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) TArray<FBuildingActionBtn> BtnActionList;
	UFUNCTION() void OnSelected(UPrimitiveComponent* Target, FKey ButtonPressed);

	TMap<EBuildingBtnAction, UWidgetComponent*> BtnListComp;
	UWidgetComponent* BtnActionPanelBg;
	FString CoolingIcon;
	FString IL_CoolingTitle;
	FString BuildingPlace;
	static UDataTable* CityBuildingPos;

	ASCityBuilding();
	void setSprite(class UPaperSprite* Sprite);
	void addActionBtnComp();
	void setUpgradingProgressBar();
	virtual void initBuilding();
	virtual void setBuildingActionBtnList();
	virtual void setOperatingProgressBar();

	static void getBuildingLvlData();
	


};
