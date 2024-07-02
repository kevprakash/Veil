// Fill out your copyright notice in the Description page of Project Settings.


#include "VeilEquipmentBase.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AVeilEquipmentBase::AVeilEquipmentBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	abilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	abilitySystemComponent->SetIsReplicated(true);

	attributeSet = CreateDefaultSubobject<UVeilAttributeSet>(TEXT("AttributeSet"));

	mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));

	RootComponent = mesh;
}

void AVeilEquipmentBase::BeginPlay() {
	Super::BeginPlay();

	if (IsValid(abilitySystemComponent)) {
		abilitySystemComponent->InitAbilityActorInfo(this, this);
		attributeSet = abilitySystemComponent->GetSet<UVeilAttributeSet>();
	}
}

void AVeilEquipmentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(AVeilEquipmentBase, user, COND_None, REPNOTIFY_Always);
}
