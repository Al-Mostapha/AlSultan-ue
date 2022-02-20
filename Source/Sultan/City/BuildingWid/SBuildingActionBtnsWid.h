// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Building/SBuildingActionBtnsComp.h"
#include "SWid_BuildingACBtn.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "SBuildingActionBtnsWid.generated.h"


/*
 
 

  [1048] = {
    btnId = 1048,
    OpName = "OpMonument",
    Desc = "buildDes_name_124",
    PicFile = "btn_main_monument.png",
    OpSortIndex = 420,
    scale = 0,
    offset = {x = 0, y = 0}
  }
}
return data
*/

UENUM(BlueprintType)
enum class EBuildingBtnAction : uint8 {
	BBA_BOOST UMETA(DisplayName = "BBA Boost"),
	BBA_BOOST_BY_TOOL UMETA(DisplayName = "BBA BoostByTool"),
	BBA_DETAIL UMETA(DisplayName = "BBA Details"),
	BBA_SPEED_UP_BY_GOLD UMETA(DisplayName = "BBA SpeedUpByGold"),
	BBA_SPEED_UP_BY_TOOL UMETA(DisplayName = "BBA SpeedUpByTool"),
	BBA_UPGRADE UMETA(DisplayName = "BBA Upgrade"),
	BBA_TRADE UMETA(DisplayName = "BBA Trade"),
	BBA_RESEARCH UMETA(DisplayName = "BBA Research"),
	BBA_BUILD UMETA(DisplayName = "BBA Build"),
	BBA_TRAIN UMETA(DisplayName = "BBA Train"),
	BBA_HELP UMETA(DisplayName = "BBA Help"),
	BBA_REINFORCEMENTS UMETA(DisplayName = "BBA Reinforcements"),
	BBA_WISH UMETA(DisplayName = "BBA Wish"),
	BBA_ALLIANCEBATTLE UMETA(DisplayName = "BBA AllianceBattle"),
	BBA_DEFEND UMETA(DisplayName = "BBA Defend"),
	BBA_MILITARYINFO UMETA(DisplayName = "BBA MilitaryInfo"),
	BBA_CITY_INFO UMETA(DisplayName = "BBA CityInfo"),
	BBA_CITY_GIFT UMETA(DisplayName = "BBA CityGift"),
	BBA_CITY_BUFF UMETA(DisplayName = "BBA CityBuff"),
	BBA_HEAL UMETA(DisplayName = "BBA Heal"),
	BBA_COLLECT_Fod UMETA(DisplayName = "BBA Collect Food"),
	BBA_COLLECT_Cry UMETA(DisplayName = "BBA Collect Cry"),
	BBA_COLLECT_Irn UMETA(DisplayName = "BBA Collect Iron"),
	BBA_COLLECT_Sil UMETA(DisplayName = "BBA Collect Silver"),
	BBA_COLLECT_Stl UMETA(DisplayName = "BBA Collect Steel"),
	BBA_RES_Acc_Fod UMETA(DisplayName = "BBA Collect Food"),
	BBA_RES_Acc_Cry UMETA(DisplayName = "BBA Collect Cry"),
	BBA_RES_Acc_Irn UMETA(DisplayName = "BBA Collect Irn"),
	BBA_RES_Acc_Sil UMETA(DisplayName = "BBA Collect Sil"),
	BBA_RES_Acc_Stl UMETA(DisplayName = "BBA Collect Steel"),
	BBA_FORGING UMETA(DisplayName = "BBA Forging"),
	BBA_STORAGEBOX UMETA(DisplayName = "BBA Storagebox"),
	BBA_PYRAMID UMETA(DisplayName = "BBA Pyramid"),
	BBA_CITY_DECORATE UMETA(DisplayName = "BBA CityDecorate"),
	BBA_BADGEBOURSE UMETA(DisplayName = "BBA BadgeBourse"),
	BBA_FRIEND UMETA(DisplayName = "BBA Friend"),
	BBA_WAR UMETA(DisplayName = "BBA War"),
	BBA_FACEBOOKTREASURE UMETA(DisplayName = "BBA FaceBookTreasure"),
	BBA_MILITARY_POINT UMETA(DisplayName = "BBA MilitaryPoint"),
	BBA_MONTH_GIFT UMETA(DisplayName = "BBA MonthGift"),
	BBA_DAILYSIGN UMETA(DisplayName = "BBA DaylySign"),
	BBA_RESUSCITATE UMETA(DisplayName = "BBA Resuscitate"),
	BBA_DAILYREWARD UMETA(DisplayName = "BBA DailyReward"),
	BBA_AUCTION UMETA(DisplayName = "BBA Auction"),
	BBA_PET UMETA(DisplayName = "BBA Pet"),
	BBA_PET_MAP UMETA(DisplayName = "BBA PetMap"),
	BBA_STRING_OF_LIFE UMETA(DisplayName = "BBA SpringOfLife"),
	BBA_PREMIUM_VIP_MALL UMETA(DisplayName = "BBA PremiumVipMall"),
	BBA_PET_EXCHANGE UMETA(DisplayName = "BBA PetExchange"),
	BBA_WAR_GEM UMETA(DisplayName = "BBA WarGem"),
	BBA_WAR_TECHNOLOGY UMETA(DisplayName = "BBA WarTechnology"),
	BBA_GOD_EQUIPMENT UMETA(DisplayName = "BBA GodEquipment"),
	BBA_ARTIFACT UMETA(DisplayName = "BBA Artifact"),
	BBA_ALLIANCE_TREASURE UMETA(DisplayName = "BBA AllianceTreasure"),
	BBA_ARENA UMETA(DisplayName = "BBA Arena"),
	BBA_DISCUSS UMETA(DisplayName = "BBA Discuss"),
	BBA_SUPPORT UMETA(DisplayName = "BBA Support"),
	BBA_INFOCENTER UMETA(DisplayName = "BBA InfoCenter"),
	BBA_FACTION UMETA(DisplayName = "BBA Faction"),
	BBA_MONUMENT UMETA(DisplayName = "BBA Monument"),
	BBA_TRAINHALL UMETA(DisplayName = "BBA TrainHall"),
	BBA_PRISON UMETA(DisplayName = "BBA Prison"),
	BBA_MASTERY UMETA(DisplayName = "BBA Mastery"),
	BBA_MAINMASTERY UMETA(DisplayName = "BBA MainMastery"),
	BBA_DRAWING UMETA(DisplayName = "BBA Drawing"),
	BBA_MONUMENT_LEGEND UMETA(DisplayName = "BBA MonumentLegend"),
	BBA_INTETIOR UMETA(DisplayName = "BBA Intetior"),
	BBA_COUNTER_SYS UMETA(DisplayName = "BBA CounterSys"),
	BBA_EXCLUSIVE_VIP UMETA(DisplayName = "BBA ExclusiveVip"),
	BBA_STARUPGRADE UMETA(DisplayName = "BBA StarUpgrade"),
	BBA_STARSPEEDUP UMETA(DisplayName = "BBA StarSpeedUp"),
	BBA_ENDLESSTREASURE UMETA(DisplayName = "BBA EndlessTreasure"),
	BBA_PROCESSSTUDY UMETA(DisplayName = "BBA ProcessStudy"),
	BBA_WARFRAMEFORG UMETA(DisplayName = "BBA WarframeForg"),
	BBA_WARFRAMESTOREROOM UMETA(DisplayName = "BBA WarframeStoreroom"),
	BBA_STATUEBRAVE UMETA(DisplayName = "BBA statueBrave"),
	BBA_MILITARY_FORTRESS UMETA(DisplayName = "BBA MilitaryFortress")
};


USTRUCT(BlueprintType)
struct FBuildingActionBtn {

	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString ActionCommand;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EBuildingBtnAction BtnAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector2D Postion;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<UUserWidget> WP_Button;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString IL_Btn;
	 static void initActionBtn();
	 static void addActionBtn(EBuildingBtnAction BtnAction, FString WP_ButtonPath, FString IL_Btn);
	 static TMap<EBuildingBtnAction, FBuildingActionBtn> BuildingActionBtns;
};



UCLASS()
class SULTAN_API USBuildingActionBtnsWid : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintImplementableEvent)
	void addActionBtns(TArray<FBuildingActionBtn> const& BtnList);
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UCanvasPanel* ActionBtnContainer;

    void addBtnsList(const TArray<FBuildingActionBtn>& BtnList);
};
