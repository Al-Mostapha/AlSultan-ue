// Fill out your copyright notice in the Description page of Project Settings.


#include "SWorldFloorTiles.h"
#include "Serialization/ArchiveLoadCompressedProxy.h"
#include "Serialization/ArchiveSaveCompressedProxy.h"
#include "Serialization/BufferArchive.h"
#include "../../SGameMain.h"
#include "Misc/Base64.h"

TMap<FString, FWorldTiledMap> USWorldFloorTiles::AllWorldMaps;

FString USWorldFloorTiles::LoadFile(FString FileName) {

	FString file = FPaths::ProjectConfigDir();
	file.Append(FileName);
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	FString FileContent;
	if (FileManager.FileExists(*file))
	{
		if (FFileHelper::LoadFileToString(FileContent, *file, FFileHelper::EHashOptions::None))
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Text From File: %d"), FileContent.Len());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: ERROR: Can not read the file because it was not found."));
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Expected file location: %s"), *file);
	}

	return FileContent;
}


void USWorldFloorTiles::SaveFile(FString FileCont) {

	FString file = FPaths::ProjectConfigDir();
	file.Append(TEXT("OldMap.json"));
	// We will use this FileManager to deal with the file.
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	FString StringToWrite = FString::Printf(TEXT("{ \"TileSet\": [], \"LayerCoord\": \"%s\"}"), *FileCont);
	if (FileManager.FileExists(*file))
	{
		if (FFileHelper::SaveStringToFile(StringToWrite, *file))
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Sucsesfuly Written:  to the text file"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Failed to write FString to file."));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: ERROR: Can not read the file because it was not found."));
		UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Expected file location: %s"), *file);
	}
}


void USWorldFloorTiles::DecompressWorldLayers() {

	FString OutPut = LoadFile(FString(TEXT("OldMap_notComp.txt")));
	TArray<FString> OutArray;
	TArray<uint8> OutByteArray;
	OutPut.ParseIntoArray(OutArray, TEXT(","), true);
	OutByteArray.SetNum(OutArray.Num());
	for (int32 ii = 0; ii < OutByteArray.Num(); ii++) {
		OutByteArray[ii] = FCString::Atoi(*(OutArray[ii]));
	}

	TArray<uint8> compressedData;
	FArchiveSaveCompressedProxy  compressor =
		FArchiveSaveCompressedProxy(compressedData, ECompressionFlags::COMPRESS_ZLIB);
	compressor << OutByteArray;
	compressor.Flush();
	compressor.FlushCache();

	SaveFile(FBase64::Encode(compressedData));
	//UE_LOG(LogTemp, Warning, *FString::Printf(TEXT(" Count is %d"), OutArray.Num()));
	

	
}


void USWorldFloorTiles::loadFileAndDecompress() {

	FString file = FPaths::ProjectConfigDir();
	file.Append(TEXT("OldMap.json"));
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	FString FileContent;
	if (!FileManager.FileExists(*file)) {
		//GLog->log("")
		return;
	}
		
	FFileHelper::LoadFileToString(FileContent, *file, FFileHelper::EHashOptions::None);

	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(FileContent);
	if (!FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
	{
		GLog->Log("couldn't deserialize");
		return;
	}

	TArray<uint8> Out;
	FBase64::Decode(JsonObject->GetStringField("LayerCoord"), Out);

	FBufferArchive outbinaryArrayArchive;
	FArchiveLoadCompressedProxy  UnCompress = FArchiveLoadCompressedProxy(Out, NAME_Zlib, ECompressionFlags::COMPRESS_ZLIB);
	UnCompress << outbinaryArrayArchive;
	UnCompress.Flush();
	UnCompress.FlushCache();

	AllWorldMaps.Add("WorldMap", FWorldTiledMap());

	FWorldTiledMap* WorldMap = AllWorldMaps.Find("WorldMap");
	WorldMap->MapTile.SetNum(1201*1201);
	for (int32 index = 0; index < WorldMap->MapTile.Num(); index++) {
		
		WorldMap->MapTile[index].Land   = outbinaryArrayArchive[index *8];
		WorldMap->MapTile[index].Layer0 = outbinaryArrayArchive[index * 8 + 1];
		WorldMap->MapTile[index].Layer1 = outbinaryArrayArchive[index * 8 + 2];
		WorldMap->MapTile[index].Layer2 = outbinaryArrayArchive[index * 8 + 3];
		WorldMap->MapTile[index].Layer3 = outbinaryArrayArchive[index * 8 + 4];
		WorldMap->MapTile[index].Layer4 = outbinaryArrayArchive[index * 8 + 5];
		WorldMap->MapTile[index].Layer5 = outbinaryArrayArchive[index * 8 + 6];
		WorldMap->MapTile[index].Layer6 = outbinaryArrayArchive[index * 8 + 7];
	}

	WorldMap->TileSetDT = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/Game/WorldMap/WorldFloorOld/WorldTileSprite.WorldTileSprite'"));
	if (!WorldMap->TileSetDT) {
		PRINT_STRING(FString::Printf(TEXT("Error Readingfhgfhgfhghf")));
	}
	static const FString ContextString(TEXT("World Unit Sprite"));
	TArray<FWorldFloorTileSprite*> AllSprites;
	WorldMap->TileSetDT->GetAllRows<FWorldFloorTileSprite>(ContextString, AllSprites);
	WorldMap->SpriteList.SetNum(AllSprites.Num());
	for (int32 i = 0; i < AllSprites.Num(); i++) {
	
		WorldMap->SpriteList[i] = *(AllSprites[i]);

	}
	

}