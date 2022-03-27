// Fill out your copyright notice in the Description page of Project Settings.



#include "SCityGM.h"
#include "Engine/World.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "SCityFloor.h"
#include "SCityPC.h"
#include "../SGameMain.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "BuildingClass/SCityBuilding.h"
#include "BuildingClass/SBuildingClassCastle.h"
#include "BuildingClass/SBuildingClassStable.h"
#include "BuildingWid/SBuildingActionBtnsWid.h"
#include "../SGameBoot.h"
#include "../World/SWorldFloor.h"


class UCameraComponent;
void ASCityGM::initCamera() {

	
}


ASCityGM::ASCityGM() {
	PlayerControllerClass = ASCityPC::StaticClass();
	
}

void ASCityGM::StartPlay() {

	Super::StartPlay();

	USGameBoot::getBuildingLvlData();

	FBuildingActionBtn::initActionBtn();
	ASBuildingClassCastle::initCastleSkin();
	USCBuilding::initBuildingPos();
	USCBuilding::initBuildingData();
	buildCityFloor();
	
	USNetBase* Req = NewObject<USNetBase>();
	Req->ReqBody = {
		{"Test1", "Test"},
		{"Test2", "Test"},
		{"Test3", "Test"},
		{"Test4", "Test"},
		{"Test5", "Test"},
		{"Test6", "Test"},
	};
	Req->OnComplete = [this, Req]() {
		GLog->Log("----------------------------");
		/**TSharedPtr<FJsonObject> JsonValue;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Req->Response->GetContentAsString());
		if(!FJsonSerializer::Deserialize(Reader, JsonValue)){
			GLog->Log(JsonValue->GetStringField("State"));
		}*/
		FJsonObjectConverter::JsonObjectToUStruct(Req->ResJson.ToSharedRef(), &USGameMain::PlayerCity);
		PRINT_STRUCT(USGameMain::PlayerCity);
		buildCityBuilding();
	};
	Req->GetReq("/api/CCity/getCity");

	

	return;



	
	
	buildCityFixedBuilding();
	buildCityFixedDecore();
	buildCityResBuilding();
	buildCityOuterBuilding();
	


}



void ASCityGM::buildCityFloor() {

	ASCityFloor::CityFloorParts = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityFloorPartsLvl1DT.CityFloorPartsLvl1DT'"));

	if (!ASCityFloor::CityFloorParts) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityFloorPart*> CityPartArr;
	ASCityFloor::CityFloorParts->GetAllRows<FCityFloorPart>(FString(TEXT("City Parts")), CityPartArr);
	ASCityFloor* OneCityFloor;

	for (FCityFloorPart* OnePart : CityPartArr) {
		FVector Vect(OnePart->x, OnePart->y, OnePart->z);
		FRotator Rot(OnePart->yaw, OnePart->roll, 0);
		OneCityFloor = GetWorld()->SpawnActor<ASCityFloor>(ASCityFloor::StaticClass(), Vect, Rot);
		OneCityFloor->setSprite(OnePart->Sprite);
	}



}


void ASCityGM::buildCityBuilding() {
	/**
	ASCityBuilding::CityBuildingPos = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DTCityBuildingPos.DTCityBuildingPos'"));

	if (!ASCityBuilding::CityBuildingPos) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityBuildingPos*> CityBuildingPosArr;
	ASCityBuilding::CityBuildingPos->GetAllRows<FCityBuildingPos>(FString(TEXT("City Parts")), CityBuildingPosArr);
	ASCityBuilding* OneCityBuilding;

	for (FCityBuildingPos* OneCityBuildingPos : CityBuildingPosArr) {

		OneCityBuilding = GetWorld()->SpawnActor<ASCityBuilding>(ASCityBuilding::StaticClass(), OneCityBuildingPos->Vect, OneCityBuildingPos->Rot);
		UPaperSprite* Temp = LoadObject<class UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingInner/bubingying_war.bubingying_war'"));

		OneCityBuilding->setSprite(Temp);

		//OneCityBuildingPos->setSprite(OneCityBuildingPos->Sprite);
	}*/
	ASCityBuilding* OneCityBuilding;
	for (auto OneBuilding : USCBuilding::BuildingPos) {
		FCityBuildingUnitDS Building;
		if (OneBuilding.BuildingCityPlace == ECBuildingCityPlace::INNER)
			Building = USGameMain::PlayerCity.BuildingInner.getBuilding(FName(*OneBuilding.BuildingPlace));
		else if (OneBuilding.BuildingCityPlace == ECBuildingCityPlace::OUTER)
			Building = USGameMain::PlayerCity.BuildingOuter.getBuilding(FName(*OneBuilding.BuildingPlace));
		else
			GLog->Log("----------------------- ERROR Buildig Type");

		if (!USCBuilding::BuildingData.Contains(Building.buildingType)) {
			GLog->Log("----------------------- ERROR Buildig Type NOT FOUND IN MAP -> " + FString::FromInt(static_cast<uint8>(Building.buildingType))  + "  === " + OneBuilding.BuildingPlace);
			continue;
		}
		if (!GetWorld()) {
			GLog->Log("-----------------------hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh");
			return;
		}
			

		FBuildingData BuildingData = USCBuilding::BuildingData[Building.buildingType];
		if (!BuildingData.BuildingClass) {
			GLog->Log("-----------------------hhhhhhhhhhffffffffffffffffffffffffffffhhhhhhhhhhhhhhhhhh");
			return;
		}
		OneCityBuilding =  GetWorld()->SpawnActor<ASCityBuilding>(
			BuildingData.BuildingClass,
			OneBuilding.Vect,
			OneBuilding.Rot);

		if (!OneCityBuilding) {
			GLog->Log("----------------------- ERROR Buildig Type NOT FOUND IN MAP At Place " + OneBuilding.BuildingPlace + "---" +  FString::FromInt(static_cast<uint8>(Building.buildingType)));
			continue;
		}
		OneCityBuilding->initBuilding();
		OneCityBuilding->BuildingPlace = OneBuilding.BuildingPlace;
		GLog->Log(OneBuilding.BuildingPlace);
	}



}


void ASCityGM::buildCityFixedBuilding() {
	
	UDataTable* FixedBuilding = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DTCityFixedBuildingPos.DTCityFixedBuildingPos'"));

	if (!FixedBuilding) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityFixedBuildingPosAndSp*> CityFixedBuildingArr;
	FixedBuilding->GetAllRows<FCityFixedBuildingPosAndSp>(FString(TEXT("City Parts")), CityFixedBuildingArr);
	ASCityBuilding* OneCityBuilding;

	for (FCityFixedBuildingPosAndSp* OneCityBuildingPos : CityFixedBuildingArr) {

		OneCityBuilding = GetWorld()->SpawnActor<ASCityBuilding>(ASCityBuilding::StaticClass(), OneCityBuildingPos->Vect, OneCityBuildingPos->Rot);
		OneCityBuilding->setSprite(OneCityBuildingPos->Sprite);

		//OneCityBuildingPos->setSprite(OneCityBuildingPos->Sprite);
	}
	

}

void ASCityGM::buildCityFixedDecore() {


	UDataTable* FixedBuildingDecore = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DTCityDecore.DTCityDecore'"));


	if (!FixedBuildingDecore) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityFixedBuildingPosAndSp*> CityFixedBuildingArr;
	FixedBuildingDecore->GetAllRows<FCityFixedBuildingPosAndSp>(FString(TEXT("City Parts")), CityFixedBuildingArr);
	ASCityFloor* OneCityBuilding;

	for (FCityFixedBuildingPosAndSp* OneCityBuildingPos : CityFixedBuildingArr) {

		OneCityBuilding = GetWorld()->SpawnActor<ASCityFloor>(ASCityFloor::StaticClass(), OneCityBuildingPos->Vect, OneCityBuildingPos->Rot);
		OneCityBuilding->setSprite(OneCityBuildingPos->Sprite);
	}


}

void ASCityGM::buildCityResBuilding() {

	ASCityBuilding::CityBuildingPos = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DTCityBuildingResOutPos.DTCityBuildingResOutPos'"));



	if (!ASCityBuilding::CityBuildingPos) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityBuildingPos*> CityBuildingPosArr;
	ASCityBuilding::CityBuildingPos->GetAllRows<FCityBuildingPos>(FString(TEXT("City Parts")), CityBuildingPosArr);
	ASCityBuilding* OneCityBuilding;

	for (FCityBuildingPos* OneCityBuildingPos : CityBuildingPosArr) {

		OneCityBuilding = GetWorld()->SpawnActor<ASCityBuilding>(ASCityBuilding::StaticClass(), OneCityBuildingPos->Vect, OneCityBuildingPos->Rot);
		UPaperSprite* Temp = LoadObject<class UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingAcc/res_tile.res_tile'"));
		OneCityBuilding->setSprite(Temp);
	}
}


void ASCityGM::buildCityOuterBuilding() {

	ASCityBuilding::CityBuildingPos = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/DTCItyBuildingOutPos.DTCItyBuildingOutPos'"));

	if (!ASCityBuilding::CityBuildingPos) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityBuildingPos*> CityBuildingPosArr;
	ASCityBuilding::CityBuildingPos->GetAllRows<FCityBuildingPos>(FString(TEXT("City Parts")), CityBuildingPosArr);
	ASCityBuilding* OneCityBuilding;

	for (FCityBuildingPos* OneCityBuildingPos : CityBuildingPosArr) {

		OneCityBuilding = GetWorld()->SpawnActor<ASCityBuilding>(ASCityBuilding::StaticClass(), OneCityBuildingPos->Vect, OneCityBuildingPos->Rot);
		UPaperSprite* Temp = LoadObject<class UPaperSprite>(nullptr, TEXT("PaperSprite'/Game/City/CityOld/BuildingAcc/inner_city_building_tile.inner_city_building_tile'"));
		OneCityBuilding->setSprite(Temp);
	}
}


void ASCityGM::buildCompleteBuilding() {



	ASBuildingClassCastle* iii1 = GetWorld()->SpawnActor<ASBuildingClassCastle>(ASBuildingClassCastle::StaticClass(),  FVector(2283.0, 10, -168.0), FRotator::ZeroRotator);
	/*ASBuildingClassCastle* iii2 = GetWorld()->SpawnActor<ASBuildingClassCastle>(ASBuildingClassCastle::StaticClass(), FVector(750, 0, 0), FRotator::ZeroRotator);
	ASBuildingClassCastle* iii3 = GetWorld()->SpawnActor<ASBuildingClassCastle>(ASBuildingClassCastle::StaticClass(),  FVector(1500, 0, 0), FRotator::ZeroRotator);
	ASBuildingClassCastle* iii4 = GetWorld()->SpawnActor<ASBuildingClassCastle>(ASBuildingClassCastle::StaticClass(),  FVector(2250, 0, 0), FRotator::ZeroRotator);
	ASBuildingClassCastle* iii5 = GetWorld()->SpawnActor<ASBuildingClassCastle>(ASBuildingClassCastle::StaticClass(),  FVector(0, 0, 750), FRotator::ZeroRotator);
	ASBuildingClassCastle* iii6 = GetWorld()->SpawnActor<ASBuildingClassCastle>(ASBuildingClassCastle::StaticClass(),  FVector(0, 0, 1500), FRotator::ZeroRotator);
	ASBuildingClassCastle* iii7 = GetWorld()->SpawnActor<ASBuildingClassCastle>(ASBuildingClassCastle::StaticClass(),  FVector(0, 0, 2250), FRotator::ZeroRotator);
	ASBuildingClassCastle* iii8 = GetWorld()->SpawnActor<ASBuildingClassCastle>(ASBuildingClassCastle::StaticClass(),  FVector(-750, 0, 0), FRotator::ZeroRotator);
	ASBuildingClassCastle* iii9 = GetWorld()->SpawnActor<ASBuildingClassCastle>(ASBuildingClassCastle::StaticClass(),  FVector(0, 0, -750), FRotator::ZeroRotator);
	ASBuildingClassCastle* iii10 = GetWorld()->SpawnActor<ASBuildingClassCastle>(ASBuildingClassCastle::StaticClass(), FVector(-1500, 0, 0), FRotator::ZeroRotator);
	
	iii1->setSkin(ECityCastleSkin::CLASSICAL);
	iii2->setSkin(ECityCastleSkin::RAMADAN);
	iii3->setSkin(ECityCastleSkin::WARLV);
	iii4->setSkin(ECityCastleSkin::SUPERVIP);
	iii5->setSkin(ECityCastleSkin::SECOND);
	iii6->setSkin(ECityCastleSkin::THREE);
	iii7->setSkin(ECityCastleSkin::NEWRAMADAN);
	iii8->setSkin(ECityCastleSkin::KOH2018RAMADAN);
	iii9->setSkin(ECityCastleSkin::EGYPT);
	iii10->setSkin(ECityCastleSkin::PANTHER);*/

	iii1->setSkin(ECityCastleSkin::CLASSICAL);

	return;
	/**

	UDataTable* TestTable = LoadObject<class UDataTable>(nullptr, TEXT("DataTable'/Game/City/CityOld/NewDataTable.NewDataTable'"));

	if (!TestTable) {

		PRINT_STRING(TEXT("Error City Flor Parts Data Table"));
		return;
	}

	TArray<FCityBuildingData*> CityBuildingPosArr;
	TestTable->GetAllRows<FCityBuildingData>(FString(TEXT("City Parts")), CityBuildingPosArr);

	for (FCityBuildingData* OneCityBuildingPos : CityBuildingPosArr) {

		ASCityBuilding* Test = GetWorld()->SpawnActor<ASCityBuilding>(OneCityBuildingPos->BuildingClass, FVector::ZeroVector, FRotator::ZeroRotator);*/
		//Test->setSprite(OneCityBuildingPos->FloorSprite);
		//Test->WidgitComp->SetWidgetClass(OneCityBuildingPos->BuildingProg);
		//Test->WidgitComp
	//}
}


void ASCityGM::BeginPlay() {

	Super::BeginPlay();

	PRINT_STRING(FString::Printf(TEXT("Trattttttt")))

}




