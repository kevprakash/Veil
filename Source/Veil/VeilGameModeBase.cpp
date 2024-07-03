// Fill out your copyright notice in the Description page of Project Settings.

#include "VeilGameModeBase.h"
#include "VeilGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "VeilGameState.h"

void AVeilGameModeBase::OnPostLogin(AController* newPlayer) {
	UVeilGameInstance* GI = Cast<UVeilGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GI->registerPlayer(newPlayer);
}

void AVeilGameModeBase::HandleSeamlessTravelPlayer(AController*& newPlayer)
{
	FString levelName = GetWorld()->GetMapName();
	levelName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("" + levelName));

	if (levelName == "TestMap") {
		OnMatchLoadPlayer(newPlayer);
	}
}

TMap<AController*, FPLAYER_DATA> AVeilGameModeBase::getAllPlayerData() {
	UVeilGameInstance* GI = Cast<UVeilGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	return GI->getAllPlayerData();
}

AVeilGameModeBase::AVeilGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bUseSeamlessTravel = true;
}

void AVeilGameModeBase::updateGameState() {
	AVeilGameState* gs = GetWorld()->GetGameState<AVeilGameState>();
}

void AVeilGameModeBase::changePlayerTeam(AController* player, int newTeam) {
	UVeilGameInstance* GI = Cast<UVeilGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GI->updatePlayerTeam(player, newTeam);
}

int AVeilGameModeBase::getPlayerTeam(AController* player)
{
	UVeilGameInstance* GI = Cast<UVeilGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	return GI->getPlayerTeam(player);
}

void AVeilGameModeBase::startGame()
{
	GetWorld()->ServerTravel("/Game/Maps/TestMap?listen");
}
