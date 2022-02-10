// Fill out your copyright notice in the Description page of Project Settings.


#include "SCityFloor.h"
#include "UObject/NoExportTypes.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

UDataTable* ASCityFloor::CityFloorParts = NULL;

ASCityFloor::ASCityFloor() {

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("PaperSprite"));
	RootComponent = Sprite;

}


void ASCityFloor::setSprite(class UPaperSprite* PSprite) {

	Sprite->SetSprite(PSprite);

}