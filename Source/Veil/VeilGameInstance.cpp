// Fill out your copyright notice in the Description page of Project Settings.

#include "VeilGameInstance.h"
#include "VeilGameModeBase.h"

void UVeilGameInstance::registerPlayer(AController* newPlayer) {
    if (newPlayer) {
        FPLAYER_DATA newPlayerData;
        newPlayerData.team = 0; //playerData.Num() % 2;
        playerData.Add( newPlayer, newPlayerData );
        UE_LOG(LogTemp, Log, TEXT("Registered player with team %d"), newPlayerData.team);

        /**
        if (GEngine) {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, FString::Printf(TEXT("Registered player with team %d"), newPlayerData.team));
        }
        **/

    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Attempted to register a null player"));
    }

    ((AVeilGameModeBase*)GetWorld()->GetAuthGameMode())->updateGameState();
}

int UVeilGameInstance::getPlayerTeam(AController* newPlayer) {
	return playerData[newPlayer].team;
}

FPLAYER_DATA UVeilGameInstance::getPlayerData(AController* newPlayer) {
	return playerData[newPlayer];
}

TMap<AController*, FPLAYER_DATA> UVeilGameInstance::getAllPlayerData() {
    return playerData;
}