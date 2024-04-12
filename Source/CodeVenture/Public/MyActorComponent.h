// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODEVENTURE_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, category = "Waypoints")
	AActor* FirstWaypoints;

	UPROPERTY(EditAnywhere, category = "Waypoints")
	AActor* SecondWaypoints;

	UPROPERTY(EditAnywhere)
		AActor* Ennemy;

	UPROPERTY()
		FVector Location;

	UFUNCTION()
	void EnnemyInterpolate();

public:	
	// Sets default values for this component's properties
	UMyActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
