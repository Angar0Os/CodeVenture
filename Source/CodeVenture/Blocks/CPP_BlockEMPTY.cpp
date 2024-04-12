// Fill out your copyright notice in the Description page of Project Settings.


#include "../Blocks/CPP_BlockEMPTY.h"

// Sets default values
ACPP_BlockEMPTY::ACPP_BlockEMPTY()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPP_BlockEMPTY::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_BlockEMPTY::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

