// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"
#include "PaperSprite.h"
#include "SWorldCoord.h"
#include "Components/TextRenderComponent.h"
#include "PaperSpriteComponent.h"
#include "SWorldUnitSprite.generated.h"



USTRUCT(BlueprintType)
struct FWorldUnitRaw {
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
	class ASWorldUnitSpriteCastle* UnitCastle;


};




UCLASS()
class SULTAN_API ASWorldUnitSprite : public AActor
{
	GENERATED_BODY()

private :
	class UPaperFlipbookComponent* Flipbook;
	
public:	
	// Sets default values for this actor's properties
	ASWorldUnitSprite();
	class UPaperFlipbookComponent* setFlipbook(class UPaperFlipbook* LFlipbook);
	FORCEINLINE class UPaperFlipbookComponent* getFlipbook() const { return Flipbook;}

	virtual void BeginPlay() override;

	static FHashTable WorldCastleSkins;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
