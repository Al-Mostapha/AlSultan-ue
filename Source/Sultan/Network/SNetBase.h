// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Http.h"
#include "JsonObjectConverter.h"
#include "SNetBase.generated.h"

/**
 * 
 */
UCLASS()
class SULTAN_API USNetBase : public UObject
{
	GENERATED_BODY()
		FHttpModule* Http;
public:
	
	static FString BaseUrl;
	USNetBase();
	~USNetBase();
	FHttpRequestPtr Request;
	FHttpResponsePtr Response;
	bool bWasSuccessful;
	TFunction<void()> OnComplete;
	void OnResponceReady(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	FString parseReqBody();
	void GetReq(const FString& url);
	void PostReq(const FString& url);
	TSharedPtr<FJsonObject> ResJson;
	TMap<FString, FString> ReqBody;
	
};
