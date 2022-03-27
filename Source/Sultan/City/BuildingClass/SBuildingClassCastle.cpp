// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassCastle.h"


TMap<ECityCastleSkin, FBuildingCastleSkin> ASBuildingClassCastle::CastleSkins;
TMap<int32, FBuildingLvlDataCastle> ASBuildingClassCastle::LvlData;


ASBuildingClassCastle::ASBuildingClassCastle() {

	Comp = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ssssssssssssssssss"));
	Comp->SetupAttachment(RootComponent);
	OnClicked.AddUniqueDynamic(this, &ASBuildingClassCastle::Clicked);
	//OnClicked.AddUnique(this, &ASBuildingClassCastle::Clicked);
}

void ASBuildingClassCastle::setBuildingActionBtnList() {

}

void ASBuildingClassCastle::initCastleSkin() {


	UDataTable* DT_CastleSkin = LoadObject < UDataTable >(nullptr, TEXT("DataTable'/Game/City/CastleSkinOld.CastleSkinOld'"));
	static const FString ContextString(TEXT("Castle Skin"));
	//FBuildingCastleSkin* CastleSkin = DT_CastleSkin->GetAllRows<FBuildingCastleSkin>(ContextString, )


	TArray<FName> RowNames;
	RowNames = DT_CastleSkin->GetRowNames();

	for (auto& name : RowNames)
	{
		FBuildingCastleSkin* row = DT_CastleSkin->FindRow<FBuildingCastleSkin>(name, ContextString);
		if (row)
			ASBuildingClassCastle::CastleSkins.Add(row->indexSkin, *row);
	}

	GLog->Log(FString::Printf(TEXT("-------------------------------- Map Length %d"), ASBuildingClassCastle::CastleSkins.Num()));

}



void ASBuildingClassCastle::setSkin(ECityCastleSkin CSkin) {

	FBuildingCastleSkin* Skin = ASBuildingClassCastle::CastleSkins.Find(CSkin);

	if (!Skin)
		GLog->Log("------------------------------ Castle Skin Not Found");
	int8 firstIndex = -1;
	for (auto& SkinPart : Skin->Parts) {

		firstIndex++;

		if (firstIndex == 0) {
			Sprite->SetSprite(SkinPart.Sprite);
			Sprite->SetRelativeLocation(SkinPart.Pos);
			continue;
		}
		else if(firstIndex == 1) {
			
			Comp->SetRelativeLocation(SkinPart.Pos + FVector(35, 0, 77.5));
			Comp->SetSprite(SkinPart.Sprite);

			continue;
		}

		/**Comp->SetSprite(SkinPart.Sprite);
		Comp-> SetRelativeLocation(SkinPart.Pos);*/

		UPaperSpriteComponent* newPaperSprite = NewObject<UPaperSpriteComponent>(this, FName(SkinPart.idPart + "_" + FString::FromInt(firstIndex)));
		newPaperSprite->RegisterComponent();
		newPaperSprite->SetupAttachment(Sprite);
		newPaperSprite->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		newPaperSprite->SetRelativeLocation(SkinPart.Pos + FVector(35, 0, 77.5));
		newPaperSprite->SetSprite(SkinPart.Sprite);

		
		GLog->Log("------------------------------ SKin Added");

	}

}



void ASBuildingClassCastle::Clicked(AActor* Target, FKey ButtonPressed) {


	static int Index = 0;
	/*CLASSICAL = 1  UMETA(DisplayName = "CS CLASSICAL"),
	RAMADAN = 2  UMETA(DisplayName = "CS RAMADAN"),
	WARLV = 3  UMETA(DisplayName = "CS WARLV"),
	SUPERVIP = 4  UMETA(DisplayName = "CS SUPERVIP"),
	SECOND = 5  UMETA(DisplayName = "CS SECOND"),
	THREE = 6  UMETA(DisplayName = "CS THREE"),
	NEWRAMADAN = 7  UMETA(DisplayName = "CS NEWRAMADAN"),
	KOH2018RAMADAN = 8  UMETA(DisplayName = "CS KOH2018RAMADAN"),
	EGYPT = 9  UMETA(DisplayName = "CS EGYPT"),
	PANTHER = 10  UMETA(DisplayName = "CS PANTHER"),*/
	TArray<ECityCastleSkin> T = { 
		ECityCastleSkin::CLASSICAL,  ECityCastleSkin::RAMADAN,
		ECityCastleSkin::WARLV,  ECityCastleSkin::SECOND, 
		ECityCastleSkin::THREE,   ECityCastleSkin::NEWRAMADAN, 
		ECityCastleSkin::KOH2018RAMADAN, ECityCastleSkin::EGYPT,
		ECityCastleSkin::PANTHER, ECityCastleSkin::EGYPT,
	};
	

}

void ASBuildingClassCastle::initBuilding() {

}

void ASBuildingClassCastle::getLvlData(TSharedPtr<FJsonObject> JsonValue) {

	for (auto& T : JsonValue->Values) {

		int32 buildingLvl = FCString::Atoi(*T.Key);
		if (!T.Value || T.Value->IsNull())
			continue;

		FBuildingLvlDataCastle BuildingLvlData;

		FJsonObjectConverter::JsonObjectToUStruct(T.Value->AsObject().ToSharedRef(), &BuildingLvlData);
		LvlData.Add(buildingLvl, BuildingLvlData);
	}

}