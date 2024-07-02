// Fill out your copyright notice in the Description page of Project Settings.


#include "VeilAttributeSet.h"
#include "Net/UnrealNetwork.h"

#define REPLICATION_FUNCTION(PropertyName)\
	FORCEINLINE void UVeilAttributeSet::OnRep_##PropertyName(const FGameplayAttributeData& oldVal)\
	{\
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, PropertyName, oldVal);\
	}\

#define DRLCN(PropertyName)\
	DOREPLIFETIME_CONDITION_NOTIFY(UVeilAttributeSet, PropertyName, COND_None, REPNOTIFY_Always);

REPLICATION_FUNCTION(Health)
REPLICATION_FUNCTION(MaxHealth)

REPLICATION_FUNCTION(Bullets)
REPLICATION_FUNCTION(MagazineSize)
REPLICATION_FUNCTION(FireRate)
REPLICATION_FUNCTION(SprayCounter)

REPLICATION_FUNCTION(ADSTime)
REPLICATION_FUNCTION(ReloadTime)
REPLICATION_FUNCTION(ADSSpeed)
REPLICATION_FUNCTION(ReloadSpeed)
REPLICATION_FUNCTION(DamageMultiplier)
REPLICATION_FUNCTION(RecoilXMultiplier)
REPLICATION_FUNCTION(RecoilYMultiplier)
REPLICATION_FUNCTION(InstabilityXMultiplier)
REPLICATION_FUNCTION(InstabilityYMultiplier)
REPLICATION_FUNCTION(GunshotNoiseMultiplier)
REPLICATION_FUNCTION(GunshotFlashMultiplier)
REPLICATION_FUNCTION(ADSZoom)


void UVeilAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DRLCN(Health);
	DRLCN(MaxHealth);
	DRLCN(Bullets);
	DRLCN(MagazineSize);
	DRLCN(FireRate);
	DRLCN(SprayCounter);
	DRLCN(ADSTime);
	DRLCN(ReloadTime);
	DRLCN(ADSSpeed);
	DRLCN(ReloadSpeed);
	DRLCN(DamageMultiplier);
	DRLCN(RecoilXMultiplier);
	DRLCN(RecoilYMultiplier);
	DRLCN(InstabilityXMultiplier);
	DRLCN(InstabilityYMultiplier);
	DRLCN(GunshotNoiseMultiplier);
	DRLCN(GunshotFlashMultiplier);
	DRLCN(ADSZoom);
}


