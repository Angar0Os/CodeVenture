// Fill out your copyright notice in the Description page of Project Settings.


#include "EnnemyAI.h"
#include "Kismet/GameplayStatics.h"
#include "EnnemyAIcontroler.h"
#include "Waypoint.h"

// Sets default values
AEnnemyAI::AEnnemyAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnnemyAI::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), AWaypoint::StaticClass(), WaypointName, Waypoints);
	MoveToWaypoints();
}

// Called every frame
void AEnnemyAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnnemyAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnnemyAI::MoveToWaypoints()
{
	AEnnemyAIcontroler* EnnemyAI = Cast<AEnnemyAIcontroler>(GetController());

	if (EnnemyAI)
	{
		if (CurrentWaypoint <= Waypoints.Num())
		{
			for (AActor* Waypoint : Waypoints)
			{
				AWaypoint* WaypointItr = Cast<AWaypoint>(Waypoint);

				if (WaypointItr)
				{
					if (WaypointItr->GetWaypointOrder() == CurrentWaypoint)
					{
						EnnemyAI->MoveToActor(WaypointItr, 5.0f);

						break;
					}
				}
			}
		}
	}
}

void AEnnemyAI::interpolation()
{
	CurrentWaypoint = (CurrentWaypoint + 1) % Waypoints.Num();
}



