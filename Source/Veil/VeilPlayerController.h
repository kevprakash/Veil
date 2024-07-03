// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VeilPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class VEIL_API AVeilPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	AVeilPlayerController(const FObjectInitializer& ObjectInitializer);

	virtual void AcknowledgePossession(APawn* NewPawn) override;

	UFUNCTION(BlueprintCallable)
	int getTeam();

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void swapTeam();

	UFUNCTION(BlueprintCallable)
	int getNumPlayersOnTeam(int teamToCheck);

	UFUNCTION(Server, Reliable)
	void updateReplicatedStats();

	UPROPERTY(Replicated)
	int team;

	UPROPERTY(Replicated)
	int attackerCount;

	UPROPERTY(Replicated)
	int defenderCount;

	void GetLifetimeReplicatedProps(class TArray<class FLifetimeProperty>& outLifetimeProps) const;
};
