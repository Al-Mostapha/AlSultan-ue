// Fill out your copyright notice in the Description page of Project Settings.


#include "SWorldCoord.h"


FWorldAddedUnit USWorldCoord::WorldAddedUnit[WORLD_WIDTH_IN_UNIT][WORLD_HEIGHT_IN_UNIT];

int32 USWorldCoord::getRealCoordX(int32 xCoord) { return ((xCoord % WORLD_WIDTH_IN_UNIT) + WORLD_WIDTH_IN_UNIT) % WORLD_WIDTH_IN_UNIT; }
int32 USWorldCoord::getRealCoordY(int32 yCoord) { return ((yCoord % WORLD_HEIGHT_IN_UNIT) + WORLD_HEIGHT_IN_UNIT) % WORLD_HEIGHT_IN_UNIT; }

void USWorldCoord::getUnitPos(int32 xCoord, int32 yCoord, FVector& Vect) {
	Vect.X = xCoord * S_WORLD_UNIT_WIDTH + abs(yCoord % 2) * S_WORLD_UNIT_HEIGHT/2;
	Vect.Z = yCoord * S_WORLD_UNIT_HEIGHT -  abs(yCoord % 2) * S_WORLD_UNIT_HEIGHT/2;
}
int32 USWorldCoord::getUnitPosX(int32 xCoord, int32 yCoord) {
	return xCoord * S_WORLD_UNIT_WIDTH/2 - yCoord * S_WORLD_UNIT_HEIGHT/2;
}

int32 USWorldCoord::getUnitPosY(int32 xCoord, int32 yCoord) {
	return   -(xCoord * S_WORLD_UNIT_WIDTH/4 + yCoord * S_WORLD_UNIT_HEIGHT/4);
}

int32 USWorldCoord::getUnitXCoordFromPos(int32 xPixle, int32 yPixle) {
	return FMath::RoundToInt((-2 * yPixle + xPixle) / S_WORLD_UNIT_WIDTH);
}

int32 USWorldCoord::getUnitYCoordFromPos(int32 xPixle, int32 yPixle) {
	return FMath::RoundToInt(-(2 * yPixle + xPixle) / S_WORLD_UNIT_HEIGHT);
}