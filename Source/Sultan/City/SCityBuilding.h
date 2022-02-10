// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "Building/SBuildingNameComp.h"
#include "Building/SBuildingLvlComp.h"
#include "Building/SBuildingNotifComp.h"
#include "Building/SBuildingProgComp.h"
#include "Building/SBuildingBtnComp.h"
#include "Components/WidgetComponent.h"

#include "SCityBuilding.generated.h"


USTRUCT(BlueprintType)
struct FCityBuildingPos : public FTableRowBase {


	GENERATED_BODY()
public: 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BuildingPlace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Vect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator Rot;
};


USTRUCT(BlueprintType)
struct FCityFixedBuildingPosAndSp: public FTableRowBase {


	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString BuildingPlace;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Vect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator Rot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSprite* Sprite;
};



USTRUCT(BlueprintType)
struct FCityBuildingData : public FTableRowBase {

	GENERATED_BODY()
public :
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Title;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Desc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UPaperSprite* FloorSprite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Offset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture* Icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture* OverIcon;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class ASCityBuilding> BuildingClass;
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<class UUserWidget> BuildingProg;

};
/**
 * 
 */
UCLASS()
class SULTAN_API ASCityBuilding : public APawn
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UPaperSpriteComponent* Sprite;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingNameComp* BuildingName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingLvlComp* BuildingLvl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingNotifComp* BuildingNotif;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingProgComp* BuildingProgress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingBtnComp* WidgitComp;

	ASCityBuilding();
	void setSprite(class UPaperSprite* Sprite);
	static UDataTable* CityBuildingPos;
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	void DragX(float Val);
	void DragY(float Val);
	UFUNCTION()
	void Click();
	UFUNCTION()
	void OnSelected(UPrimitiveComponent* Target, FKey ButtonPressed);


};
