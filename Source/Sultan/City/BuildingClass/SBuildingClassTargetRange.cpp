// Fill out your copyright notice in the Description page of Project Settings.


#include "SBuildingClassTargetRange.h"


FString ASBuildingClassTargetRange::IL_BuildingTitle = "buildDes_name_117";

ASBuildingClassTargetRange::ASBuildingClassTargetRange() {

	Sprite->OnClicked.AddUniqueDynamic(this, &ASBuildingClassTargetRange::OnClicked);

	BtnCompDetail = BtnListComp.Add(EBuildingBtnAction::BBA_DETAIL, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompDetail")));
	BtnCompUpgrade = BtnListComp.Add(EBuildingBtnAction::BBA_UPGRADE, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompUpgrade")));
	BtnCompTrain = BtnListComp.Add(EBuildingBtnAction::BBA_TRAIN, CreateDefaultSubobject<USBuildingActionBtnsComp>(TEXT("BtnCompTrain")));

	BtnCompDetail->SetupAttachment(RootComponent);
	BtnCompUpgrade->SetupAttachment(RootComponent);
	BtnCompTrain->SetupAttachment(RootComponent);

	setBuildingArcher();

}


void ASBuildingClassTargetRange::setBuildingArcher() {

	TrainArcher1 = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("TrainArcher1"));
	TrainArcher2 = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("TrainArcher2"));
	TrainArcher3 = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("TrainArcher3"));
	TrainArcher4 = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("TrainArcher4"));
	TrainArcher1->SetupAttachment(RootComponent);
	TrainArcher2->SetupAttachment(RootComponent);
	TrainArcher3->SetupAttachment(RootComponent);
	TrainArcher4->SetupAttachment(RootComponent);
	TrainArcher1->SetRelativeLocation(FVector(-10, 2, -16));
	TrainArcher2->SetRelativeLocation(FVector(-35, 5, -28));
	TrainArcher3->SetRelativeLocation(FVector(25, 5, -34));
	TrainArcher4->SetRelativeLocation(FVector(2, 5, -44));
}


void ASBuildingClassTargetRange::setSprite() {

	UPaperSprite* BuildingSprite = LoadObject<UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/gongbingying.gongbingying'"));
	Sprite->SetSprite(BuildingSprite);

}


void ASBuildingClassTargetRange::showTrainSol() {

	UPaperFlipbook* ArcherFB = LoadObject<UPaperFlipbook>(nullptr, TEXT("PaperFlipbook'/Game/Animation/MainCity/MainCityNPC/shibing3.shibing3'"));
	if (ArcherFB) {
		TrainArcher1->SetFlipbook(ArcherFB);
		TrainArcher2->SetFlipbook(ArcherFB);
		TrainArcher3->SetFlipbook(ArcherFB);
		TrainArcher4->SetFlipbook(ArcherFB);
	}

}

void ASBuildingClassTargetRange::hideTrainSol() {


}

void ASBuildingClassTargetRange::BeginPlay() {

	Super::BeginPlay();
	showTrainSol();
	setSprite();
	addActionBtnComp();
	bindBtnActionFunction();
}


void ASBuildingClassTargetRange::bindBtnActionFunction() {

	USWid_BuildingACBtn* T = Cast<USWid_BuildingACBtn>(BtnCompDetail->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassTargetRange::OnBtnClickedDetail);

	T = Cast<USWid_BuildingACBtn>(BtnCompUpgrade->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassTargetRange::OnBtnClickedUpgrade);

	T = Cast<USWid_BuildingACBtn>(BtnCompTrain->GetUserWidgetObject());
	if (T)
		T->ActionBtn->OnClicked.AddDynamic(this, &ASBuildingClassTargetRange::OnBtnClickedTrain);

}


void ASBuildingClassTargetRange::OnBtnClickedDetail() {

	GLog->Log("-----------------**************-----------------");

}


void ASBuildingClassTargetRange::OnBtnClickedUpgrade() {

	GLog->Log("-----------------+++++++++++++++++++-----------------");

}


void ASBuildingClassTargetRange::OnBtnClickedTrain() {

	GLog->Log("-----------------**////////////////*-----------------");

}

void ASBuildingClassTargetRange::OnClicked(UPrimitiveComponent* Target, FKey ButtonPressed) {


}


void ASBuildingClassTargetRange::setBuildingActionBtnList() {

}


void ASBuildingClassTargetRange::initBuilding() {

}
