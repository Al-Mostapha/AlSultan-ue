// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "City/BuildingClass/SBuildingClassBarrack.h"
#include "City/BuildingClass/SBuildingClassBlackSmith.h"
#include "City/BuildingClass/SBuildingClassCastle.h"
#include "City/BuildingClass/SBuildingClassDrill.h"
#include "City/BuildingClass/SBuildingClassEmbassy.h"
#include "City/BuildingClass/SBuildingClassFortress.h"
#include "City/BuildingClass/SBuildingClassHallOfWar.h"
#include "City/BuildingClass/SBuildingClassHarbor.h"
#include "City/BuildingClass/SBuildingClassInstitute.h"
#include "City/BuildingClass/SBuildingClassLeisureHouse.h"
#include "City/BuildingClass/SBuildingClassMarket.h"
#include "City/BuildingClass/SBuildingClassOFarm.h"
#include "City/BuildingClass/SBuildingClassOIronMine.h"
#include "City/BuildingClass/SBuildingClassOMatWorkshop.h"
#include "City/BuildingClass/SBuildingClassOMiliTent.h"
#include "City/BuildingClass/SBuildingClassOSawMill.h"
#include "City/BuildingClass/SBuildingClassOSteel.h"
#include "City/BuildingClass/SBuildingClassStable.h"
#include "City/BuildingClass/SBuildingClassStatue.h"
#include "City/BuildingClass/SBuildingClassTargetRange.h"
#include "City/BuildingClass/SBuildingClassTravelMerchant.h"
#include "City/BuildingClass/SBuildingClassTreasurePool.h"
#include "City/BuildingClass/SBuildingClassTroopsDetail.h"
#include "City/BuildingClass/SBuildingClassVeteransHall.h"
#include "City/BuildingClass/SBuildingClassWall.h"
#include "City/BuildingClass/SBuildingClassWarehouse.h"
#include "City/BuildingClass/SBuildingClassWatchTower.h"
#include "City/BuildingClass/SBuildingClassWorkshop.h"
#include "Network/SNetBase.h"
#include "SGameBoot.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API USGameBoot : public UGameInstance
{
	GENERATED_BODY()
public:
	USGameBoot();
	static void getBuildingLvlData();
	
};
