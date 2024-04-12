// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "N_Block.generated.h"

UCLASS()
class CODEVENTURE_API AN_Block : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AN_Block();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Variables")
		TArray<AActor*> N_OverlapedActors;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* TriggerVolume;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
