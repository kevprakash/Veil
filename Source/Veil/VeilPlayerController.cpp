// Fill out your copyright notice in the Description page of Project Settings.


#include "VeilPlayerController.h"
#include "VeilCharacterBase.h"
#include "VeilGameState.h"
#include "Net/UnrealNetwork.h"

void AVeilPlayerController::GetLifetimeReplicatedProps(class TArray<class FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AVeilPlayerController, team);
	DOREPLIFETIME(AVeilPlayerController, attackerCount);
	DOREPLIFETIME(AVeilPlayerController, defenderCount);
}

void AVeilPlayerController::AcknowledgePossession(APawn* newPawn) {
	Super::AcknowledgePossession(newPawn);

	AVeilCharacterBase* characterBase = Cast<AVeilCharacterBase>(newPawn);
	if (characterBase) {
		characterBase->GetAbilitySystemComponent()->InitAbilityActorInfo(characterBase, characterBase);
	}
}
int AVeilPlayerController::getTeam()
{
	updateReplicatedStats();
	return team;
}

void AVeilPlayerController::swapTeam_Implementation()
{
	AVeilGameState* gs = GetWorld()->GetGameState<AVeilGameState>();
	gs->swapTeam(this);
}

int AVeilPlayerController::getNumPlayersOnTeam(int teamToCheck)
{
	updateReplicatedStats();
	return teamToCheck == 0 ? attackerCount : defenderCount;
}

void AVeilPlayerController::updateReplicatedStats_Implementation()
{
	AVeilGameState* gs = GetWorld()->GetGameState<AVeilGameState>();
	team = gs->getTeam(this);
	attackerCount = gs->getNumPlayersOnTeam(0);
	defenderCount = gs->getNumPlayersOnTeam(1);

	/*
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Team: " + FString::FromInt(team)));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Attackers: " + FString::FromInt(attackerCount)));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Defenders: " + FString::FromInt(defenderCount)));
	}
	*/
}

AVeilPlayerController::AVeilPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	bReplicates = true;
}
