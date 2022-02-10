// Fill out your copyright notice in the Description page of Project Settings.


#include "SCityPlayerCont.h"
#include "Engine/World.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "../SGameMain.h"

ASCityPlayerCont::ASCityPlayerCont() {
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bShowMouseCursor = true;
}




void ASCityPlayerCont::BeginPlay() {

	Super::BeginPlay();
	FVector cameraPos(0, 50, 0);
	FRotator CameraRotator(0, -90, 0);
	MainCamera = GetWorld()->SpawnActor<ACameraActor>(ACameraActor::StaticClass(), cameraPos, CameraRotator);
	MainCamera->GetCameraComponent()->bUsePawnControlRotation = false;
	MainCamera->GetCameraComponent()->SetProjectionMode(ECameraProjectionMode::Orthographic);
	MainCamera->GetCameraComponent()->SetMobility(EComponentMobility::Movable);
	MainCamera->GetCameraComponent()->SetHiddenInGame(false);
	MainCamera->GetCameraComponent()->SetOrthoWidth(1024);
	MainCamera->GetCameraComponent()->bConstrainAspectRatio = false;
	SetViewTarget(MainCamera);
	SetInputMode(FInputModeGameAndUI());

	
	

}


void ASCityPlayerCont::SetupInputComponent() {

	Super::SetupInputComponent();
	InputComponent->BindAxis("LeftArrow",  this, &ASCityPlayerCont::moveCameraLeft);
	InputComponent->BindAxis("RightArrow", this, &ASCityPlayerCont::moveCameraRight);
	InputComponent->BindAxis("DownArrow",  this, &ASCityPlayerCont::moveCameraDown);
	InputComponent->BindAxis("UpArrow",    this, &ASCityPlayerCont::moveCameraUp);
	InputComponent->BindAxis("Scroll",     this, &ASCityPlayerCont::zoomCamera);


}

