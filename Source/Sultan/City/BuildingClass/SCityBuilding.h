// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataTable.h"
#include "../../Base/SBase.h"
#include "../Building/SBuildingNameComp.h"
#include "../Building/SBuildingTitleComp.h"
#include "../Building/SBuildingLvlComp.h"
#include "../Building/SBuildingNotifComp.h"
#include "../Building/SBuildingProgComp.h"
#include "../Building/SBuildingBtnComp.h"
#include "../Building/SBuildingActionBtnsComp.h"
#include "../BuildingWid/SBuildingActionBtnsWid.h"
#include "Components/WidgetComponent.h"
#include "PaperFlipbookComponent.h"
#include "PaperFlipbook.h"

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
	USBuildingTitleComp* BuildingTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingLvlComp* BuildingLvl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingNotifComp* BuildingNotif;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingProgComp* BuildingProgress;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingBtnComp* WidgitComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USBuildingActionBtnsComp* ActionBtnWid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FBuildingActionBtn> BtnActionList;
	TMap<EBuildingBtnAction, USBuildingActionBtnsComp*> BtnListComp;
	UWidgetComponent* BtnActionPanelBg;

	FString CoolingIcon;
	FString IL_CoolingTitle;
	FString BuildingPlace;

	ASCityBuilding();
	void setSprite(class UPaperSprite* Sprite);
	static UDataTable* CityBuildingPos;
	UFUNCTION()
		void OnSelected(UPrimitiveComponent* Target, FKey ButtonPressed);


	void addActionBtnComp();
	virtual void initBuilding();
	virtual void setBuildingActionBtnList();


};
