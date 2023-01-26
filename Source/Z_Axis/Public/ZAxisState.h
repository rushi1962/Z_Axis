// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ZAxisState.generated.h"

UENUM()
enum EZAxisStateEnum
{
	ZAxisEnabled UMETA(DisplayName = "ZAxisEnabled"),
	ZAxisDisabled UMETA(DisplayName = "ZAxisDisabled")
};

UCLASS()
class Z_AXIS_API AZAxisState : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZAxisState();

	EZAxisStateEnum ZAxisStateEnum;
	
	virtual void Init();
	virtual void OnEnter();
	virtual void OnExit();
	virtual void OnTick(float DeltaTime);

};
