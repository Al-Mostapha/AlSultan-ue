// Fill out your copyright notice in the Description page of Project Settings.


#include "SCityModel.h"



USCityModel::USCityModel() {

	FCityDS Test;
	Test.idCity = 15;
	Test.BuildingOuter.resBuilding_1.buildingLvl = 1000;
	GLog->Log(FString::Printf(TEXT("ttttttttttttttttttttttttttttttttttttttttttttttttttt v %d"), Test.BuildingOuter.getBuilding(FName("TEDS")).buildingLvl ));
	//FJsonObjectConverter::UStructToJsonObject<Test>();
	


	/**for (TFieldIterator<FProperty> It(Test); It; ++It)
	{
		FProperty* Property = *It;

		// Check to see if we should ignore this property
		if (CheckFlags != 0 && !Property->HasAnyPropertyFlags(CheckFlags))
		{
			continue;
		}
		if (Property->HasAnyPropertyFlags(SkipFlags))
		{
			continue;
		}

		FString VariableName = StandardizeCase(Property->GetName());
		const void* Value = Property->ContainerPtrToValuePtr<uint8>(Struct);

		// convert the property to a FJsonValue
		TSharedPtr<FJsonValue> JsonValue = UPropertyToJsonValue(Property, Value, CheckFlags, SkipFlags, ExportCb);
		if (!JsonValue.IsValid())
		{
			FFieldClass* PropClass = Property->GetClass();
			UE_LOG(LogJson, Error, TEXT("UStructToJsonObject - Unhandled property type '%s': %s"), *PropClass->GetName(), *Property->GetPathName());
			return false;
		}

		// set the value on the output object
		OutJsonAttributes.Add(VariableName, JsonValue);
	}*/
}