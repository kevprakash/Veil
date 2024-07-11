// Fill out your copyright notice in the Description page of Project Settings.

#include "VeilGameState.h"
#include "Net/UnrealNetwork.h"
#include "VeilGameModeBase.h"


void AVeilGameState::GetLifetimeReplicatedProps(class TArray<class FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(AVeilGameState, reinforcements, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(AVeilGameState, attackerRounds, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(AVeilGameState, defenderRounds, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(AVeilGameState, attackerAlive, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(AVeilGameState, defenderAlive, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(AVeilGameState, phase, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(AVeilGameState, phaseTimer, COND_None, REPNOTIFY_Always);
}

TArray<AVeilCharacterBase*> AVeilGameState::getPlayersOnTeam(int team) {
	TArray<AVeilCharacterBase*> playersOnTeam;

	auto playerData = Cast<AVeilGameModeBase>(GetWorld()->GetAuthGameMode())->getAllPlayerData();

	for (auto data : playerData) {

		/*
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Team: " + FString::FromInt(data.Value.team)));
		*/

		if (data.Value.team == team && data.Value.alive) {
			APawn* controlledPawn = data.Key->GetPawn();
			if (IsValid(controlledPawn) && controlledPawn->IsA<AVeilCharacterBase>()) {
				AVeilCharacterBase* playerCharacter = Cast<AVeilCharacterBase>(controlledPawn);
				playersOnTeam.Add(playerCharacter);
			}
		}
	}

	return playersOnTeam;
}

int AVeilGameState::getTeam(APlayerController* player) {
	auto playerData = Cast<AVeilGameModeBase>(GetWorld()->GetAuthGameMode())->getAllPlayerData();

	if (playerData.Contains(player)) {

		return playerData[player].team;
	}
	else {
		return -1;
	}
}



void AVeilGameState::swapTeam(APlayerController* player){
	AVeilGameModeBase* gameMode = Cast<AVeilGameModeBase>(GetWorld()->GetAuthGameMode());

	int currentTeam = gameMode->getPlayerTeam(player);

	int newTeam = currentTeam == 0 ? 1 : 0;

	gameMode->changePlayerTeam(player, newTeam);
}

int AVeilGameState::getNumPlayersOnTeam(int team)
{
	auto playerData = Cast<AVeilGameModeBase>(GetWorld()->GetAuthGameMode())->getAllPlayerData();
	int count = 0;
	for (auto data : playerData) {
		if (data.Value.team == team && data.Value.alive) {
			count++;
		}
	}
	return count;
}

int AVeilGameState::getNumPlayersAliveOnTeam(int team)
{
	return team == 0 ? attackerAlive: defenderAlive;
}

void AVeilGameState::subtractReinforcement_Implementation()
{
	reinforcements--;
}

void AVeilGameState::setWinCondition_Implementation(WinConditions newWinCon)
{
	winCondition = newWinCon;
	AVeilGameModeBase* gameMode = Cast<AVeilGameModeBase>(GetWorld()->GetAuthGameMode());
	gameMode->setRoundPhase(GamePhase::POST_ROUND);
}
