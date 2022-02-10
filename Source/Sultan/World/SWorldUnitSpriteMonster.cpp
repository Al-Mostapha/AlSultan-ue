// Fill out your copyright notice in the Description page of Project Settings.


#include "SWorldUnitSpriteMonster.h"
#include "../SGameMain.h"
#include "Engine/TextRenderActor.h"



ASWorldUnitSpriteMonster::ASWorldUnitSpriteMonster() {

	

	MonsterLvl = CreateDefaultSubobject<UTextRenderComponent>(TEXT("MonterLvl"));
	MonsterLvlBg = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("MonterLvlBg"));
	MonsterFlipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("MonterFlipbook"));
	RootComponent = MonsterFlipbook;
	

	MonsterLvl->SetTextRenderColor(FColor::White);
	MonsterLvl->SetText(FText::FromString(FString::Printf(TEXT("%d , %d"), 0, 0)));
	MonsterLvl->AddLocalRotation(FRotator(0, 90, 0), false );
	MonsterLvl->AddLocalOffset(FVector(50, 10, -192), false );
	MonsterLvl->SetTranslucentSortPriority(9);
	MonsterLvl->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MonsterLvlBg->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MonsterLvlBg->SetupAttachment(RootComponent);
	MonsterLvl->SetupAttachment(MonsterLvlBg);
	
}


void ASWorldUnitSpriteMonster::BeginPlay() {
	
	Super::BeginPlay();

	UDataTable* CastleSkins = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/WorldMap/DTWorldUnitMonsterFlipBook.DTWorldUnitMonsterFlipBook'"));
	static const FString ContextString(TEXT("Monster FlipBook"));
	FWorldUnitMonsterFlipbook* MonsterFlip = CastleSkins->FindRow<FWorldUnitMonsterFlipbook>(FName(TEXT("" + FString::FromInt(rand() % 15 + 1))), ContextString, true);
	if (!MonsterFlip) {
		PRINT_STRING(FString::Printf(TEXT("dsadsadsadsadsadsadsad")));
		return;
	}
	if(MonsterFlipbook)
		MonsterFlipbook->SetFlipbook(MonsterFlip->FlipbookIdle);
	MonsterFlipbook->SetPlayRate(0.5);
	/**
	MonsterLvlBg->SetSprite(LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/MainCity/icon_main_build_warlv.icon_main_build_warlv'")));
	MonsterLvlBg->AddLocalOffset(FVector(128, 10, -8));
	MonsterLvlBg->SetTranslucentSortPriority(10);
	MonsterLvl->SetText(FText::FromString("123"));
	MonsterLvl->SetTextRenderColor(FColor::White);
	MonsterLvl->SetTranslucentSortPriority(9);*/

}

void ASWorldUnitSpriteMonster::setMonsterLvl(int32 xCoord, int32 yCoord) {

	MonsterLvl->SetTextRenderColor(FColor::White);
	MonsterLvl->SetText(FText::FromString(FString::Printf(TEXT("%d , %d"), xCoord, yCoord)));
	
	//MonsterLvl->AddLocalRotation(FRotator(90, 0, 0));
	//MonsterLvl->AddLocalOffset(FVector(128, 10, 128));

}


bool ASWorldUnitSpriteMonster::addWorldMonster(int32 xCoord, int32 yCoord, UWorld* World) {

	int32 xReal = USWorldCoord::getRealCoordX(xCoord);
	int32 yReal = USWorldCoord::getRealCoordY(yCoord);

	FWorldAddedUnit& AddedUnit = USWorldCoord::WorldAddedUnit[xReal][yReal];

	if (AddedUnit.bAddedToWorld)
		return false;
	int32 WorldUnitType = AddedUnit.type;
	FVector Vect(USWorldCoord::getUnitPosX(xCoord, yCoord), 10, USWorldCoord::getUnitPosY(xCoord, yCoord));
	AddedUnit.UnitSprite = World->SpawnActor<ASWorldUnitSpriteMonster>(Vect, FRotator::ZeroRotator);
	AddedUnit.bAddedToWorld = true;
	return true;


}


bool ASWorldUnitSpriteMonster::removeWorldMonster(int32 xCoord, int32 yCoord) {

	int16 xReal = USWorldCoord::getRealCoordX(xCoord);
	int16 yReal = USWorldCoord::getRealCoordY(yCoord);

	FWorldAddedUnit& UnitInW = USWorldCoord::WorldAddedUnit[xReal][yReal];
	if (!UnitInW.bAddedToWorld)
		return false;
	ASWorldUnitSpriteMonster* Monster = Cast<ASWorldUnitSpriteMonster>(UnitInW.UnitSprite);
	if (Monster && !Monster->IsPendingKillPending())
		Monster->Destroy();
	UnitInW.bAddedToWorld = false;
	//ASWorldFloor::UnitsInTheWorld[xRealL][yRealL].UnitFloor = nullptr;
	static int32 count = 0;
	PRINT_STRING(FString::Printf(TEXT(" Removed Monster From sdfdsfdsfsdsdfdsfdsfsddsffsdfs")))
	return true;

}


void ASWorldUnitSpriteMonster::Destroy() {

	Super::Destroy();
	PRINT_STRING(FString::Printf(TEXT(" Removed Monster From")))
}