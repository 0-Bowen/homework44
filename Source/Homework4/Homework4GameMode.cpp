// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Homework4GameMode.h"
#include "Homework4HUD.h"
#include "Homework4Character.h"
#include "UObject/ConstructorHelpers.h"

AHomework4GameMode::AHomework4GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHomework4HUD::StaticClass();
}
