// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingActionBtnsWid.h"

TMap<EBuildingBtnAction, FBuildingActionBtn> FBuildingActionBtn::BuildingActionBtns;

void FBuildingActionBtn::addActionBtn(EBuildingBtnAction BtnAction, FString WP_ButtonPath, FString IL_Btn) {

	if (WP_ButtonPath == "")
		return;
	FString ClassBath = FString::Printf(TEXT("/Game/City/CityOld/BuildingWidgets/BuildingActionBtns/Btns/%s.%s_C"), *WP_ButtonPath, *WP_ButtonPath);
	FBuildingActionBtn T = FBuildingActionBtn();
	T.WP_Button = LoadObject<UClass>(nullptr, *ClassBath);
	T.BtnAction = BtnAction;
	T.IL_Btn = IL_Btn;
	BuildingActionBtns.Add(BtnAction, T);

}


void FBuildingActionBtn::initActionBtn() {

	/**/
	addActionBtn(EBuildingBtnAction::BBA_BOOST, "WBP_BAB_Boost", "common_text_058");
	addActionBtn(EBuildingBtnAction::BBA_BOOST_BY_TOOL, "WBP_BAB_BoostByTool", "common_text_058");
	addActionBtn(EBuildingBtnAction::BBA_DETAIL, "WBP_BAB_Details", "common_text_059");
	addActionBtn(EBuildingBtnAction::BBA_SPEED_UP_BY_GOLD, "WBP_BAB_SpeedUpByGold", "common_text_018");
	addActionBtn(EBuildingBtnAction::BBA_SPEED_UP_BY_TOOL, "WBP_BAB_SpeedUpByTool", "common_text_018");
	addActionBtn(EBuildingBtnAction::BBA_UPGRADE, "WBP_BAB_Upgrade", "common_text_055");
	addActionBtn(EBuildingBtnAction::BBA_TRADE, "WBP_BAB_MarkTrade", "common_text_044");
	addActionBtn(EBuildingBtnAction::BBA_RESEARCH, "WBP_BAB_Research", "common_text_062");
	addActionBtn(EBuildingBtnAction::BBA_BUILD, "WBP_BAB_TrabTrain", "common_text_042");
	addActionBtn(EBuildingBtnAction::BBA_TRAIN, "WBP_BAB_Train", "common_text_061");
	addActionBtn(EBuildingBtnAction::BBA_HELP, "WBP_BAB_AlncHelp", "common_text_037");
	addActionBtn(EBuildingBtnAction::BBA_REINFORCEMENTS, "WBP_BAB_ArmyHelp", "common_text_010");
	addActionBtn(EBuildingBtnAction::BBA_WISH, "WBP_BAB_Wish", "common_text_060");
	addActionBtn(EBuildingBtnAction::BBA_ALLIANCEBATTLE, "WBP_BAB_AlncWar", "common_text_047");
	addActionBtn(EBuildingBtnAction::BBA_DEFEND, "WBP_BAB_CityDef", "common_text_041");
	addActionBtn(EBuildingBtnAction::BBA_MILITARYINFO, "WBP_BAB_MilitInfo", "common_text_045");
	addActionBtn(EBuildingBtnAction::BBA_CITY_INFO, "WBP_BAB_CityInfo", "common_text_039");
	addActionBtn(EBuildingBtnAction::BBA_CITY_GIFT, "WBP_BAB_CityGift", "common_text_4030");
	addActionBtn(EBuildingBtnAction::BBA_CITY_BUFF, "WBP_BAB_CityEffect", "common_text_014");
	addActionBtn(EBuildingBtnAction::BBA_HEAL, "WBP_BAB_OutHeal", "common_text_065");
	addActionBtn(EBuildingBtnAction::BBA_COLLECT_Fod, "WBP_BAB_ResCollFod", "common_text_057");
	addActionBtn(EBuildingBtnAction::BBA_COLLECT_Wod, "WBP_BAB_ResCollWood", "common_text_057");
	addActionBtn(EBuildingBtnAction::BBA_COLLECT_Cry, "WBP_BAB_ResCollCry", "common_text_057");
	addActionBtn(EBuildingBtnAction::BBA_COLLECT_Irn, "WBP_BAB_ResCollIrn", "common_text_057");
	addActionBtn(EBuildingBtnAction::BBA_COLLECT_Sil, "WBP_BAB_ResCollSil", "common_text_057");
	addActionBtn(EBuildingBtnAction::BBA_COLLECT_Stl, "WBP_BAB_ResCollStl", "common_text_057");
	addActionBtn(EBuildingBtnAction::BBA_RES_Acc_Fod, "WBP_BAB_ResAccFod", "common_text_018");
	addActionBtn(EBuildingBtnAction::BBA_RES_Acc_Wod, "WBP_BAB_ResAccWod", "common_text_018");
	addActionBtn(EBuildingBtnAction::BBA_RES_Acc_Cry, "WBP_BAB_ResAccCry", "common_text_018");
	addActionBtn(EBuildingBtnAction::BBA_RES_Acc_Irn, "WBP_BAB_ResAccIrn", "common_text_018");
	addActionBtn(EBuildingBtnAction::BBA_RES_Acc_Sil, "WBP_BAB_ResAccSil", "common_text_018");
	addActionBtn(EBuildingBtnAction::BBA_FORGING, "WBP_BAB_Froging", "common_text_1339");
	addActionBtn(EBuildingBtnAction::BBA_STORAGEBOX, "WBP_BAB_StorageBox", "common_text_040");
	addActionBtn(EBuildingBtnAction::BBA_PYRAMID, "WBP_BAB_BtnPyramid", "common_text_1140");
	addActionBtn(EBuildingBtnAction::BBA_CITY_DECORATE, "WBP_BAB_CitySkin", "common_text_1798");
	addActionBtn(EBuildingBtnAction::BBA_BADGEBOURSE, "WBP_BAB_BtnBadgeBourse", "common_text_1906");
	addActionBtn(EBuildingBtnAction::BBA_FRIEND, "WBP_BAB_EmbsFriend", "friend_name_01");
	addActionBtn(EBuildingBtnAction::BBA_WAR, "WBP_BAB_BtnHonorUp", "common_text_310");
	addActionBtn(EBuildingBtnAction::BBA_FACEBOOKTREASURE, "", "");
	addActionBtn(EBuildingBtnAction::BBA_MILITARY_POINT, "WBP_BAB_MilitExch", "common_text_2408");
	addActionBtn(EBuildingBtnAction::BBA_MONTH_GIFT, "WBP_BAB_BoatMonthGift", "common_text_2476");
	addActionBtn(EBuildingBtnAction::BBA_DAILYSIGN, "WBP_BAB_BoatDailySign", "login_title_01");
	addActionBtn(EBuildingBtnAction::BBA_RESUSCITATE, "WBP_BAB_BtnResuscitate", "common_text_2499");
	addActionBtn(EBuildingBtnAction::BBA_DAILYREWARD, "WBP_BAB_BoatDailyReward", "common_text_2657");
	addActionBtn(EBuildingBtnAction::BBA_AUCTION, "WBP_BAB_MarkAuction", "common_text_2768");
	addActionBtn(EBuildingBtnAction::BBA_PET, "WBP_BAB_BuildPet", "common_text_2975");
	addActionBtn(EBuildingBtnAction::BBA_PET_MAP, "WBP_BAB_BuildPetBook", "common_text_2935");
	addActionBtn(EBuildingBtnAction::BBA_STRING_OF_LIFE, "WBP_BAB_SpringOfLife", "common_text_3459");
	addActionBtn(EBuildingBtnAction::BBA_PREMIUM_VIP_MALL, "WBP_BAB_VIPMall", "common_text_1967");
	addActionBtn(EBuildingBtnAction::BBA_PET_EXCHANGE, "WBP_BAB_BuildPetExch", "common_text_3799");
	addActionBtn(EBuildingBtnAction::BBA_WAR_GEM, "WBP_BAB_WarGem", "common_text_3878");
	addActionBtn(EBuildingBtnAction::BBA_WAR_TECHNOLOGY, "WBP_BAB_WarTechnology", "common_text_3905");
	addActionBtn(EBuildingBtnAction::BBA_GOD_EQUIPMENT, "", "");
	addActionBtn(EBuildingBtnAction::BBA_ARTIFACT, "WBP_BAB_BtnArtiFact", "artifact_title_01");
	addActionBtn(EBuildingBtnAction::BBA_ALLIANCE_TREASURE, "WBP_BAB_AlncTrea", "allitreas_title_01");
	addActionBtn(EBuildingBtnAction::BBA_ARENA, "WBP_BAB_ArenaBtn", "arena_btn_01");
	addActionBtn(EBuildingBtnAction::BBA_DISCUSS, "WBP_BAB_SupDiscuss", "common_text_3421");
	addActionBtn(EBuildingBtnAction::BBA_SUPPORT, "WBP_BAB_SupSupport", "common_btn_06");
	addActionBtn(EBuildingBtnAction::BBA_INFOCENTER, "WBP_BAB_SupInfCnt", "common_text_3162_ros");
	addActionBtn(EBuildingBtnAction::BBA_FACTION, "WBP_BAB_CivilExch", "civilization_system_text_04");
	addActionBtn(EBuildingBtnAction::BBA_MONUMENT, "", "");
	addActionBtn(EBuildingBtnAction::BBA_TRAINHALL, "WBP_BAB_HeroTrain", "common_text_061");
	addActionBtn(EBuildingBtnAction::BBA_PRISON, "WBP_BAB_HeroPrison", "buildDes_name_125");
	addActionBtn(EBuildingBtnAction::BBA_MASTERY, "WBP_BAB_BtnMastery", "specialization_text_02");
	addActionBtn(EBuildingBtnAction::BBA_MAINMASTERY, "WBP_BAB_BtnMaysteryMain", "specialization_text_03");
	addActionBtn(EBuildingBtnAction::BBA_DRAWING, "WBP_BAB_BtnDrawing", "drawing_btn_01");
	addActionBtn(EBuildingBtnAction::BBA_MONUMENT_LEGEND, "WBP_BAB_BtnDrawing", "history_name_11");
	addActionBtn(EBuildingBtnAction::BBA_INTETIOR, "WBP_BAB_EmbsParliament", "parliament_name_01");
	addActionBtn(EBuildingBtnAction::BBA_COUNTER_SYS, "WBP_BAB_AlncCounterSys", "CounterSystem_btn_01");
	addActionBtn(EBuildingBtnAction::BBA_EXCLUSIVE_VIP, "WBP_BAB_VipExclusive", "privilege_text_06");
	addActionBtn(EBuildingBtnAction::BBA_STARUPGRADE, "WBP_BAB_StarUpgrade", "Glory_text_10");
	addActionBtn(EBuildingBtnAction::BBA_STARSPEEDUP, "WBP_BAB_StarSpeedup", "Glory_text_29");
	addActionBtn(EBuildingBtnAction::BBA_ENDLESSTREASURE, "WBP_BAB_WishEndTreas", "endless_treasures_text_01");
	addActionBtn(EBuildingBtnAction::BBA_PROCESSSTUDY, "WBP_BAB_ProsStudy", "Soldiers_armor_text_2");
	addActionBtn(EBuildingBtnAction::BBA_WARFRAMEFORG, "WBP_BAB_WarFrog", "Soldiers_armor_text_3");
	addActionBtn(EBuildingBtnAction::BBA_WARFRAMESTOREROOM, "WBP_BAB_WarStoreRoom", "Soldiers_armor_text_4");
	addActionBtn(EBuildingBtnAction::BBA_STATUEBRAVE, "WBP_BAB_BtnstatueBrave", "ice_carnival_text03");
	addActionBtn(EBuildingBtnAction::BBA_MILITARY_FORTRESS, "WBP_BAB_MilitFortress", "fortress_name_01");
	USWid_BuildingACBtn::setBtnStyle();
}


void USBuildingActionBtnsWid::addBtnsList(const TArray<FBuildingActionBtn>& BtnList) {



	static TArray<float> AngleRengeStart = { 90, 75, 60, 45, 30, 15, 0, -15, -30 };
	static float Reduis = 220.0f;
	float startingAngle = 0, x, y;
	float btnCount = float(BtnList.Num());
	int32 index = 0;

	if (AngleRengeStart.IsValidIndex(btnCount - 1)) {
		startingAngle = AngleRengeStart[btnCount - 1];
		GLog->Log(FString::Printf(TEXT(" Angle Start Angle %f And Btn count = %f"), startingAngle, btnCount));
	}
		
	for (const FBuildingActionBtn& Btn : BtnList) {
		USWid_BuildingACBtn* BtnWid = CreateWidget<USWid_BuildingACBtn>(GetWorld(), Btn.WP_Button);
		BtnWid->ActionBtn->SetStyle(USWid_BuildingACBtn::BtnStyle);
	    x = FMath::Sin(FMath::DegreesToRadians(startingAngle - 90 + index * 30)) * Reduis + Reduis - 13;
		y = FMath::Cos(FMath::DegreesToRadians(startingAngle - 90 + index * 30)) * Reduis + 16;
		ActionBtnContainer->AddChildToCanvas(BtnWid)->SetPosition(FVector2D(x,y));
		index++;
	}
}