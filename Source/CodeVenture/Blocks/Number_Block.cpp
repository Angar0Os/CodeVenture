// Fill out your copyright notice in the Description page of Project Settings.


#include "../Blocks/Number_Block.h"
#include "../Blocks/BlockManager.h"
#include "Components/BoxComponent.h"

// Sets default values
ANumber_Block::ANumber_Block()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));

	if (!ensure(TriggerVolume != nullptr)) return;

	RootComponent = TriggerVolume;

	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &ANumber_Block::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ANumber_Block::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANumber_Block::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANumber_Block::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	if (OtherActor == this)
		return;

	if (auto bm = FindComponentByClass<UBlockManager>(); bm != nullptr)
	{
		if (OtherActor->ActorHasTag("Block"))
		{
			Number_OverlapedActors.Add(OtherActor);
			OtherActor->SetActorEnableCollision(false);
			OtherActor->SetActorHiddenInGame(true);
		}
	}
}



