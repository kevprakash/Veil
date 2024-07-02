// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VeilStructs.generated.h"

USTRUCT(BlueprintType)
struct FPLAYER_DATA {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int team;
};

UENUM(BlueprintType)
enum class GunName : uint8 {

	TEST UMETA(DisplayName = "TEST"),
};

UENUM(BlueprintType)
enum class Muzzle : uint8 {

	NONE UMETA(DisplayName = "None"),
	FLASH_HIDER UMETA(DisplayName = "Flash Hider"),
	COMPENSATOR UMETA(DisplayName = "Compensator"),
	MUZZLE_BRAKE UMETA(DisplayName = "Muzzle Break"),
	EXTENDED_BARREL UMETA(DisplayName = "Extended Barrel"),
	SUPPRESSOR UMETA(DisplayName = "Suppressor")
};

UENUM(BlueprintType)
enum class Grip : uint8 {

	HORIZONTAL UMETA(DisplayName = "Horizontal"),
	VERTICAL  UMETA(DisplayName = "Vertical"),
	ANGLED UMETA(DisplayName = "Angled"),
	STUBBY UMETA(DisplayName = "Stubby")
};

UENUM(BlueprintType)
enum class SideBarrel : uint8 {

	None UMETA(DisplayName = "None"),
	LASER_SIGHT UMETA(DisplayName = "Laser Sight"),
	RANGE_FINDER UMETA(DisplayName = "Range Finder")
};

UENUM(BlueprintType)
enum class Stock : uint8 {

	Standard UMETA(DisplayName = "Standard"),
	HEAVY_DUTY UMETA(DisplayName = "Heavy Duty"),
	LIGHT UMETA(DisplayName = "Light"),
	NONE UMETA(DisplayName = "None")
};

UENUM(BlueprintType)
enum class Scope : uint8 {

	x1 UMETA(DisplayName = "1x"),
	x2_5 UMETA(DisplayName = "2.5x"),
	x4 UMETA(DisplayName = "4x"),
	x8 UMETA(DisplayName = "8x"),
};

USTRUCT(BlueprintType)
struct FGunData {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	GunName name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	Muzzle muzzle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	Grip grip;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	SideBarrel sideBarrel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	Stock stock;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	Scope scope;
};

USTRUCT(BlueprintType)
struct FLoadOut {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGunData primary;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGunData secondary;
};