// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "Engine/DataTable.h"
#include "SCityFloor.generated.h"



USTRUCT(BlueprintType)
struct FCityFloorPart : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 x;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 z;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 yaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 roll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSprite*  Sprite;
};

UCLASS()
class SULTAN_API ASCityFloor : public AActor
{
	GENERATED_BODY()
		
public:
	class UPaperSpriteComponent* Sprite;
	ASCityFloor();
	void setSprite(class UPaperSprite* Sprite);
	static UDataTable* CityFloorParts;
	
};
