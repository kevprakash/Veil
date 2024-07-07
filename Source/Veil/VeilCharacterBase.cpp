// Fill out your copyright notice in the Description page of Project Settings.


#include "VeilCharacterBase.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AVeilCharacterBase::AVeilCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	abilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	abilitySystemComponent->SetIsReplicated(true);

	attributeSet = CreateDefaultSubobject<UVeilAttributeSet>(TEXT("AttributeSet"));

	
}

// Called when the game starts or when spawned
void AVeilCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(abilitySystemComponent)) {
		abilitySystemComponent->InitAbilityActorInfo(this, this);
		attributeSet = abilitySystemComponent->GetSet<UVeilAttributeSet>();
	}
}

// Called every frame
void AVeilCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVeilCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int AVeilCharacterBase::getTeam()
{
	return team;
}

void AVeilCharacterBase::setTeam(int newTeam)
{
	team = newTeam;
}

void AVeilCharacterBase::PossessedBy(AController* newController) 
{
	Super::PossessedBy(newController);

	SetOwner(newController);
}

void AVeilCharacterBase::GetLifetimeReplicatedProps(class TArray<class FLifetimeProperty>& OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AVeilCharacterBase, team);
}