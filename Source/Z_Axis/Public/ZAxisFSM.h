// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ZAxisDisabledState.h"
#include "ZAxisEnabledState.h"
#include "BoxPlatform.h"
#include "GameCharacter.h"
#include "ZAxisFSM.generated.h"

UCLASS()
class Z_AXIS_API AZAxisFSM : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AZAxisFSM();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ZAxisStates")
		TArray<AZAxisState*> ZAxisStatesArray;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ZAxisStates")
		AZAxisState* CurrentState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "BoxPlatforms")
		TArray<ABoxPlatform*> BoxPlatformArray;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GameCharacters")
		TArray<AGameCharacter*> GameCharacterArray;

	void ChangeStateTo(EZAxisStateEnum newState);

};
