// Fill out your copyright notice in the Description page of Project Settings.


#include "../Blocks/BlockManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UBlockManager::UBlockManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBlockManager::BeginPlay()
{
	Super::BeginPlay();

	// ...

	Cursor = Cast<ACursor>(UGameplayStatics::GetActorOfClass(GetWorld(), ACursor::StaticClass()));
	BlockToSpawnRef = Cast<ACPP_BlockEMPTY>(UGameplayStatics::GetActorOfClass(GetWorld(), ACPP_BlockEMPTY::StaticClass()));
	
	SequenceBlockRef = Cast<ASequenceBlock>(UGameplayStatics::GetActorOfClass(GetWorld(), ASequenceBlock::StaticClass()));
	N_BlockRef = Cast<AN_Block>(UGameplayStatics::GetActorOfClass(GetWorld(), AN_Block::StaticClass()));
	Number_BlockRef = Cast<ANumber_Block>(UGameplayStatics::GetActorOfClass(GetWorld(), ANumber_Block::StaticClass()));
	
	Bounds = BlockToSpawnRef->GetComponentsBoundingBox();
	Bounds_Size = Bounds.BoxExtent;

	CursorLocation = Cursor->GetActorLocation();
	
}


// Called every frame
void UBlockManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//... Switch on block_type to define different block comportements ...//
}


void UBlockManager::N_Block(int NombreBoucles)
{
	for (AActor* actor : N_BlockRef->N_OverlapedActors)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, FString::Printf(TEXT("coucou")));
		for (int32 i = 0; i <= NombreBoucles; ++i)
		{
			StartSequence(N_BlockRef->N_OverlapedActors, i);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("Actor: %s"), *actor->GetName()));
		}
	}
		

}

void UBlockManager::NumberBlock(AActor* Actor)
{
	if (auto bm = Actor->FindComponentByClass<UBlockManager>(); bm != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("BM not null"));
		
		for (AActor* Actor : Number_BlockRef->Number_OverlapedActors)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("One actor at least"));
			for (int32 i = 0; i <= bm->Number; ++i)
			{  
				StartSequence(Number_BlockRef->Number_OverlapedActors, 1);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Actor: %s"), *Actor->GetName()));
			}
		}
	}
}


void UBlockManager::SpawnBlock()
{
	// ... If block is a number block, spawn the number of blocks defined by the number variable ... //
	if (BlockToSpawnRef && Cursor)
	{
		ACPP_BlockEMPTY* block = GetWorld()->SpawnActor<ACPP_BlockEMPTY>(BlockToSpawnRef->GetClass(), CursorLocation, FRotator::ZeroRotator);
		block->Tags.Add("spawnedBlock");
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, TEXT("HAS SPAWN BLOCK"));
	}

}

void UBlockManager::ArrowBlock(AActor* Actor)
{
	//...If block is an arrow block, move the cursor in the direction of the arrow ...//

	if (Cursor != nullptr)
	{
		if (auto bm = Actor->FindComponentByClass<UBlockManager>(); bm != nullptr)
		{
			switch (bm->ArrowDirection)
			{
			case Arrow_Direction::ARROW_UP:
				Cursor->SetActorLocation
				(FVector(Cursor->GetActorLocation().X, Cursor->GetActorLocation().Y, Cursor->GetActorLocation().Z + 75));
				break;
			case Arrow_Direction::ARROW_DOWN:
				Cursor->SetActorLocation
				(FVector(Cursor->GetActorLocation().X, Cursor->GetActorLocation().Y, Cursor->GetActorLocation().Z - 75));
				break;
			case Arrow_Direction::ARROW_RIGHT:
				Cursor->SetActorLocation
				(FVector(Cursor->GetActorLocation().X, Cursor->GetActorLocation().Y + 75, Cursor->GetActorLocation().Z));
				break;
			case Arrow_Direction::ARROW_LEFT:
				Cursor->SetActorLocation
				(FVector(Cursor->GetActorLocation().X, Cursor->GetActorLocation().Y -75, Cursor->GetActorLocation().Z));
				break;
			default:
				break;
			}
			CursorLocation = Cursor->GetActorLocation();
		}
	}
}

void UBlockManager::StartSequence(TArray<AActor*> ActorsList, int i)
{
	for (AActor* Actor : ActorsList)
	{	
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("SEQUENCE"));
		if (auto bm = Actor->FindComponentByClass<UBlockManager>(); bm != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("CHECK ACTOR"));
			
			switch (bm->BlockType)
			{
			case Block_Type::E_ARROW_BLOCK: 
				ArrowBlock(Actor);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("ARROW"));
				break;
			case Block_Type::E_SPAWN_BLOCK:
				SpawnBlock();
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("SPAWN"));
				break;
			case Block_Type::E_NUMBER_BLOCK:
				NumberBlock(Actor);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("NUMBER"));
				break;
			case Block_Type::E_N_BLOCK:
				N_Block(i);
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("N"));
				break;
			default:
				break;
			}
		}
	}
}


