// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "BoxPlatform.h"

// Sets default values
ABoxPlatform::ABoxPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Collider->SetupAttachment(Mesh);

	Collider->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	Collider->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	Collider->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Ignore);

	ZAxisEnabledPosition = FVector();
	InterpSpeed = 4.f;
	StuckCollisionEnabled = false;
}

// Called when the game starts or when spawned
void ABoxPlatform::BeginPlay()
{
	Super::BeginPlay();

	m_ZAxisDisabledPosition = GetActorLocation();
	m_IsZAxisEnabled = false;
}

// Called every frame
void ABoxPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_IsZAxisEnabled)
	{
		FVector currentPosition = GetActorLocation();
		if ((currentPosition - (m_ZAxisDisabledPosition + ZAxisEnabledPosition)).Size() > 0.001f)
		{
			FVector Interp = FMath::VInterpTo(currentPosition, m_ZAxisDisabledPosition + ZAxisEnabledPosition, DeltaTime, InterpSpeed);

			SetActorLocation(Interp);
		}
	}
	else
	{
		FVector currentPosition = GetActorLocation();
		if ((currentPosition - m_ZAxisDisabledPosition).Size() > 0.001f)
		{
			FVector Interp = FMath::VInterpTo(currentPosition, m_ZAxisDisabledPosition, DeltaTime, InterpSpeed);
			SetActorLocation(Interp);
		}

		if (StuckCollisionEnabled)
		{
			TArray<FHitResult> hitResults;
			FCollisionShape colShape = FCollisionShape::MakeSphere(StuckCheckSphereRadius);

			bool hit = GetWorld()->SweepMultiByChannel(hitResults, GetActorLocation() + IsPlayerStuckAfterZAxisDisabledCheckPosition, GetActorLocation() + IsPlayerStuckAfterZAxisDisabledCheckPosition, FQuat::Identity, ECollisionChannel::ECC_Pawn, colShape);
			if (hit)
			{
				for (FHitResult hitResult : hitResults)
				{
					APlayerCharacter* playerCharacter = Cast<APlayerCharacter>(hitResult.Actor);
					if (playerCharacter && playerCharacter->IsAlive)
					{
						UE_LOG(LogTemp, Warning, TEXT("Player dead"));
						playerCharacter->IsAlive = false;
					}
				}
			}
		}
	}
}

