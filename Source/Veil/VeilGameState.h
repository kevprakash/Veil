// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "VeilCharacterBase.h"
#include "VeilStructs.h"
#include "VeilGameState.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class VEIL_API AVeilGameState : public AGameState
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	TArray<AVeilCharacterBase*> getPlayersOnTeam(int team);

	UFUNCTION(BlueprintCallable)
	int getTeam(APlayerController* player);

	void swapTeam(APlayerController* player);

	int getNumPlayersOnTeam(int team);

	UFUNCTION(BlueprintCallable)
	int getNumPlayersAliveOnTeam(int team);

	UPROPERTY(BlueprintReadOnly, Replicated)
	int reinforcements = 10;

	UPROPERTY(BlueprintReadOnly, Replicated)
	int attackerRounds = 0;

	UPROPERTY(BlueprintReadOnly, Replicated)
	int defenderRounds = 0;

	UPROPERTY(BlueprintReadOnly, Replicated)
	int attackerAlive = 0;

	UPROPERTY(BlueprintReadOnly, Replicated)
	int defenderAlive = 0;

	UPROPERTY(BlueprintReadOnly, Replicated)
	bool bombPlanted = false;
	
	UPROPERTY(BlueprintReadOnly, Replicated)
	GamePhase phase = GamePhase::PRE_ROUND;

	UPROPERTY(BlueprintReadOnly, Replicated)
	WinConditions winCondition = WinConditions::NONE;

	UPROPERTY(BlueprintReadOnly, Replicated);
	float phaseTimer = 0.0f;

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void subtractReinforcement();

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void setWinCondition(WinConditions newWinCon);


protected:

	void GetLifetimeReplicatedProps(class TArray<class FLifetimeProperty>& outLifetimeProps) const;

};
