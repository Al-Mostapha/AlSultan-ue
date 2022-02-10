// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "UObject/NoExportTypes.h"
#include "PaperSprite.h"
#include "../SGameMain.h" 
#include "Floor/SWorldFloorTiles.h"
#include "SWorldFloor.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FUnitsInTheWorld {
	GENERATED_BODY()
		uint16 xCoord;
		uint16 yCoord;
		uint16 type;
		uint16 skin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ASWorldFloor* UnitFloor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperSprite* UnitDecore;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperSprite* UnitSprite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bInWorld;

};

UCLASS()
class SULTAN_API ASWorldFloor : public AActor
{
	GENERATED_BODY()
public:
	static uint8 WorldFloorBaseSkin[WORLD_WIDTH_IN_UNIT][WORLD_HEIGHT_IN_UNIT];
	static FUnitsInTheWorld UnitsInTheWorld[WORLD_WIDTH_IN_UNIT][WORLD_HEIGHT_IN_UNIT];
	static FWorldTiledMap CurrentWorldMap;
	ASWorldFloor();
	virtual void BeginPlay();
	static bool setWorldFloor(int32 xCoord, int32 yCoord, UWorld* WorldLvl);
	static bool addWorldFloor(int32 xCoord, int32 yCoord, UWorld* WorldLvl);
	void Clicked(AActor* TouchedActor, FKey ButtonPressed);
	void NotifyActorOnClicked(FKey ButtonPressed = EKeys::LeftMouseButton) override;
	bool addWorldFloorLayers(FWorldUnitTileType& WorldFloorType);
	static void destroyWorldFloor(int32 xCoord, int32 yCoord);
	class UPaperSpriteComponent* Floor;
	class UPaperSpriteComponent* Layer_1;
	class UPaperSpriteComponent* Layer_2;
	class UPaperSpriteComponent* Water;
	int32 xReal;
	int32 yReal;
	FUnitsInTheWorld* UnitInWorld;
	virtual void Destroy();
	
};
