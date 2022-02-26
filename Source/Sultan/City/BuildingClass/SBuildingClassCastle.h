// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SCityBuilding.h"
#include "SBuildingClassCastle.generated.h"


UENUM(BlueprintType)
enum class ECityCastleSkin : uint8 {
	NOSKIN = 0  UMETA(DisplayName = "CS NOSKIN"),
	CLASSICAL = 1  UMETA(DisplayName = "CS CLASSICAL"),
	RAMADAN = 2  UMETA(DisplayName = "CS RAMADAN"),
	WARLV = 3  UMETA(DisplayName = "CS WARLV"),
	SUPERVIP = 4  UMETA(DisplayName = "CS SUPERVIP"),
	SECOND = 5  UMETA(DisplayName = "CS SECOND"),
	THREE = 6  UMETA(DisplayName = "CS THREE"),
	NEWRAMADAN = 7  UMETA(DisplayName = "CS NEWRAMADAN"),
	KOH2018RAMADAN = 8  UMETA(DisplayName = "CS KOH2018RAMADAN"),
	EGYPT = 9  UMETA(DisplayName = "CS EGYPT"),
	PANTHER = 10  UMETA(DisplayName = "CS PANTHER"),
	ICESNOW = 11  UMETA(DisplayName = "CS ICESNOW"),
	NIGHTDX = 12  UMETA(DisplayName = "CS NIGHTDX"),
	CRAZYSTAR = 13  UMETA(DisplayName = "CS CRAZYSTAR"),
	EXQUISITE = 14  UMETA(DisplayName = "CS EXQUISITE"),
	STREAM = 15  UMETA(DisplayName = "CS STREAM"),
	OASIS = 16  UMETA(DisplayName = "CS OASIS"),
	WORLDCUP = 17  UMETA(DisplayName = "CS WORLDCUP"),
	WATCH = 18  UMETA(DisplayName = "CS WATCH"),
	VALENTINE = 19  UMETA(DisplayName = "CS VALENTINE"),
	KINGCOBRA = 20  UMETA(DisplayName = "CS KINGCOBRA"),
	FORT = 21  UMETA(DisplayName = "CS FORT"),
	CORBAN = 22  UMETA(DisplayName = "CS CORBAN"),
	CHRISTMAS = 23  UMETA(DisplayName = "CS CHRISTMAS"),
	HALLOWEEN = 24  UMETA(DisplayName = "CS HALLOWEEN"),
	CHRISTMAS2018 = 25  UMETA(DisplayName = "CS CHRISTMAS2018"),
	HALLOWEEN2018 = 26  UMETA(DisplayName = "CS HALLOWEEN2018"),
	NEWYEAR = 27  UMETA(DisplayName = "CS NEWYEAR"),
	KOH2019RAMADAN = 28  UMETA(DisplayName = "CS KOH2019RAMADAN"),
	HEGEMON = 29  UMETA(DisplayName = "CS HEGEMON"),
	LEGENDARY = 30  UMETA(DisplayName = "CS LEGENDARY"),
	EASTER = 31  UMETA(DisplayName = "CS EASTER"),
	FOURTH = 32  UMETA(DisplayName = "CS FOURTH"),
	SMAILWIND = 33  UMETA(DisplayName = "CS SMAILWIND"),
	WARRIOR = 34  UMETA(DisplayName = "CS WARRIOR"),
	SCORPION = 35  UMETA(DisplayName = "CS SCORPION"),
	DEGULA = 36  UMETA(DisplayName = "CS DEGULA"),
	YIJICB = 37  UMETA(DisplayName = "CS YIJICB"),
	REDGEM = 38  UMETA(DisplayName = "CS REDGEM"),
	KINGLION = 39  UMETA(DisplayName = "CS KINGLION"),
	SKYGUARD = 40  UMETA(DisplayName = "CS SKYGUARD"),
	KOH2020RAMADAN = 41  UMETA(DisplayName = "CS KOH2020RAMADAN"),
	CORBAN2020 = 42  UMETA(DisplayName = "CS CORBAN2020"),
	FIFTH = 43  UMETA(DisplayName = "CS FIFTH"),
	CONSTRUCTED = 44  UMETA(DisplayName = "CS CONSTRUCTED"),
	GOLDENCITY = 45  UMETA(DisplayName = "CS GOLDENCITY"),
	SOARCASTLE = 46  UMETA(DisplayName = "CS SOARCASTLE"),
	ICECASTLE = 47  UMETA(DisplayName = "CS ICECASTLE"),
	KOH2021RAMADAN = 48  UMETA(DisplayName = "CS KOH2021RAMADAN"),
	KING = 49  UMETA(DisplayName = "CS KING"),
	SKYGARDEN = 50  UMETA(DisplayName = "CS SKYGARDEN"),
	THUNDERCLOUD = 51  UMETA(DisplayName = "CS THUNDERCLOUD"),
	CORBAN2021 = 52  UMETA(DisplayName = "CS CORBAN2021"),
	HOURGLASS = 53  UMETA(DisplayName = "CS HOURGLASS"),
	ICEWOLF = 54 UMETA(DisplayName = "CS ICEWOLF")
};

USTRUCT(BlueprintType)
struct FBuildingCastleSkinPart : public FTableRowBase {


	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString idPart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Pos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator Rot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperSprite* Sprite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPaperFlipbook* Flipbook;
};



USTRUCT(BlueprintType)
struct FBuildingCastleSkin : public FTableRowBase {


	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString idSkin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECityCastleSkin indexSkin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBuildingCastleSkinPart> Parts;
};



/**
 * 
 */
UCLASS()
class SULTAN_API ASBuildingClassCastle : public ASCityBuilding
{
	GENERATED_BODY()
public:
	static TMap<ECityCastleSkin, FBuildingCastleSkin> CastleSkins;
	UPaperSpriteComponent* Comp;
	ASBuildingClassCastle();
	static void initCastleSkin();
	void setSkin(ECityCastleSkin CSkin);
	void setBuildingActionBtnList() override;

	UFUNCTION()
	void Clicked(AActor* Target, FKey ButtonPressed);
};
