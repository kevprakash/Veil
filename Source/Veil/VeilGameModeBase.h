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

	UFUNCTION(BlueprintCallable)
	void setPlayerLife(AController* player, bool alive, bool force);

	UFUNCTION(BlueprintCallable)
	void setPlayerLoadout(AController* player, FLoadout loadout);

	UFUNCTION(BlueprintCallable)
	void endPhase();

	UFUNCTION(BlueprintCallable)
	void setRoundPhase(GamePhase phase);

protected:
	virtual void OnPostLogin(AController* NewPlayer) override;

	virtual void HandleSeamlessTravelPlayer(AController*& newPlayer) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnMatchLoadPlayer(AController* player);

	virtual void Tick(float deltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	bool shouldPhaseEnd(EndReason cause);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void resetRound();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void spawnDefenders();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void spawnAttackers();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void endRound();

	UFUNCTION(BlueprintCallable)
	TArray<AVeilPlayerController*> getPlayersOnTeam(int team);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<GamePhase, float> phaseLengths;

	UFUNCTION(BlueprintCallable)
	void resetPlayerData();

	UFUNCTION(BlueprintCallable)
	void giveRoundWin(int team);
};
