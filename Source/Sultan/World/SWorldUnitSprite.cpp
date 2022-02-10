// Fill out your copyright notice in the Description page of Project Settings.


#include "SWorldUnitSprite.h"

// Sets default values
ASWorldUnitSprite::ASWorldUnitSprite()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Flipbook = CreateDefaultSubobject<class UPaperFlipbookComponent>(TEXT("PaperSprite"));
	RootComponent = Flipbook;
	
	

}

// Called when the game starts or when spawned
void ASWorldUnitSprite::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ASWorldUnitSprite::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

