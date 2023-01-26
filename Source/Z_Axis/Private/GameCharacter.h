// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameCharacter.generated.h"

UCLASS()
class AGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGameCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
		UStaticMeshComponent* BodyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Mesh)
		UStaticMeshComponent* DirectionPointer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		float JumpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		bool IsAlive;

	FORCEINLINE void SetIsZAxisEnabled(bool value)
	{
		m_IsZAxisEnabled = value;
	}

protected :

	virtual void MoveForward(float input);
	virtual void MoveRight(float input);
	virtual void EnableZAxis();
	virtual void DisableZAxis();

	FVector m_MoveDirection;
	bool m_IsZAxisEnabled;
};
