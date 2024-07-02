// Fill out your copyright notice in the Description page of Project Settings.

#include "VeilGameModeBase.h"
#include "VeilGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "VeilGameState.h"

void AVeilGameModeBase::OnPostLogin(AController* newPlayer) {
	UVeilGameInstance* GI = Cast<UVeilGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GI->registerPlayer(newPlayer);
}

TMap<AController*, FPLAYER_DATA> AVeilGameModeBase::getAllPlayerData() {
	UVeilGameInstance* GI = Cast<UVeilGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	return GI->getAllPlayerData();
}

void AVeilGameModeBase::updateGameState() {
	AVeilGameState* gs = GetWorld()->GetGameState<AVeilGameState>();
}