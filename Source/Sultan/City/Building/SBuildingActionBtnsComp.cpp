// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingActionBtnsComp.h"

USBuildingActionBtnsComp::USBuildingActionBtnsComp() {
	bReceiveHardwareInput = true;
	SetRelativeRotation(FRotator(0, 90, 0));
	SetRelativeLocation(FVector(0, 10, -96));
	SetDrawSize(FVector2D(100, 100));
}