// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassBarrack.h"

FString ASBuildingClassBarrack::IL_BuildingTitle = "buildDes_name_118";

ASBuildingClassBarrack::ASBuildingClassBarrack() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassBarrack::OnClicked);
	BtnCompDetail  = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE,CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompTrain   = BtnListComp.Add(EBuildingBtnAction::BBA_TRAIN,  CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompTrain")));
	TrainInfantry  = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("TrainInfantry"));
	setBarrackInfantry();

}


void ASBuildingClassBarrack::setBarrackInfantry() {

	
	TrainInfantry->SetupAttachment(RootComponent);
	TrainInfantry->SetRelativeLocation(FVector(-8, 5, -24));
}


void ASBuildingClassBarrack::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/bubingying.bubingying'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassBarrack::showTrainSol() {

	UPaperFlipbook* InfantryFB = LoadObject<UPaperFlipbook>(nullptr, TEXT("PaperFlipbook'/Game/Animation/MainCity/MainCityNPC/bybubing.bybubing'"));
	if (InfantryFB) {
		TrainInfantry->SetFlipbook(InfantryFB);
	}

}

void ASBuildingClassBarrack::hideTrainSol() {


}

void ASBuildingClassBarrack::BeginPlay() {

	Super::BeginPlay();
	showTrainSol();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();

}

void ASBuildingClassBarrack::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


	GLog->Log("------------------------------------------------------------------");

}

void ASBuildingClassBarrack::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBarrack::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBarrack::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompTrain->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassBarrack::OnBtnClickedTrain);

}


void ASBuildingClassBarrack::OnBtnClickedDetail() {

	GLog->Log("-----------------**************-----------------");

}


void ASBuildingClassBarrack::OnBtnClickedUpgrade() {

	GLog->Log("-----------------+++++++++++++++++++-----------------");

}


void ASBuildingClassBarrack::OnBtnClickedTrain() {

	GLog->Log("-----------------**////////////////*-----------------");

}