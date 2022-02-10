// Fill out your copyright notice in the Description page of Project Settings.


#include "SWorldUnitSpriteCastle.h"
#include "../SGameMain.h"
#include "Containers/Map.h"



TMap<uint16, FWorldPlayerCastle> ASWorldUnitSpriteCastle::WorldBaseCastle;



ASWorldUnitSpriteCastle::ASWorldUnitSpriteCastle()
{

	SetActorEnableCollision(false);
	CastleBaseSkin = CreateDefaultSubobject<class UPaperSpriteComponent>(TEXT("CastleBaseSkin"));
	RootComponent = CastleBaseSkin;
	CastleLvlSkin = CreateDefaultSubobject<class UPaperSpriteComponent>(TEXT("CitySkin"));
	CastleLvlSkin->SetupAttachment(RootComponent);
	
	CastleNameBg = CreateDefaultSubobject<class UPaperSpriteComponent>(TEXT("CastleNameBg"));
	CastleNameBg->SetupAttachment(RootComponent);
	CastleNameBg->SetRelativeLocation(FVector(0, 11, 140), false);
	CastleName = CreateDefaultSubobject<class UTextRenderComponent>(TEXT("CastleName"));
	CastleName->SetupAttachment(RootComponent);
	CastleName->SetText(FText::FromString("Sultan Name"));
	CastleName->SetTextRenderColor(FColor::White);
	CastleName->AddLocalRotation(FRotator(0, 90, 0), false);
	CastleName->SetRelativeLocation(FVector(0, 11, 120), false);
	CastleName->SetWorldSize(16.0);
	CastleName->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);

	CastleLvlBg = CreateDefaultSubobject<class UPaperSpriteComponent>(TEXT("CastleLvlBg"));
	CastleLvlBg->SetupAttachment(RootComponent);
	CastleLvl = CreateDefaultSubobject<class UTextRenderComponent>(TEXT("CastleLvl"));
	CastleLvl->SetupAttachment(RootComponent);
	CastleLvlBg->AddLocalOffset(FVector(64, 10, 128));
	CastleLvlBg->SetTranslucentSortPriority(10);
	CastleLvl->SetText(FText::FromString("12xczc3"));
	CastleLvl->SetTextRenderColor(FColor::White);
	CastleLvl->SetTranslucentSortPriority(9);
	CastleLvl->AddLocalRotation(FRotator(0, 90, 20), false);
	CastleLvl->SetRelativeLocation(FVector(80, 11, 150), false);
	CastleLvl->SetWorldSize(16.0);

	AllianceSlog = CreateDefaultSubobject<class UPaperSpriteComponent>(TEXT("AllianceSlog"));
	AllianceSlog->SetupAttachment(RootComponent);
	AllianceSlog->SetWorldScale3D(FVector(1, 1, 1)*0.25);
	AllianceSlog->SetRelativeLocation(FVector(-128, 45, 128 + 64 + 16));
	WarLvl = CreateDefaultSubobject<class UPaperSpriteComponent>(TEXT("WarLvl"));
	WarLvl->SetupAttachment(RootComponent);
	Sheild = CreateDefaultSubobject<class UPaperSpriteComponent>(TEXT("Sheild"));
	Sheild->SetupAttachment(RootComponent);
	

	
}


bool ASWorldUnitSpriteCastle::loadBaseCastle() {

	
	UDataTable* CastleSkins = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/WorldMap/WorldMapCastle/DataTable/DT_WorldPlayerCastle.DT_WorldPlayerCastle'"));
	TArray<FWorldPlayerCastle*> AllCastle;
	static const FString ContextString(TEXT("Player Attack Montage"));
	CastleSkins->GetAllRows<FWorldPlayerCastle>(ContextString, AllCastle);
	int32 Index = 1;
	for (auto OneCarle : AllCastle) {
		ASWorldUnitSpriteCastle::WorldBaseCastle.Add(Index, *OneCarle);
		Index++;
	}
	

	return true;

};

// Called when the game starts or when spawned
void ASWorldUnitSpriteCastle::BeginPlay()
{
	Super::BeginPlay();

	static int Start = 0;
	FWorldPlayerCastle* Castle = WorldBaseCastle.Find(rand()% WorldBaseCastle.Num() + 1);
	if (!Castle)
		return;
	CastleBaseSkin->SetSprite(Castle->CastleBaseSkin);
	CastleLvlSkin->SetSprite(Castle->CastleLvlSkin);
	CastleLvl->SetText(FText::FromString(FString::Printf(TEXT("%d , %d"), xCoord, yCoord)));
	CastleLvlBg->SetSprite(LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/MainCity/icon_main_build_warlv.icon_main_build_warlv'")));
	CastleNameBg->SetSprite(LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/WorldMap/WorldMapCastle/CastleEffect/frame_allianceWar_seasion.frame_allianceWar_seasion'")));
	AllianceSlog->SetSprite(LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/Alliance/AllianceFlag/Frames/Allianceflag_001.Allianceflag_001'")));
	


}

bool ASWorldUnitSpriteCastle::addWorldCastle(int32 xCoord, int32 yCoord, UWorld* World) {

	int32 xReal = USWorldCoord::getRealCoordX(xCoord);
	int32 yReal = USWorldCoord::getRealCoordY(yCoord);
	FWorldAddedUnit* UnitInWorld = &USWorldCoord::WorldAddedUnit[xReal][yReal];
	if (UnitInWorld->bAddedToWorld)
		return false;
	int32 WorldUnitType = UnitInWorld->type;
	FVector Vect(USWorldCoord::getUnitPosX(xCoord, yCoord), 0, USWorldCoord::getUnitPosY(xCoord, yCoord) - 256);
	FRotator Rot(0, 0, 0);

	ASWorldUnitSpriteCastle* Temp = World->SpawnActor<ASWorldUnitSpriteCastle>(ASWorldUnitSpriteCastle::StaticClass(), Vect, Rot);

	Temp->xCoord = xCoord;
	Temp->yCoord = yCoord;
	UnitInWorld->UnitSprite = Temp;
	
	UnitInWorld->bAddedToWorld = true;
	return true;
}

bool ASWorldUnitSpriteCastle::removeWorldCastle(int32 xCoord, int32 yCoord) {

	int16 xReal = USWorldCoord::getRealCoordX(xCoord);
	int16 yReal = USWorldCoord::getRealCoordY(yCoord);

	FWorldAddedUnit& UnitInW = USWorldCoord::WorldAddedUnit[xReal][yReal];
	if (!UnitInW.bAddedToWorld)
		return false;
	if (!UnitInW.UnitSprite)
		return false;
	if (!UnitInW.UnitSprite->IsPendingKillPending())
		UnitInW.UnitSprite->Destroy();
	UnitInW.bAddedToWorld = false;
	//ASWorldFloor::UnitsInTheWorld[xRealL][yRealL].UnitFloor = nullptr;
	static int32 count = 0;
	PRINT_STRING(FString::Printf(TEXT(" Removed Castle From %d %d"), xCoord, yCoord))
		return true;	
}
