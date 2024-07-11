// Fill out your copyright notice in the Description page of Project Settings.

#include "VeilGameModeBase.h"
#include "VeilGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "VeilPlayerController.h"
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

void AVeilGameModeBase::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	AVeilGameState* gs = GetWorld()->GetGameState<AVeilGameState>();
	gs->phaseTimer -= deltaTime;

	if (gs->phaseTimer <= 0.0f) {
		gs->phaseTimer = 0.0f;
		if (shouldPhaseEnd(EndReason::TIMEOUT)) { 
			if (gs->phase == GamePhase::ACTION) {
				gs->setWinCondition(WinConditions::TIMEOUT);
			}
			endPhase();
		}
	}
}

TArray<AVeilPlayerController*> AVeilGameModeBase::getPlayersOnTeam(int team)
{
	TArray<AVeilPlayerController*> ret;
	auto playerData = getAllPlayerData();
	for (auto pd : playerData) {
		if (pd.Value.team == team) {
			ret.Add(Cast<AVeilPlayerController>(pd.Key));
		}
	}
	return ret;
}

void AVeilGameModeBase::resetPlayerData()
{
	UVeilGameInstance* GI = Cast<UVeilGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GI->resetPlayerData();
}

void AVeilGameModeBase::giveRoundWin(int team)
{
	AVeilGameState* gs = GetWorld()->GetGameState<AVeilGameState>();
	if (team == 0) {
		gs->attackerRounds += 1;
	}
	else {
		gs->defenderRounds += 1;
	}
}

TMap<AController*, FPLAYER_DATA> AVeilGameModeBase::getAllPlayerData() {
	UVeilGameInstance* GI = Cast<UVeilGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	return GI->getAllPlayerData();
}

AVeilGameModeBase::AVeilGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bUseSeamlessTravel = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
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

void AVeilGameModeBase::setPlayerLife(AController* player, bool alive, bool force) {
	UVeilGameInstance* GI = Cast<UVeilGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	bool lifeChanged = GI->updatePlayerLife(player, alive);
	if (force || lifeChanged) {
		AVeilGameState* gs = GetWorld()->GetGameState<AVeilGameState>();
		auto pc = Cast<APlayerController>(player);
		int team = gs->getTeam(pc);
		int delta = alive ? 1 : -1;
		if (team == 0) {
			gs->attackerAlive += delta;
			if (gs->attackerAlive <= 0) {
				if (shouldPhaseEnd(EndReason::ELIMINATION)) {
					gs->setWinCondition(WinConditions::ATTACKERS_ELIMINATED);
				}
			}
		}
		else {
			gs->defenderAlive += delta;
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("" + FString::FromInt(gs->defenderAlive)));
			if (gs->defenderAlive <= 0) {
				if (shouldPhaseEnd(EndReason::ELIMINATION)) {
					gs->setWinCondition(WinConditions::DEFENDERS_ELIMINATED);
				}
			}
		}
	}
}

void AVeilGameModeBase::setPlayerLoadout(AController* player, FLoadout loadout)
{
	UVeilGameInstance* GI = Cast<UVeilGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GI->updatePlayerLoadout(player, loadout);
}

void AVeilGameModeBase::endPhase()
{
	AVeilGameState* gs = GetWorld()->GetGameState<AVeilGameState>();
	GamePhase gamePhase = gs->phase;
	switch (gamePhase) {
	case GamePhase::PRE_ROUND:
		setRoundPhase(GamePhase::PREP);
		break;
	case GamePhase::PREP:
		setRoundPhase(GamePhase::ACTION);
		break;
	case GamePhase::ACTION:
		if (gs->bombPlanted) {
			setRoundPhase(GamePhase::POST_PLANT);
		}
		else {
			setRoundPhase(GamePhase::POST_ROUND);
		}
		break;
	case GamePhase::POST_PLANT:
		setRoundPhase(GamePhase::POST_ROUND);
		break;
	case GamePhase::POST_ROUND:
		setRoundPhase(GamePhase::PRE_ROUND);
		break;
	}
}

void AVeilGameModeBase::setRoundPhase(GamePhase phase)
{
	AVeilGameState* gs = GetWorld()->GetGameState<AVeilGameState>();
	gs->phase = phase;
	switch(phase) {
	case GamePhase::PRE_ROUND:
		resetRound();
		gs->winCondition = WinConditions::NONE;
		break;
	case GamePhase::PREP:
		spawnDefenders();
		break;
	case GamePhase::ACTION:
		spawnAttackers();
		break;
	case GamePhase::POST_PLANT:
		gs->bombPlanted = true;
		break;
	case GamePhase::POST_ROUND:
		endRound();
		gs->bombPlanted = false;
		switch (gs->winCondition) {
		case WinConditions::TIMEOUT:
			giveRoundWin(1);
			break;
		case WinConditions::BOMB_DEFUSED:
			giveRoundWin(1);
			break;
		case WinConditions::ATTACKERS_ELIMINATED:
			giveRoundWin(1);
			break;
		case WinConditions::DEFENDERS_ELIMINATED:
			giveRoundWin(0);
			break;
		case WinConditions::BOMB_DETONATED:
			giveRoundWin(0);
			break;
		}
		break;
	}

	gs->phaseTimer = phaseLengths[phase];
}
