// Fill out your copyright notice in the Description page of Project Settings.


#include "PakDownloader.h"

#include "ChunkDownloader.h"
//#include "AssetRegistry/AssetRegistryModule.h"
#include "Serialization/JsonTypes.h"






bool UPakDownloader::InitDownloader(const FString ConfigType, const FString BuildKey, const FString PlatformName)
{
    UE_LOG(LogTemp, Warning, TEXT("C++ InitDownloader..........%s , %s ") , *ConfigType, *BuildKey);

    bool isUpToDate = false;

    TSharedRef<FChunkDownloader> tmpDl = FChunkDownloader::GetOrCreate();
    tmpDl->Initialize(PlatformName , 8);
    //
    tmpDl->LoadCachedBuild(ConfigType);
    //

    TFunction<void(bool)> checkAllPaksUpToDate = [&](bool b){ isUpToDate = b;};
    tmpDl->UpdateBuild(ConfigType, BuildKey, checkAllPaksUpToDate);


     // FJsonSerializableArrayInt dlChunks;
     // dlChunks.Add(1432);

     // dlChunks.ToString();
     // UE_LOG(LogTemp, Warning, TEXT("Json : %s"),  dlChunks.ToString(););

    return isUpToDate;

}




void UPakDownloader::CloseDownloader()
{
    UE_LOG(LogTemp, Warning, TEXT("c++ CloseDownloader.........."));
    FChunkDownloader::Shutdown();
}

int32 UPakDownloader::CheckChunkById(int32 ChunkID)
{
     TSharedRef<FChunkDownloader> dl = FChunkDownloader::GetChecked();
     return static_cast<int32>(dl->GetChunkStatus(ChunkID));
}

void UPakDownloader::DownloadChunkById(int32 ChunkID)
{
    TSharedRef<FChunkDownloader> dl = FChunkDownloader::GetChecked();

    TFunction<void(bool)> dlCb = [& , ChunkID](bool b){
        PakDownloadEvt.Broadcast(ChunkID, b);
    };

    dl->DownloadChunk(ChunkID , dlCb , 1);

}
