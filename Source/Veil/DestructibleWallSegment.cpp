// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructibleWallSegment.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ADestructibleWallSegment::ADestructibleWallSegment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(mesh);
	mesh->SetIsReplicated(true);

	abilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	abilitySystemComponent->SetIsReplicated(true);

	attributeSet = CreateDefaultSubobject<UVeilAttributeSet>(TEXT("AttributeSet"));
	attributeSet->InitHealth(500.0f);
	attributeSet->InitMaxHealth(500.0f);
}