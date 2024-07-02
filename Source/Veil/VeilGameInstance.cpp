// Fill out your copyright notice in the Description page of Project Settings.

#include "VeilGameInstance.h"
#include "VeilGameModeBase.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "steam/steam_api.h"
#include "Online/OnlineSessionNames.h"
#include <string>
#include "Kismet/GameplayStatics.h"

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

void UVeilGameInstance::Init() {
    if (IOnlineSubsystem* subsystem = IOnlineSubsystem::Get()) {
        sessionInterface = subsystem->GetSessionInterface();

        if (sessionInterface.IsValid()) {
            sessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UVeilGameInstance::OnCreateSessionComplete);
            sessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UVeilGameInstance::OnFindSessionComplete);
            sessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UVeilGameInstance::OnJoinSessionComplete);
        }
    }
}

void UVeilGameInstance::CreateServer(FName serverName) {
    
    FOnlineSessionSettings sessionSettings;
    sessionSettings.bAllowJoinInProgress = true;
    sessionSettings.bIsDedicated = false;
    sessionSettings.bIsLANMatch = false;
    sessionSettings.bShouldAdvertise = true;
    sessionSettings.bUsesPresence = true;
    sessionSettings.NumPublicConnections = 10;


    sessionInterface->CreateSession(0, serverName, sessionSettings);

    if (GEngine)
        GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Creating Server with name: " + serverName.ToString()));
}

void UVeilGameInstance::OnCreateSessionComplete(FName serverName, bool success) {
    if (success) {
        GetWorld()->ServerTravel("Maps/TestMap?listen");
    }else {
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Could not create server with name: " + serverName.ToString()));
    }
}

void UVeilGameInstance::JoinServer(FName serverName) {
    sessionSearch = MakeShareable(new FOnlineSessionSearch());
    sessionSearch->bIsLanQuery = false;
    sessionSearch->MaxSearchResults = 10000;
    sessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);

    serverToJoin = serverName;
    sessionInterface->FindSessions(0, sessionSearch.ToSharedRef());
}

void UVeilGameInstance::OnFindSessionComplete(bool success){
    if (success) {
        TArray<FOnlineSessionSearchResult> searchResults = sessionSearch->SearchResults;
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Server count: " + FString::FromInt(searchResults.Num())));

        if (searchResults.Num() > 0) {
            sessionInterface->JoinSession(0, serverToJoin, searchResults[0]);
        }
    }
    else {
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Something went wrong while searching for servers"));
    }
}

void UVeilGameInstance::OnJoinSessionComplete(FName sessionName, EOnJoinSessionCompleteResult::Type result) {
    if (APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0)) {
        FString joinAddress = "";
        sessionInterface->GetResolvedConnectString(sessionName, joinAddress);
        if(joinAddress != "")
            controller->ClientTravel(joinAddress, ETravelType::TRAVEL_Absolute);
    }
}