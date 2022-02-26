// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnitClass/SWorldUnitSprite.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "Engine/DataTable.h"
#include "Components/TextRenderComponent.h"
#include "SWorldUnitSpriteCastle.generated.h"


#define WUT_CASTLE_SKIN_LVL1  1
#define WUT_CASTLE_SKIN_LVL2  2
#define WUT_CASTLE_SKIN_LVL3  3
#define WUT_CASTLE_SKIN_LVL4  4
#define WUT_CASTLE_SKIN_LVL5  5
#define WUT_CASTLE_SKIN_LVL6  6
#define WUT_CASTLE_SKIN_LVL7  7
#define WUT_CASTLE_SKIN_LVL8  8
#define WUT_CASTLE_SKIN_LVL9  9
#define WUT_CASTLE_SKIN_LVL10  10
#define WUT_CASTLE_SKIN_LVL11  11
#define WUT_CASTLE_SKIN_LVL12  12
#define WUT_CASTLE_SKIN_LVL13  13
#define WUT_CASTLE_SKIN_LVL14  14
#define WUT_CASTLE_SKIN_LVL15  15
#define WUT_CASTLE_SKIN_LVL16  16
#define WUT_CASTLE_SKIN_LVL17  17
#define WUT_CASTLE_SKIN_LVL18  18
#define WUT_CASTLE_SKIN_LVL19  19
#define WUT_CASTLE_SKIN_LVL20  20
#define WUT_CASTLE_SKIN_LVL21  21
#define WUT_CASTLE_SKIN_LVL22  22
#define WUT_CASTLE_SKIN_LVL23  23
#define WUT_CASTLE_SKIN_LVL24  24
#define WUT_CASTLE_SKIN_LVL25  25
#define WUT_CASTLE_SKIN_LVL26  26
#define WUT_CASTLE_SKIN_LVL27  27
#define WUT_CASTLE_SKIN_LVL28  28
#define WUT_CASTLE_SKIN_LVL29  29
#define WUT_CASTLE_SKIN_LVL30  30
#define WUT_CASTLE_SKIN_LVL31  31
#define WUT_CASTLE_SKIN_LVL32  32
#define WUT_CASTLE_SKIN_LVL33  33
#define WUT_CASTLE_SKIN_LVL34  34
#define WUT_CASTLE_SKIN_LVL35  35
#define WUT_CASTLE_SKIN_LVL36  36
#define WUT_CASTLE_SKIN_LVL37  37
#define WUT_CASTLE_SKIN_LVL38  38
#define WUT_CASTLE_SKIN_LVL39  39
#define WUT_CASTLE_SKIN_LVL40  40
#define WUT_CASTLE_SKIN_WAR_LVL1  50
#define WUT_CASTLE_SKIN_WAR_LVL2  51
#define WUT_CASTLE_SKIN_WAR_LVL3  52
#define WUT_CASTLE_SKIN_WAR_LVL4  53
#define WUT_CASTLE_SKIN_WAR_LVL5  54

/**
 * 
 */

USTRUCT(BlueprintType)
struct FWorldUnitCastle {
	GENERATED_BODY()

	uint16 xCoord;
	uint16 yCoord;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 lvl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 skin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 Warlvl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		uint8 AllianceSlog;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString CityName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString PlayerName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString AllianceName;
};





USTRUCT(BlueprintType)
struct FWorldUnitCastleSkin : public FTableRowBase{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSprite* CastleSkine;
};

USTRUCT(BlueprintType)
struct FWorldPlayerCastle : public FTableRowBase {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSprite* CastleBaseSkin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPaperSprite* CastleLvlSkin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector  CastleLvlSkinLocalOffset;
	FWorldPlayerCastle() : CastleBaseSkin(nullptr), CastleLvlSkin(nullptr)
	{}
	FWorldPlayerCastle(UPaperSprite* VCastleBaseSkin, UPaperSprite* VCastleLvlSkin) : CastleBaseSkin(VCastleBaseSkin), CastleLvlSkin(VCastleLvlSkin)
	{}
	/**FWorldPlayerUnSkinnedCastle(UPaperSprite* VCastleBaseSkin, UPaperSprite* VCastleLvlSkin) {
		CastleBaseSkin = VCastleBaseSkin;
		VCastleLvlSkin = VCastleLvlSkin;
	}*/
};




UCLASS()
class SULTAN_API ASWorldUnitSpriteCastle : public ASWorldUnitSprite
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperSpriteComponent* CastleNameBg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextRenderComponent* CastleName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperSpriteComponent* CastleLvlBg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextRenderComponent* CastleLvl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperSpriteComponent* AllianceSlog;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperSpriteComponent* WarLvl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperSpriteComponent* Sheild;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperSpriteComponent* CastleBaseSkin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UPaperSpriteComponent* CastleLvlSkin;
	int32 xCoord;
	int32 yCoord;
public:
	ASWorldUnitSpriteCastle();
	virtual void BeginPlay() override;
	static bool addWorldCastle(int32 xCoord, int32 yCoord, UWorld* World);
	static bool removeWorldCastle(int32 xCoord, int32 yCoord);
	static bool loadBaseCastle();
	static TMap<uint16, FWorldPlayerCastle> WorldBaseCastle;
};
