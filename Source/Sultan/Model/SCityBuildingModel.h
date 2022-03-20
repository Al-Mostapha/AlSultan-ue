// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SBaseModel.h"
#include "../Config/SCBuilding.h"
#include "SCityBuildingModel.generated.h"

USTRUCT(BlueprintType)
struct FCityBuildingUnitDS {

	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 buildingLvl;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) ECBuildingType buildingType;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) bool  buildingLocked;

};


USTRUCT(BlueprintType)
struct FCityBuildingInnerDS {
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 idCity;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 idPlayer;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	castle;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	wall;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS wallGate;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	arrowTower;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	watchTower;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	merchant;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	leisureHouse;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	statue;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	petCenter;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	eventCenter;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	veteransHall;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_3;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_5;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_6;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_7;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_8;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_9;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_10;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_11;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_12;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	innerBuilding_13;

	FCityBuildingUnitDS getBuilding(FName BuildingPlace) {

		FCityBuildingUnitDS Out;
		Out.buildingLvl = -1;
		FProperty* prop = FCityBuildingInnerDS::StaticStruct()->FindPropertyByName(BuildingPlace);

		if (!prop)
			return Out;
		FStructProperty* idC = CastField<FStructProperty>(prop);
		if (!idC)
			return Out;


		FCityBuildingUnitDS* Add = prop->ContainerPtrToValuePtr<FCityBuildingUnitDS>(this);
		/**if (FCityBuildingUnitDS* TTTT = Cast<FCityBuildingUnitDS>(Add))
			return *TTTT;*/
		if (Add)
			return *Add;
		return Out;

	}

};


USTRUCT(BlueprintType)
struct FCityBuildingOuterDS {
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 idCity;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 idPlayer;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_3;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_5;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_6;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_7;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_8;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_9;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_10;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_11;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_12;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_13;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_14;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_15;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_16;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_17;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_18;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_19;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_20;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_21;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_22;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_23;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_24;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_25;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_26;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_27;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_28;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_29;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	resBuilding_30;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_1;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_3;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_5;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_6;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_7;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_8;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_9;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_10;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_11;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) FCityBuildingUnitDS	outerBuilding_12;

	FCityBuildingUnitDS getBuilding(FName BuildingPlace) {
		
		FCityBuildingUnitDS Out;
		Out.buildingLvl = -1;
		FProperty* prop = FCityBuildingOuterDS::StaticStruct()->FindPropertyByName(BuildingPlace);

		if (!prop)
			return Out;
		FStructProperty* idC = CastField<FStructProperty>(prop);
		if (!idC)
			return Out;


		FCityBuildingUnitDS* Add = prop->ContainerPtrToValuePtr<FCityBuildingUnitDS>(this);
		/**if (FCityBuildingUnitDS* TTTT = Cast<FCityBuildingUnitDS>(Add))
			return *TTTT;*/
		if (Add)
			return *Add;
		return Out;

	}


};



/**
 * 
 */
UCLASS()
class SULTAN_API USCityBuildingModel : public USBaseModel
{
	GENERATED_BODY()
	
};
