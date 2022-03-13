// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SBaseModel.h"
#include "SCityArmyModel.generated.h"



USTRUCT(BlueprintType)
struct FCityArmyDS {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 idPlayer;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 idCity;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyA_1; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyA_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyA_3; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyA_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyB_1; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyB_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyB_3; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyB_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyC_1; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyC_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyC_3; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyC_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyD_1; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyD_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyD_3; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyD_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyE_1; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyE_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyE_3; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyE_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyF_1; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyF_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyF_3; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 armyF_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapA_1; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapA_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapA_3; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapA_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapA_5;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapB_1; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapB_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapB_3; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapB_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapB_5;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapC_1; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapC_2;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapC_3; UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapC_4;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 trapC_5;

};


/**
 * 
 */
UCLASS()
class SULTAN_API USCityArmyModel : public USBaseModel
{
	GENERATED_BODY()
	
};
