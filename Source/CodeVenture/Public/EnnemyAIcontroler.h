// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnnemyAIcontroler.generated.h"

/**
 * 
 */
UCLASS()
class CODEVENTURE_API AEnnemyAIcontroler : public AAIController
{
	GENERATED_BODY()

	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
};
