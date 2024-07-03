// Fill out your copyright notice in the Description page of Project Settings.

#include "VeilGameState.h"
#include "Net/UnrealNetwork.h"
#include "VeilGameModeBase.h"


void AVeilGameState::GetLifetimeReplicatedProps(class TArray<class FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

TArray<AVeilCharacterBase*> AVeilGameState::getPlayersOnTeam(int team) {
	TArray<AVeilCharacterBase*> playersOnTeam;

	auto playerData = Cast<AVeilGameModeBase>(GetWorld()->GetAuthGameMode())->getAllPlayerData();

	for (auto data : playerData) {
		if (data.Value.team == team) {
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

	return playerData[player].team;
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
		if (data.Value.team == team) {
			count++;
		}
	}
	return count;
}
