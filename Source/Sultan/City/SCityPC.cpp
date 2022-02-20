// Fill out your copyright notice in the Description page of Project Settings.


#include "SCityPC.h"
#include "../SGameMain.h"

ASCityPC::ASCityPC() {
	bEnableClickEvents = true;
	bEnableMouseOverEvents = true;
	bShowMouseCursor = true;
}




void ASCityPC::BeginPlay() {

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


void ASCityPC::SetupInputComponent() {

	Super::SetupInputComponent();
	InputComponent->BindAxis("LeftArrow", this, &ASCityPC::moveCameraLeft);
	InputComponent->BindAxis("RightArrow", this, &ASCityPC::moveCameraRight);
	InputComponent->BindAxis("DownArrow", this, &ASCityPC::moveCameraDown);
	InputComponent->BindAxis("UpArrow", this, &ASCityPC::moveCameraUp);
	InputComponent->BindAxis("Scroll", this, &ASCityPC::zoomCamera);


}


