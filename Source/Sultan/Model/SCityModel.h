// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SBaseModel.h"
#include "SCityBuildingModel.h"
#include "SCityResourceModel.h"
#include "SCityArmyModel.h"
#include "SCityModel.generated.h"


USTRUCT(BlueprintType)
struct FCityDS {

	GENERATED_BODY()	
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32                idCity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) int32                idPlayer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FCityResourceDS      Resource;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FCityArmyDS          Army;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FCityBuildingInnerDS BuildingInner;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FCityBuildingOuterDS BuildingOuter;

	int32 getProp(FName PropName) {
		UStruct* _struct = FCityDS::StaticStruct();
		FProperty* prop = _struct->FindPropertyByName(FName("idCity"));
		if (!prop)
			return -1;
		FIntProperty* idC = CastField<FIntProperty>(prop);

		if (!idC)
			return -1;

		/**TSharedPtr<FJsonObject> AMyActor::BlueprintStructToJsonAttributes(FProperty * Property, const void* Value)
		{
			if (FStructProperty* StructProperty = CastField<FStructProperty>(Property))
			{
				TSharedPtr<FJsonObject> Out = MakeShared<FJsonObject>();
				if (FJsonObjectConverter::UStructToJsonAttributes(StructProperty->Struct, Value, Out->Values))
				{
					return Out;
				}
			}
			return nullptr;
		}*/
		//FStructProperty* = Cast<FStructProperty>();
		//FJsonObjectConverter::UStructToJsonAttributes;
		int32* Add = prop->ContainerPtrToValuePtr<int32>(this);
		if(Add)
			return *Add;
		return -1;
	}
};


/**
 * 
 */
UCLASS()
class SULTAN_API USCityModel : public USBaseModel
{
	GENERATED_BODY()
	USCityModel();
	
};
