// Fill out your copyright notice in the Description page of Project Settings.


#include "SNetBase.h"



FString USNetBase::BaseUrl = TEXT("localhost:8080");

USNetBase::USNetBase()
{


	Http = &FHttpModule::Get();


}

USNetBase::~USNetBase() {

	GLog->Log("Destroyed Request ==================================");

}


FString USNetBase::parseReqBody() {

	TArray<FString> Ret;
	for (auto& MapUnit : ReqBody) {
		Ret.Add(FString::Printf(TEXT("%s=%s"), *MapUnit.Key, *MapUnit.Value));
	
	}
	return FString::Join(Ret, TEXT("&"));
}


void USNetBase::GetReq(const FString& url)
{

	if (!Http || !Http->IsHttpEnabled()) {
		GLog->Log("Http is Not valid ------------------------------------------------------------------");
		return;
	}
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Req = Http->CreateRequest();
	Req->OnProcessRequestComplete().BindUObject(this, &USNetBase::OnResponceReady);
	Req->SetURL(FString::Printf(TEXT("http://%s%s?%s"), * USNetBase::BaseUrl, *url, *parseReqBody()));
	Req->SetVerb("GET");
	Req->SetHeader(TEXT("User-Agent"), "X-Alsultan-Agent");
	Req->SetHeader("Content-Type", TEXT("application/json"));
	if(!Req->ProcessRequest())
		GLog->Log("Req->ProcessRequest() valid ------------------------------------------------------------------");

}



void USNetBase::PostReq(const FString& url)
{
	if (!Http || !Http->IsHttpEnabled()) {
		GLog->Log("Http is Not valid ------------------------------------------------------------------");
		return;
	}

	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Req = Http->CreateRequest();
	Req->OnProcessRequestComplete().BindUObject(this, &USNetBase::OnResponceReady);
	Req->SetURL(FString::Printf(TEXT("http://%s%s"), * USNetBase::BaseUrl, *url));
	Req->SetVerb("POST");
	Req->SetContentAsString(parseReqBody());
	Req->SetHeader(TEXT("User-Agent"), "X-Alsultan-Agent");
	Req->SetHeader("Content-Type", "application/x-www-form-urlencoded");
	Req->SetHeader("Content-Type", TEXT("application/json"));
	if(!Req->ProcessRequest())
		GLog->Log("Req->ProcessRequest() valid ------------------------------------------------------------------");

}




void USNetBase::OnResponceReady(FHttpRequestPtr Req, FHttpResponsePtr Res, bool succ) {
	Request = Req;
	Response = Res;
	bWasSuccessful = succ;

	if (!Res.IsValid()) {
		GLog->Log("Res is Not valid ------------------------------------------------------------------");
		return;
	}

	if (!EHttpResponseCodes::IsOk(Response->GetResponseCode())) {
		GLog->Log("Res is Not Ok ------------------------------------------------------------------");
		return;
	}

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Response->GetContentAsString());
	if (!FJsonSerializer::Deserialize(Reader, ResJson)) 
		GLog->Log("Res is Not Json ------------------------------------------------------------------");
	
	OnComplete();
}