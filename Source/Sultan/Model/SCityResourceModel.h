// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SBaseModel.h"
#include "SCityResourceModel.generated.h"

USTRUCT(BlueprintType)
struct FCityResourceDS {



	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 idPlayer;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 idCity;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 coin; 
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 food; 
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 wood; 
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 silver; 
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 iron; 
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 crystal; 
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 coinIn; 
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 foodIn; 
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 woodIn;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 silverIn;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 ironIn;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 crystalIn;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 coinOut;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 foodOut;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 woodOut;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 silverOut;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 ironOut;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 crystalOut;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 coinCap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 foodCap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 woodCap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 silverCap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 ironCap;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) int32 crystalCap;
};

/**
 * 
 */
UCLASS()
class SULTAN_API USCityResourceModel : public USBaseModel
{
	GENERATED_BODY()
	
};
