// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SCBuilding.h"
#include "SCArmy.generated.h"


UENUM()
enum class ECArmyID: uint64 {

	ARMY_NONE = 0,

	ArmyA_1 = 401,  ArmyA_2 = 402,  ArmyA_3 = 403,
	ArmyA_4 = 404,  ArmyA_5 = 405,  ArmyA_6 = 406,
	ArmyA_7 = 407,  ArmyA_8 = 408,  ArmyA_9 = 409,
	ArmyA_10 = 410, ArmyA_11 = 411, ArmyA_12 = 412,
	ArmyA_13 = 413, ArmyA_14 = 414,

	ArmyB_1 = 501,  ArmyB_2 = 502,  ArmyB_3 = 503,
	ArmyB_4 = 504,  ArmyB_5 = 505,  ArmyB_6 = 506,
	ArmyB_7 = 507,  ArmyB_8 = 508,  ArmyB_9 = 509,
	ArmyB_10 = 510, ArmyB_11 = 511, ArmyB_12 = 512,
	ArmyB_13 = 513, ArmyB_14 = 514,

	ArmyC_1 = 601,  ArmyC_2 = 602,  ArmyC_3 = 603,
	ArmyC_4 = 604,  ArmyC_5 = 605,  ArmyC_6 = 606,
	ArmyC_7 = 607,  ArmyC_8 = 608,  ArmyC_9 = 609,
	ArmyC_10 = 610, ArmyC_11 = 611, ArmyC_12 = 612,
	ArmyC_13 = 613, ArmyC_14 = 614,

	ArmyD_1 = 701,  ArmyD_2 = 702,  ArmyD_3 = 703,
	ArmyD_4 = 704,  ArmyD_5 = 705,  ArmyD_6 = 706,
	ArmyD_7 = 707,  ArmyD_8 = 708,  ArmyD_9 = 709,
	ArmyD_10 = 710, ArmyD_11 = 711, ArmyD_12 = 712,
	ArmyD_13 = 713, ArmyD_14 = 714,

	ArmyE_1 = 901,  ArmyE_2 = 902, ArmyE_3 = 903,
	ArmyE_4 = 904,  ArmyE_5 = 905, ArmyE_6 = 906,
	ArmyE_7 = 907,  ArmyE_8 = 908, ArmyE_9 = 909,
	ArmyE_10 = 910, ArmyE_11 = 911,

	armyTrapA_1 = 801, armyTrapA_2 = 802,
	armyTrapA_3 = 803, armyTrapA_4 = 804,
	armyTrapA_5 = 805, 

	armyTrapB_1 = 811, armyTrapB_2 = 812,
	armyTrapB_3 = 813, armyTrapB_4 = 814,
	armyTrapB_5 = 815, 

	armyTrapC_1 = 821, armyTrapC_2 = 822,
	armyTrapC_3 = 823, armyTrapC_4 = 824,
	armyTrapC_5 = 825

};


UENUM() enum class ECArmyType : uint8 {

	Army_NONE = 0,
	ArmyA = 1,
	ArmyB = 2,
	ArmyC = 3,
	ArmyD = 4,
	ArmyE = 5,
	ArmyTrap = 9
};


USTRUCT() struct FArmyCostRes {
	GENERATED_BODY()
	UPROPERTY() int32 Grain;
	UPROPERTY() int32 Lumber;
	UPROPERTY() int32 Iron;
	UPROPERTY() int32 Silver;
	UPROPERTY() int32 Crystal;

};


USTRUCT() struct FArmyUnitData {
	GENERATED_BODY()
	UPROPERTY() ECArmyID armyId;
	UPROPERTY() FString armyName;
	UPROPERTY() FString armyPic;
	UPROPERTY() FString armySmallPic;
	UPROPERTY() TArray<int32> skill;
	UPROPERTY() int32 modelType;
	UPROPERTY() FString armyDes;
	UPROPERTY() FString tip;
	UPROPERTY() int32 starchange;
};

USTRUCT() struct FCArmyUnit {
	GENERATED_BODY()
		
	UPROPERTY() int32 index;
	UPROPERTY() ECArmyID armyId;
	UPROPERTY() ECArmyType armyType;
	UPROPERTY() int32 armorType;
	UPROPERTY() int32 battleUnitType;
	UPROPERTY() ECBuildingID barrackID;
	UPROPERTY() int32 barrackLevel;
	UPROPERTY() int32 starchange;
	UPROPERTY() int32 starlv;
	UPROPERTY() int32 trainingTime;
	UPROPERTY() FArmyCostRes costRes;
	UPROPERTY() int32 attack;
	UPROPERTY() int32 defense;
	UPROPERTY() int32 life;
	UPROPERTY() float atkInterval;
	UPROPERTY() int32 atkDistance;
	UPROPERTY() int32 speed;
	UPROPERTY() int32 strike;
	UPROPERTY() int32 freeWeight;
	UPROPERTY() float costFood;
	UPROPERTY() int32 power;
	UPROPERTY() float trainPoint;
	UPROPERTY() float trigger;
	UPROPERTY() float build_Speed;
	UPROPERTY() int32 position;
	UPROPERTY() float kingWarScore;
	UPROPERTY() float UseElitePoint;
	UPROPERTY() FArmyUnitData ArmyData;
};

USTRUCT() struct FCArmyAData {
	GENERATED_BODY()
	UPROPERTY() FCArmyUnit armyA_1;
	UPROPERTY() FCArmyUnit armyA_2;
	UPROPERTY() FCArmyUnit armyA_3;
	UPROPERTY() FCArmyUnit armyA_4;
	UPROPERTY() FCArmyUnit armyA_5;
	UPROPERTY() FCArmyUnit armyA_6;
	UPROPERTY() FCArmyUnit armyA_7;
	UPROPERTY() FCArmyUnit armyA_8;
	UPROPERTY() FCArmyUnit armyA_9;
	UPROPERTY() FCArmyUnit armyA_10;
	UPROPERTY() FCArmyUnit armyA_11;
	UPROPERTY() FCArmyUnit armyA_12;
	UPROPERTY() FCArmyUnit armyA_13;
	UPROPERTY() FCArmyUnit armyA_14;
};


USTRUCT() struct FCArmyBData {
	GENERATED_BODY()
	UPROPERTY() FCArmyUnit armyB_1;
	UPROPERTY() FCArmyUnit armyB_2;
	UPROPERTY() FCArmyUnit armyB_3;
	UPROPERTY() FCArmyUnit armyB_4;
	UPROPERTY() FCArmyUnit armyB_5;
	UPROPERTY() FCArmyUnit armyB_6;
	UPROPERTY() FCArmyUnit armyB_7;
	UPROPERTY() FCArmyUnit armyB_8;
	UPROPERTY() FCArmyUnit armyB_9;
	UPROPERTY() FCArmyUnit armyB_10;
	UPROPERTY() FCArmyUnit armyB_11;
	UPROPERTY() FCArmyUnit armyB_12;
	UPROPERTY() FCArmyUnit armyB_13;
	UPROPERTY() FCArmyUnit armyB_14;
};

USTRUCT() struct FCArmyCData {
	GENERATED_BODY()
	UPROPERTY() FCArmyUnit armyC_1;
	UPROPERTY() FCArmyUnit armyC_2;
	UPROPERTY() FCArmyUnit armyC_3;
	UPROPERTY() FCArmyUnit armyC_4;
	UPROPERTY() FCArmyUnit armyC_5;
	UPROPERTY() FCArmyUnit armyC_6;
	UPROPERTY() FCArmyUnit armyC_7;
	UPROPERTY() FCArmyUnit armyC_8;
	UPROPERTY() FCArmyUnit armyC_9;
	UPROPERTY() FCArmyUnit armyC_10;
	UPROPERTY() FCArmyUnit armyC_11;
	UPROPERTY() FCArmyUnit armyC_12;
	UPROPERTY() FCArmyUnit armyC_13;
	UPROPERTY() FCArmyUnit armyC_14;
};

USTRUCT() struct FCArmyDData {
	GENERATED_BODY()
	UPROPERTY() FCArmyUnit armyD_1;
	UPROPERTY() FCArmyUnit armyD_2;
	UPROPERTY() FCArmyUnit armyD_3;
	UPROPERTY() FCArmyUnit armyD_4;
	UPROPERTY() FCArmyUnit armyD_5;
	UPROPERTY() FCArmyUnit armyD_6;
	UPROPERTY() FCArmyUnit armyD_7;
	UPROPERTY() FCArmyUnit armyD_8;
	UPROPERTY() FCArmyUnit armyD_9;
	UPROPERTY() FCArmyUnit armyD_10;
	UPROPERTY() FCArmyUnit armyD_11;
	UPROPERTY() FCArmyUnit armyD_12;
	UPROPERTY() FCArmyUnit armyD_13;
	UPROPERTY() FCArmyUnit armyD_14;
};

USTRUCT() struct FCArmyEData {
	GENERATED_BODY()
	UPROPERTY() FCArmyUnit armyE_1;
	UPROPERTY() FCArmyUnit armyE_2;
	UPROPERTY() FCArmyUnit armyE_3;
	UPROPERTY() FCArmyUnit armyE_4;
	UPROPERTY() FCArmyUnit armyE_5;
	UPROPERTY() FCArmyUnit armyE_6;
	UPROPERTY() FCArmyUnit armyE_7;
	UPROPERTY() FCArmyUnit armyE_8;
	UPROPERTY() FCArmyUnit armyE_9;
	UPROPERTY() FCArmyUnit armyE_10;
	UPROPERTY() FCArmyUnit armyE_11;
	UPROPERTY() FCArmyUnit armyE_12;
	UPROPERTY() FCArmyUnit armyE_13;
	UPROPERTY() FCArmyUnit armyE_14;
};


/**
 * 
 */
UCLASS()
class SULTAN_API USCArmy : public UObject
{
	GENERATED_BODY()

public: 
	 
	
};
