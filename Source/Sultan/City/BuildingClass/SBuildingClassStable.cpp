// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassStable.h"


FString ASBuildingClassStable::IL_BuildingTitle = "buildDes_name_116";

ASBuildingClassStable::ASBuildingClassStable() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassStable::OnClicked);

	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompTrain = BtnListComp.Add(EBuildingBtnAction::BBA_TRAIN, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompTrain")));
	
	BtnCompDetail->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompTrain->SetupAttachment(RootComponent);

	setStableCamels();

}


void ASBuildingClassStable::setStableCamels() {

	TrainCamel1 = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("TrainCamel1"));
	TrainCamel2 = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("TrainCamel2"));
	TrainCamel3 = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("TrainCamel3"));
	TrainCamel4 = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("TrainCamel4"));
	TrainCamel1->SetupAttachment(RootComponent);
	TrainCamel2->SetupAttachment(RootComponent);
	TrainCamel3->SetupAttachment(RootComponent);
	TrainCamel4->SetupAttachment(RootComponent);
	TrainCamel1->SetRelativeLocation(FVector(-10, 2, -20));
	TrainCamel2->SetRelativeLocation(FVector(-35, 5, -33));
	TrainCamel3->SetRelativeLocation(FVector(25, 5, -38));
	TrainCamel4->SetRelativeLocation(FVector(2, 5, -48));
}


void ASBuildingClassStable::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/qibingying.qibingying'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassStable::showTrainSol() {

	UPaperFlipbook* CamelFB = LoadObject<UPaperFlipbook>(nullptr, TEXT("PaperFlipbook'/Game/Animation/MainCity/MainCityNPC/shibing2.shibing2'"));
	if (CamelFB) {
		TrainCamel1->SetFlipbook(CamelFB);
		TrainCamel2->SetFlipbook(CamelFB);
		TrainCamel3->SetFlipbook(CamelFB);
		TrainCamel4->SetFlipbook(CamelFB);
	}

}

void ASBuildingClassStable::hideTrainSol() {


}

void ASBuildingClassStable::BeginPlay() {

	Super::BeginPlay();
	showTrainSol();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassStable::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassStable::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassStable::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompTrain->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassStable::OnBtnClickedTrain);

}


void ASBuildingClassStable::OnBtnClickedDetail() {

	GLog->Log("-----------------**************-----------------");

}


void ASBuildingClassStable::OnBtnClickedUpgrade() {

	GLog->Log("-----------------+++++++++++++++++++-----------------");

}


void ASBuildingClassStable::OnBtnClickedTrain() {

	GLog->Log("-----------------**////////////////*-----------------");

}

void ASBuildingClassStable::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}

void ASBuildingClassStable::setBuildingActionBtnList() {

}

void ASBuildingClassStable::initBuilding() {

}