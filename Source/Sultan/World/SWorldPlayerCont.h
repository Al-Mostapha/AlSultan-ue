// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "../SGameMain.h"
#include "SWorldPlayerCont.generated.h"


USTRUCT(BlueprintType)
struct FScreenCornersToWorld {
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector TopLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector TopRight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector BottomLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector BottomRight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 xCoordStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 yCoordStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 xCoordEnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 yCoordEnd;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 widthInUnit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 heightInUnit;
     FString ToString() {
		return FString::Printf(TEXT("TL %s, TR %s, BL %S, BR %s"), *TopLeft.ToString(), *TopRight.ToString(), *BottomLeft.ToString(), *BottomRight.ToString());
	}
};


/**
 * 
 */
UCLASS()
class SULTAN_API ASWorldPlayerCont : public APlayerController
{
	GENERATED_BODY()
		ASWorldPlayerCont();
	virtual void BeginPlay();
	virtual void SetupInputComponent() override;
	class ACameraActor* MainCamera;
	void moveCameraUp(float val) {
		if (!val)
			return;
		refreshWorldFloor(); 
		MainCamera->AddActorWorldOffset(FVector(0, 0, val * 10)); 
	}
	void moveCameraDown(float val) {
		if (!val)
			return;
		PRINT_STRING(FString::SanitizeFloat(val, 5))
		refreshWorldFloor(); 
		MainCamera->AddActorWorldOffset(FVector(0, 0, -val * 10));
	}
	void moveCameraRight(float val) {
		if (!val)
			return; 
		refreshWorldFloor();
		MainCamera->AddActorWorldOffset(FVector(val * 10, 0, 0));
	}
	void moveCameraLeft(float val) {
		if (!val)
			return; 
		refreshWorldFloor();
		MainCamera->AddActorWorldOffset(FVector(-val * 10, 0, 0));
	}
	void zoomCamera(float val) {
		if (!val)
			return;
		MainCamera->GetCameraComponent()->SetOrthoWidth(MainCamera->GetCameraComponent()->OrthoWidth + -val * 100);
	}
	FScreenCornersToWorld getScreenCornerCoord();
	void destroyUnitsInColumns(FScreenCornersToWorld& ScreenCorner);
	void destroyUnitsInRaws(FScreenCornersToWorld& ScreenCorner);
	void refreshWorldFloor();
	void showWorldCorner();
};
