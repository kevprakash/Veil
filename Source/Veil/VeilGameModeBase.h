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

	void updateGameState();

	TMap<AController*, FPLAYER_DATA> getAllPlayerData();

protected:
	virtual void OnPostLogin(AController* NewPlayer) override;
};
