// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ZAxisState.h"
#include "ZAxisEnabledState.generated.h"

/**
 * 
 */
UCLASS()
class Z_AXIS_API AZAxisEnabledState : public AZAxisState
{
	GENERATED_BODY()

public :
	AZAxisEnabledState();

	virtual void Init() override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnTick(float DeltaTime) override;
	
};
