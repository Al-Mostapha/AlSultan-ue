// Fill out your copyright notice in the Description page of Project Settings.


#include "SWorldGM.h"
#include "SWorldPlayerCont.h"
#include "SWorldFloor.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"

ASWorldGM::ASWorldGM(){
	PlayerControllerClass = ASWorldPlayerCont::StaticClass();
}

void ASWorldGM::StartPlay() {

	Super::StartPlay();

     /*UPaperSprite* WorldFloorSand = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/WorldMap/WorldFloor/WorldFloor_Sprite_2.WorldFloor_Sprite_2'"));
     UPaperSprite* WorldFloorGrass = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/WorldMap/WorldFloor/WorldFloor_Sprite_0.WorldFloor_Sprite_0'"));
     UPaperSprite* WorldFloorRock  = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/WorldMap/WorldFloor/WorldFloor_Sprite_1.WorldFloor_Sprite_1'"));
     UPaperSprite* WorldFloorLava  = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/WorldMap/WorldFloor/WorldFloor_Sprite_3.WorldFloor_Sprite_3'"));

	 ASWorldFloor* UnitFloor;

	for (int iii = 0; iii < 3; iii += 4) {
		for (int ii = 0; ii < 3; ii += 4) {
			
			FVector Vect(iii*256, 0, ii*256);
			FRotator Rot(0, 0, 0);
			UnitFloor = GetWorld()->SpawnActor<ASWorldFloor>(ASWorldFloor::StaticClass(), Vect, Rot);
			switch (ASWorldFloor::WorldFloorBaseSkin[iii][ii]) {

			case 1: 
				UnitFloor->Sprite->SetSprite(WorldFloorSand);
				break;
			case 2: 
				UnitFloor->Sprite->SetSprite(WorldFloorGrass);
				break;
			case 3: 
				UnitFloor->Sprite->SetSprite(WorldFloorRock);
				break;
			case 4: 
				UnitFloor->Sprite->SetSprite(WorldFloorLava);
				break;

			}
			
			
		}
	
	}*/


}