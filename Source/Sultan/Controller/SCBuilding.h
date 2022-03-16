// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "SCBuilding.generated.h"



UENUM()
enum class ECBuildingState : uint8 {
	NORMAL = 0,
	BUILDING = 1,
	UPGRADEING = 2,
	DEMOLISHING = 3,
	TRAINING = 4,
	TRAP_BUILDING = 5,
	TREATING = 6,
	STUDYING = 7
};

UENUM()
enum class ECBuildingOperate : uint8 {
	BUILD = 0,
	DEMOLISH = 1,
	UPGRADE = 2,
	EXCHANGE = 3,
	UNLOCK = 4
};

UENUM()
enum class ECBuildingCityPlace : uint8 {
	INNER = 0,
	OUTER = 1
};

UENUM()
enum class ECBuildingPlaceType : uint8 {
	FIXED = 0,
	NORMAL = 1,
	RESOURCE = 2
};


UENUM()
enum class ECBuildingType : uint8 {
	BUILDING_NONE = 0,
	CASTLE = 1,
	WALLS = 2,
	ARROW_TOWER = 3,
	WATCH_TOWER = 4,
	WARE_HOUSE = 5,
	EVENT_CENTER = 6,
	TRAVEL_MERCHANT = 7,
	HARBOR = 8,
	TROOP_DETAILS = 9,
	STATUE = 10,
	EMBASSY = 11,
	MARKET = 12,
	COLLEGE = 13,
	WISHING_WELL = 14,
	BLACK_SMITH = 15,
	STABLES = 16,
	RANGE = 17,
	BARRACKS = 18,
	WORKSHOP = 19,
	FORTRESS = 20,
	DRILL_GROUDS = 21,
	HALL_OF_WAR = 22,
	FARM = 50,
	SAWMILL = 51,
	IRON_MINE = 52,
	STEEL = 53,
	MILITARY_TENT = 54,
	HOSPITAL = 55,
	MATERIAL_WORKSHOP = 56,
	MIRACLE = 100,
	ELITE_PALACE = 120
};


USTRUCT(BlueprintType)
struct FBuildingData : public FTableRowBase {

	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString IL_Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString IL_Desc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ECBuildingType buildingType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ECBuildingPlaceType buildingPlaceType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ECBuildingCityPlace buildingCityPlace;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class ASCityBuilding> BuildingClass;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class UUserWidget> BuildingProg;

};

USTRUCT(BlueprintType)
struct FBuildingPos : public FTableRowBase {


	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString BuildingPlace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ECBuildingCityPlace BuildingCityPlace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ECBuildingPlaceType BuildingPlaceType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Vect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator Rot;
};

/**
 * 
 */
UCLASS()
class SULTAN_API USCBuilding : public UObject
{
	GENERATED_BODY()
public:
	static TArray<FBuildingPos> BuildingPos;
	static TMap<ECBuildingType, FBuildingData> BuildingData;
	static void initBuildingPos();
	static void initBuildingData();
};
