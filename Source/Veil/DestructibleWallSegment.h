// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemComponent.h"
#include "VeilAttributeSet.h"
#include "Components/StaticMeshComponent.h"
#include "DestructibleWallSegment.generated.h"

UCLASS()
class VEIL_API ADestructibleWallSegment : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADestructibleWallSegment();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* abilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = "true"))
	UVeilAttributeSet* attributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* mesh;

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Reset();
};
