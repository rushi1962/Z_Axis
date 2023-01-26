// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"
#include "BoxPlatform.generated.h"

UCLASS()
class ABoxPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoxPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Mesh)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Collider)
		UBoxComponent* Collider;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
		FVector ZAxisEnabledPosition;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"), Category = ZAxisDisabled)
		FVector IsPlayerStuckAfterZAxisDisabledCheckPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ZAxisDisabled)
		bool StuckCollisionEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = ZAxisDisabled)
		float StuckCheckSphereRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Interpolation)
		float InterpSpeed;

	FORCEINLINE void SetZAxisEnabled(bool zAxisEnabled)
	{
		m_IsZAxisEnabled = zAxisEnabled;
	}

	FORCEINLINE bool GetZAxisEnabled()
	{
		return m_IsZAxisEnabled;
	}

private:
	bool m_IsZAxisEnabled;
	FVector m_ZAxisDisabledPosition;
};
