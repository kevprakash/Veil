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
			if (controlledPawn->IsA<AVeilCharacterBase>()) {
				AVeilCharacterBase* playerCharacter = Cast<AVeilCharacterBase>(controlledPawn);
				playersOnTeam.Add(playerCharacter);
			}
		}
	}

	return playersOnTeam;
}