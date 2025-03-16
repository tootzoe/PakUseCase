// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PakDownloader.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FChunkDownloadSignature, int32, ChunkID, bool, IsSuccess);


/**
 * 
 */
UCLASS(BlueprintType)
class PAKUSECASE_API UPakDownloader : public UObject
{
	GENERATED_BODY()
	

   public:
    UFUNCTION(BlueprintCallable, Category = "Pak")
    bool InitDownloader(const FString ConfigType, const FString BuildKey, const FString PlatformName);
    UFUNCTION(BlueprintCallable, Category = "Pak")
    void CloseDownloader();
    //
    UFUNCTION(BlueprintCallable, Category = "Pak")
    int32 CheckChunkById(int32 ChunkID);
    UFUNCTION(BlueprintCallable, Category = "Pak")
    void DownloadChunkById(int32 ChunkID);



    UPROPERTY(BlueprintAssignable, Category="Pak")
    FChunkDownloadSignature PakDownloadEvt;


private:

   // bool isAllPaksUpToDate;

	
};
