// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCharacter.h"

// Sets default values
AGameCharacter::AGameCharacter()
{
 	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Character Body Mesh"));
	BodyMesh->SetupAttachment(GetRootComponent());
	DirectionPointer = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Direction Pointer"));
	DirectionPointer->SetupAttachment(BodyMesh);

	JumpSpeed = 650.f;
}

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	m_MoveDirection = FVector(0.f);
	m_IsZAxisEnabled = false;

	GetCharacterMovement()->JumpZVelocity = JumpSpeed;
	IsAlive = true;
}

void AGameCharacter::MoveForward(float input)
{
	if (m_MoveDirection.Y == 0 && m_IsZAxisEnabled)
	{
		m_MoveDirection.X = input >= 0 ? input : -input;
		m_MoveDirection.Normalize();
		AddMovementInput(m_MoveDirection, input);
	}
}

void AGameCharacter::MoveRight(float input)
{
	m_MoveDirection.X = 0.f;
	m_MoveDirection.Y = input >= 0 ? input : -input;
	m_MoveDirection.Normalize();
	AddMovementInput(m_MoveDirection, input);

	if (input > 0)
	{
		FRotator rotation = FRotator(0.f);
		BodyMesh->SetWorldRotation(rotation);
	}
	else if (input < 0)
	{
		FRotator rotation = FRotator(0.f, 180.f, 0.f);
		BodyMesh->SetWorldRotation(rotation);
	}
}

void AGameCharacter::EnableZAxis()
{
	m_IsZAxisEnabled = true;
}

void AGameCharacter::DisableZAxis()
{
	m_IsZAxisEnabled = false;
}

void AGameCharacter::KillCharacter()
{
	
}

