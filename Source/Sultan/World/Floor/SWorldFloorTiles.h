// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "SWorldFloorTiles.generated.h"





USTRUCT(BlueprintType)
struct FWorldFloorTile : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 floor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 layer_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 layer_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 water;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 land;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 mapObjet_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 mapObjet_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 mapObjet_3;


	/**FWorldFloorTile() : floor(0), layer_1(0), layer_2(0), water(0)
	{}
	FWorldFloorTile(uint32 MaskedBits)
		: floor((MaskedBits & 0x000000ff) >> 0),
		layer_1((MaskedBits & 0x0000ff00) >> 8),
		layer_2((MaskedBits & 0x00ff0000) >> 16),
		water((MaskedBits & 0xff000000) >> 24)
	{}*/
};





union FWorldUnitTileType {
	uint64 Unit;
	struct {
		uint8 Land, Layer0, Layer1, Layer2, Layer3, Layer4, Layer5, Layer6 ;
	};
	

};



USTRUCT(BlueprintType)
struct FWorldTiledMap {
	GENERATED_BODY()
	TArray<FWorldUnitTileType> MapTile;
	int32 MapWidth;
	int32 MapHeight;
	TArray<FWorldFloorTileSprite> SpriteList;
	class UDataTable* TileSetDT;

};

USTRUCT(BlueprintType)
struct FWorldFloorTileSprite : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 index;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSprite* Sprite;
	/**FWorldFloorTile() : floor(0), layer_1(0), layer_2(0), water(0)
	{}
	FWorldFloorTile(uint32 MaskedBits)
		: floor((MaskedBits & 0x000000ff) >> 0),
		layer_1((MaskedBits & 0x0000ff00) >> 8),
		layer_2((MaskedBits & 0x00ff0000) >> 16),
		water((MaskedBits & 0xff000000) >> 24)
	{}*/
};

UCLASS()
class SULTAN_API USWorldFloorTiles : public UObject
{
	GENERATED_BODY()
public:

	static TMap<FString, FWorldTiledMap> AllWorldMaps;
	static void DecompressWorldLayers();
	static void loadFileAndDecompress();
	static FString LoadFile(FString FileName);
	static void SaveFile(FString FileCont);
};
