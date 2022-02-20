// Fill out your copyright notice in the Description page of Project Settings.


#include "SWid_BuildingACBtn.h"

FButtonStyle USWid_BuildingACBtn::BtnStyle;
void USWid_BuildingACBtn::setBtnStyle()
{
	FSlateBrush Brsh;
	Brsh.DrawAs = ESlateBrushDrawType::NoDrawType;
	BtnStyle.SetNormal(Brsh).SetHovered(Brsh).SetDisabled(Brsh).SetPressed(Brsh);
}
