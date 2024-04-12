// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Blocks/Cursor.h"

#include "../Blocks/CPP_BlockEMPTY.h"
#include "../Blocks/SequenceBlock.h"
#include "../Blocks/Number_Block.h"
#include "../Blocks/N_Block.h"


#include "Math/BoxSphereBounds.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BlockManager.generated.h"

UENUM(BlueprintType)
enum class Block_Type : uint8
{
	E_SPAWN_BLOCK = 0 UMETA(DisplayName = "Spawn"),
	E_NUMBER_BLOCK = 1 UMETA(DisplayName = "Number"),
	E_N_BLOCK = 2 UMETA(DisplayName = "N"),
	E_ARROW_BLOCK = 3 UMETA(DisplayName = "Arrow"),
	E_SEQUENCE_BLOCK = 4 UMETA(DisplayName = "Sequence"),
	E_EMPTY_BLOCK = 5 UMETA(DisplayName = "Empty"),
};
ENUM_CLASS_FLAGS(Block_Type);

UENUM(BlueprintType)
enum class Arrow_Direction : uint8
{
	ARROW_UP = 0 UMETA(DisplayName = "UP"),
	ARROW_DOWN = 1 UMETA(DisplayName = "DOWN"),
	ARROW_RIGHT = 2 UMETA(DisplayName = "RIGHT"),
	ARROW_LEFT = 3 UMETA(DisplayName = "LEFT"),
};
ENUM_CLASS_FLAGS(Arrow_Direction);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODEVENTURE_API UBlockManager : public UActorComponent
{
	GENERATED_BODY()
		
#pragma region DefineProperties

	UPROPERTY()
		ACPP_BlockEMPTY* BlockToSpawnRef;

	UPROPERTY()
		ASequenceBlock* SequenceBlockRef;
	
	UPROPERTY()
		AN_Block* N_BlockRef;
	
	UPROPERTY()
		ANumber_Block* Number_BlockRef;
	
	UPROPERTY()
		FBoxSphereBounds Bounds;

	UPROPERTY()
		FVector CursorLocation;

	UPROPERTY()
		FVector Bounds_Size;

	UPROPERTY()
		FVector SpawnLocation;
#pragma endregion

	


	
public:	
	// Sets default values for this component's properties
	UBlockManager();

	UPROPERTY(EditAnywhere, meta = (EditCondition = "BlockType == Block_Type::E_SEQUENCE_BLOCK", EditConditionHides))
		ACursor* Cursor = nullptr;

#pragma region PublicProperties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BlockType")
		Block_Type BlockType = Block_Type::E_SPAWN_BLOCK;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta = (EditCondition = "BlockType == Block_Type::E_ARROW_BLOCK", EditConditionHides))
		Arrow_Direction ArrowDirection = Arrow_Direction::ARROW_UP;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "BlockType == Block_Type::E_NUMBER_BLOCK", EditConditionHides))
		int32 Number = 0;
	
	


#pragma endregion

#pragma region DefineFunctions
	UFUNCTION()
		void NumberBlock(AActor* Actor);
	UFUNCTION()
		void SpawnBlock();
	UFUNCTION()
		void ArrowBlock(AActor* Actor);
	UFUNCTION(BlueprintCallable)
		void StartSequence(TArray<AActor*> ActorList, int i = 0);
	UFUNCTION()
		void N_Block(int NombreBoucles);
#pragma endregion
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
