// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <map>
#include "VeilStructs.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "VeilGameInstance.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class VEIL_API UVeilGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	void registerPlayer(AController* newPlayer);

	UFUNCTION(BlueprintCallable)
	int getPlayerTeam(AController* newPlayer);

	UFUNCTION(BlueprintCallable)
	FPLAYER_DATA getPlayerData(AController* newPlayer);

	void setPlayerData(AController* player, FPLAYER_DATA newData);

	bool updatePlayerTeam(AController* player, int newTeam);

	bool updatePlayerLife(AController* player, bool alive);

	bool updatePlayerLoadout(AController* player, FLoadout loadout);

	TMap<AController*, FPLAYER_DATA> getAllPlayerData();

	void clearPlayerData();

	void resetPlayerData();

protected:
	virtual void Init() override;

	TMap<AController*, FPLAYER_DATA> playerData;

	IOnlineSessionPtr sessionInterface;

	UFUNCTION(BlueprintCallable)
	void CreateServer(FName serverName);

	UFUNCTION(BlueprintCallable)
	void JoinServer(FName serverName);

	virtual void OnCreateSessionComplete(FName serverName, bool success);
	virtual void OnFindSessionComplete(bool success);
	virtual void OnJoinSessionComplete(FName sessionName, EOnJoinSessionCompleteResult::Type result);

	TSharedPtr<FOnlineSessionSearch> sessionSearch;

	FName serverToJoin;
};
