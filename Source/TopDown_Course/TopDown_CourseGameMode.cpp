// Copyright Epic Games, Inc. All Rights Reserved.

#include "TopDown_CourseGameMode.h"
#include "TopDown_CoursePlayerController.h"
#include "TopDown_CourseCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATopDown_CourseGameMode::ATopDown_CourseGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATopDown_CoursePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}