// Fill out your copyright notice in the Description page of Project Settings.


#include "EnnemyAIcontroler.h"
#include "EnnemyAI.h"

void AEnnemyAIcontroler::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	AEnnemyAI* EnnemyAI = Cast<AEnnemyAI>(GetPawn());

	if (EnnemyAI)
	{
		EnnemyAI->interpolation();
		EnnemyAI->MoveToWaypoints();
	}
}
