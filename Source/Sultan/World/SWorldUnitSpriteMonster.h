// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnitClass/SWorldUnitSprite.h"
#include "Engine/DataTable.h"
#include "SWorldUnitSpriteMonster.generated.h"

USTRUCT(BlueprintType)
struct FWorldUnitMonsterFlipbook : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 skin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* FlipbookIdle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* FlipbookAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperFlipbook* FlipbookDie;
};

/**
 * 
 */
UCLASS()
class SULTAN_API ASWorldUnitSpriteMonster : public ASWorldUnitSprite
{
	GENERATED_BODY()
public:
	ASWorldUnitSpriteMonster();
	UPROPERTY(VisibleInstanceOnly)
	class UTextRenderComponent* MonsterLvl;
	class UPaperSpriteComponent* MonsterLvlBg;
	class UPaperFlipbookComponent* MonsterFlipbook;
	void setMonsterLvl(int32 xCoord, int32 yCoord);
	static bool addWorldMonster(int32 xCoord, int32 yCoord, UWorld* World);
	static bool removeWorldMonster(int32 xCoord, int32 yCoord);

protected:
	virtual void BeginPlay() override;
	virtual void Destroy();

	
};
