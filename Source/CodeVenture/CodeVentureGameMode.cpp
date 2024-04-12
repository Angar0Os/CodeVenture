// Copyright Epic Games, Inc. All Rights Reserved.

#include "CodeVentureGameMode.h"
#include "CodeVentureCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACodeVentureGameMode::ACodeVentureGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
