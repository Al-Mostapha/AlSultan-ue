// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameBoot.h"

USGameBoot::USGameBoot() {


}


void USGameBoot::getBuildingLvlData() {

	USNetBase* Req = NewObject<USNetBase>();
	Req->OnComplete = [Req]() {
		GLog->Log("----------------------------");
		/**TSharedPtr<FJsonObject> JsonValue;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Req->Response->GetContentAsString());
		if(!FJsonSerializer::Deserialize(Reader, JsonValue)){
			GLog->Log(JsonValue->GetStringField("State"));
		}*/

		TSharedPtr<FJsonObject> JsonValue;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Req->Response->GetContentAsString());
		if (!FJsonSerializer::Deserialize(Reader, JsonValue)) {
			GLog->Log(Req->Response->GetContentAsString());
			return;
		}
		
		ASBuildingClassBarrack::getLvlData(JsonValue->GetObjectField("Barrack"));
		ASBuildingClassBlackSmith::getLvlData(JsonValue->GetObjectField("BlackSmith"));
		ASBuildingClassCastle::getLvlData(JsonValue->GetObjectField("Castle"));
		ASBuildingClassDrill::getLvlData(JsonValue->GetObjectField("DrillGrounds"));
		ASBuildingClassEmbassy::getLvlData(JsonValue->GetObjectField("Embassy"));
		ASBuildingClassFortress::getLvlData(JsonValue->GetObjectField("Fortress"));
		ASBuildingClassHallOfWar::getLvlData(JsonValue->GetObjectField("HallOfWar"));
		ASBuildingClassInstitute::getLvlData(JsonValue->GetObjectField("Collage"));
		ASBuildingClassMarket::getLvlData(JsonValue->GetObjectField("Market"));
		ASBuildingClassOFarm::getLvlData(JsonValue->GetObjectField("Farm"));
		ASBuildingClassOIronMine::getLvlData(JsonValue->GetObjectField("IronMine"));
		ASBuildingClassOMiliTent::getLvlData(JsonValue->GetObjectField("MiliTent"));
		ASBuildingClassOSawMill::getLvlData(JsonValue->GetObjectField("SawMill"));
		ASBuildingClassOSteel::getLvlData(JsonValue->GetObjectField("Steel"));
		ASBuildingClassStable::getLvlData(JsonValue->GetObjectField("Stable"));
		ASBuildingClassTargetRange::getLvlData(JsonValue->GetObjectField("TargetRange"));
		ASBuildingClassTreasurePool::getLvlData(JsonValue->GetObjectField("WishingWell"));
		ASBuildingClassWall::getLvlData(JsonValue->GetObjectField("Wall"));
		ASBuildingClassWarehouse::getLvlData(JsonValue->GetObjectField("WareHouse"));
		ASBuildingClassWatchTower::getLvlData(JsonValue->GetObjectField("WatchTower"));
		ASBuildingClassWorkshop::getLvlData(JsonValue->GetObjectField("WorkShop"));
	};
	Req->GetReq("/Static/Json-0.0.1/GeneratedBuildingLvl.json");
}
