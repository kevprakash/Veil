// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "VeilAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

#define REPLICATION_DEFINITION(PropertyName)\
	virtual void OnRep_##PropertyName(const FGameplayAttributeData& oldVal);

#define PROPERTY_DEFINITION(PropertyName)\
	ATTRIBUTE_ACCESSORS(UVeilAttributeSet, PropertyName);


UCLASS()
class VEIL_API UVeilAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:

	// Health Related

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	PROPERTY_DEFINITION(Health);
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, Health, oldVal);
	}


	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	PROPERTY_DEFINITION(MaxHealth);
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, MaxHealth, oldVal);
	}

	// Gun Related

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Bullets)
	FGameplayAttributeData Bullets;
	PROPERTY_DEFINITION(Bullets);
	UFUNCTION()
	virtual void OnRep_Bullets(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, Bullets, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MagazineSize)
	FGameplayAttributeData MagazineSize;
	PROPERTY_DEFINITION(MagazineSize);
	UFUNCTION()
	virtual void OnRep_MagazineSize(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, MagazineSize, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_FireRate)
	FGameplayAttributeData FireRate;
	PROPERTY_DEFINITION(FireRate);
	UFUNCTION()
	virtual void OnRep_FireRate(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, FireRate, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_SprayCounter)
	FGameplayAttributeData SprayCounter;
	PROPERTY_DEFINITION(SprayCounter);
	UFUNCTION()
	virtual void OnRep_SprayCounter(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, SprayCounter, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ADSTime)
	FGameplayAttributeData ADSTime;
	PROPERTY_DEFINITION(ADSTime);
	UFUNCTION()
	virtual void OnRep_ADSTime(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, ADSTime, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ReloadTime)
	FGameplayAttributeData ReloadTime;
	PROPERTY_DEFINITION(ReloadTime);
	UFUNCTION()
	virtual void OnRep_ReloadTime(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, ReloadTime, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ADSSpeed)
	FGameplayAttributeData ADSSpeed;
	PROPERTY_DEFINITION(ADSSpeed);
	UFUNCTION()
	virtual void OnRep_ADSSpeed(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, ADSSpeed, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ReloadSpeed)
	FGameplayAttributeData ReloadSpeed;
	PROPERTY_DEFINITION(ReloadSpeed);
	UFUNCTION()
	virtual void OnRep_ReloadSpeed(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, ReloadSpeed, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_DamageMultiplier)
	FGameplayAttributeData DamageMultiplier;
	PROPERTY_DEFINITION(DamageMultiplier);
	UFUNCTION()
	virtual void OnRep_DamageMultiplier(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, DamageMultiplier, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_RecoilXMultiplier)
	FGameplayAttributeData RecoilXMultiplier;
	PROPERTY_DEFINITION(RecoilXMultiplier);
	UFUNCTION()
	virtual void OnRep_RecoilXMultiplier(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, RecoilXMultiplier, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_RecoilYMultiplier)
	FGameplayAttributeData RecoilYMultiplier;
	PROPERTY_DEFINITION(RecoilYMultiplier);
	UFUNCTION()
	virtual void OnRep_RecoilYMultiplier(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, RecoilYMultiplier, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_InstabilityXMultiplier)
	FGameplayAttributeData InstabilityXMultiplier;
	PROPERTY_DEFINITION(InstabilityXMultiplier);
	UFUNCTION()
	virtual void OnRep_InstabilityXMultiplier(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, InstabilityXMultiplier, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_InstabilityYMultiplier)
	FGameplayAttributeData InstabilityYMultiplier;
	PROPERTY_DEFINITION(InstabilityYMultiplier);
	UFUNCTION()
	virtual void OnRep_InstabilityYMultiplier(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, InstabilityYMultiplier, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_GunshotNoiseMultiplier)
	FGameplayAttributeData GunshotNoiseMultiplier;
	PROPERTY_DEFINITION(GunshotNoiseMultiplier);
	UFUNCTION()
	virtual void OnRep_GunshotNoiseMultiplier(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, GunshotNoiseMultiplier, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_GunshotFlashMultiplier)
	FGameplayAttributeData GunshotFlashMultiplier;
	PROPERTY_DEFINITION(GunshotFlashMultiplier);
	UFUNCTION()
	virtual void OnRep_GunshotFlashMultiplier(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, GunshotFlashMultiplier, oldVal);
	}

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_ADSZoom)
	FGameplayAttributeData ADSZoom;
	PROPERTY_DEFINITION(ADSZoom);
	UFUNCTION()
	virtual void OnRep_ADSZoom(const FGameplayAttributeData& oldVal) {
		GAMEPLAYATTRIBUTE_REPNOTIFY(UVeilAttributeSet, ADSZoom, oldVal);
	}
};
