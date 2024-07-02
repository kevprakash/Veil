// Fill out your copyright notice in the Description page of Project Settings.


#include "VeilPlayerController.h"
#include "VeilCharacterBase.h"

void AVeilPlayerController::AcknowledgePossession(APawn* newPawn) {
	Super::AcknowledgePossession(newPawn);

	AVeilCharacterBase* characterBase = Cast<AVeilCharacterBase>(newPawn);
	if (characterBase) {
		characterBase->GetAbilitySystemComponent()->InitAbilityActorInfo(characterBase, characterBase);
	}
} 