// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "VeilStructs.h"
#include "VeilGameModeBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class VEIL_API AVeilGameModeBase : public AGameMode
{
	GENERATED_BODY()
	
public:

	AVeilGameModeBase(const FObjectInitializer& ObjectInitializer);

	void updateGameState();

	TMap<AController*, FPLAYER_DATA> getAllPlayerData();

	void changePlayerTeam(AController* player, int newTeam);

	int getPlayerTeam(AController* player);

	UFUNCTION(BlueprintCallable)
	void startGame();

protected:
	virtual void OnPostLogin(AController* NewPlayer) override;

	virtual void HandleSeamlessTravelPlayer(AController*& newPlayer) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnMatchLoadPlayer(AController* player);
};
