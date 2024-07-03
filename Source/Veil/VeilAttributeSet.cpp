// Fill out your copyright notice in the Description page of Project Settings.


#include "VeilAttributeSet.h"
#include "Net/UnrealNetwork.h"

#define DRLCN(PropertyName)\
	DOREPLIFETIME_CONDITION_NOTIFY(UVeilAttributeSet, PropertyName, COND_None, REPNOTIFY_Always);


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


