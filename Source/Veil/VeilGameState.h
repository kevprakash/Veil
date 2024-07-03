// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "VeilCharacterBase.h"
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

	int getTeam(APlayerController* player);

	void swapTeam(APlayerController* player);

	int getNumPlayersOnTeam(int team);

protected:

	void GetLifetimeReplicatedProps(class TArray<class FLifetimeProperty>& outLifetimeProps) const;

};
