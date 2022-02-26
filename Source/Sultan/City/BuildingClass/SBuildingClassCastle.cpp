// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassCastle.h"


TMap<ECityCastleSkin, FBuildingCastleSkin> ASBuildingClassCastle::CastleSkins;



ASBuildingClassCastle::ASBuildingClassCastle() {

	Comp = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("ssssssssssssssssss"));
	Comp->SetupAttachment(RootComponent);
	OnClicked.AddUniqueDynamic(this, &ASBuildingClassCastle::Clicked);
	//OnClicked.AddUnique(this, &ASBuildingClassCastle::Clicked);
}

void ASBuildingClassCastle::setBuildingActionBtnList() {

}

void ASBuildingClassCastle::initCastleSkin() {


	UDataTable* DT_CastleSkin = LoadObject < UDataTable >(nullptr, TEXT("DataTable'/Game/City/CastleSkin.CastleSkin'"));
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
			//	setSprite();
			Sprite->SetSprite(SkinPart.Sprite);
			GLog->Log("------------------------------ SKin Added ----------------- " + SkinPart.Sprite->GetPathName());
			continue;
		}

		/**Comp->SetSprite(SkinPart.Sprite);
		Comp-> SetRelativeLocation(SkinPart.Pos);*/

		UPaperSpriteComponent* newPaperSprite = NewObject<UPaperSpriteComponent>(this, FName(SkinPart.idPart + "_" + FString::FromInt(firstIndex)));
		newPaperSprite->RegisterComponent();
		newPaperSprite->SetupAttachment(Sprite);
		newPaperSprite->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		newPaperSprite->SetRelativeLocation(SkinPart.Pos);
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
	ECityCastleSkin NewTile = T[Index++%9];
	this->setSkin(NewTile);
	GLog->Log("---------------------------------------------" + FString::FromInt(Index++));

}