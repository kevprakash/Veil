// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VeilStructs.generated.h"

UENUM(BlueprintType)
enum class GamePhase : uint8 {
	PRE_ROUND UMETA(DisplayName = "Pre Round"),
	PREP UMETA(DisplayName = "Prep"),
	ACTION UMETA(DisplayName = "Action"),
	POST_PLANT UMETA(DisplayName = "Post Plant"),
	POST_ROUND UMETA(DisplayName = "Post Round")
};

UENUM(BlueprintType)
enum class EndReason : uint8 {
	TIMEOUT UMETA(DisplayName = "Timeout"),
	ELIMINATION UMETA(DisplayName = "Elimination"),
	OBJECTIVE UMETA(DisplayName = "Objective"),
};

UENUM(BlueprintType)
enum class WinConditions : uint8 {
	NONE				 UMETA(DisplayName = "None"),
	ATTACKERS_ELIMINATED UMETA(DisplayName = "Attackers Eliminated"),
	DEFENDERS_ELIMINATED UMETA(DisplayName = "Defenders Eliminated"),
	BOMB_DETONATED		 UMETA(DisplayName = "Bomb Detonated"),
	BOMB_DEFUSED		 UMETA(DisplayName = "Bomb Defused"),
	TIMEOUT				 UMETA(DisplayName = "Timeout")
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

	NONE UMETA(DisplayName = "None"),
	LASER_SIGHT UMETA(DisplayName = "Laser Sight"),
	RANGE_FINDER UMETA(DisplayName = "Range Finder")
};

UENUM(BlueprintType)
enum class Stock : uint8 {

	STANDARD UMETA(DisplayName = "Standard"),
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
	GunName name = GunName::TEST;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	Muzzle muzzle = Muzzle::NONE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	Grip grip = Grip::HORIZONTAL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	SideBarrel sideBarrel = SideBarrel::NONE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	Stock stock = Stock::STANDARD;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	Scope scope = Scope::x1;
};

USTRUCT(BlueprintType)
struct FLoadout {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGunData primary;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGunData secondary;
};

USTRUCT(BlueprintType)
struct FPLAYER_DATA {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int team = -1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool alive = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLoadout loadout;
};