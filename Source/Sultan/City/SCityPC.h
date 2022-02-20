// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "SCityPC.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API ASCityPC : public APlayerController
{
	GENERATED_BODY()
	ASCityPC();
	virtual void BeginPlay();
	virtual void SetupInputComponent() override;
	class ACameraActor* MainCamera;
	void moveCameraUp(float val) { MainCamera->AddActorWorldOffset(FVector(0, 0, val * 10)); }
	void moveCameraDown(float val) { MainCamera->AddActorWorldOffset(FVector(0, 0, -val * 10)); }
	void moveCameraRight(float val) { MainCamera->AddActorWorldOffset(FVector(val * 10, 0, 0)); }
	void moveCameraLeft(float val) { MainCamera->AddActorWorldOffset(FVector(-val * 10, 0, 0)); }
	void zoomCamera(float val) { MainCamera->GetCameraComponent()->SetOrthoWidth(MainCamera->GetCameraComponent()->OrthoWidth + val * 30); }
};
