// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Math/UnrealMathUtility.h"
#include "../SGameMain.h"
#include "SWorldCoord.generated.h"


#define S_WORLD_UNIT_WIDTH  256
#define S_WORLD_UNIT_HEIGHT  256

USTRUCT (BlueprintType)
struct FWorldAddedUnit {
	GENERATED_BODY()

	int16 xCoord;
	int16 yCoord;
	uint8 type;
	uint8 skin;
	class ASWorldUnitSprite* UnitSprite;
	bool bAddedToWorld;

};

/**
 * 
 */
UCLASS()
class SULTAN_API USWorldCoord : public UObject
{
	GENERATED_BODY()
public:
	static int32 getRealCoordX(int32 xCoord);
	static int32 getRealCoordY(int32 yCoord);
	static FWorldAddedUnit WorldAddedUnit[1200][1200];
	static void getUnitPos(int32 xCoord, int32 yCoord, FVector& Vect);
	static int32 getUnitPosX(int32 xCoord, int32 yCoord);
	static int32 getUnitPosY(int32 xCoord, int32 yCoord);
	static int32 getUnitXCoordFromPos(int32 xPixle, int32 yPixle);
	static int32 getUnitYCoordFromPos(int32 xPixle, int32 yPixle);
/**	static InWorldCastle;
	static InWorldMonster;*/
	
};
