// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include <map>
#include "VeilStructs.h"
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

	TMap<AController*, FPLAYER_DATA> getAllPlayerData();

protected:
	TMap<AController*, FPLAYER_DATA> playerData;
};
