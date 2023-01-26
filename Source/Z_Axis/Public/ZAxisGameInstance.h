// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ZAxisFSM.h"
#include "ZAxisGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class Z_AXIS_API UZAxisGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UZAxisGameInstance();

private :
	AZAxisFSM* ZAxisFSM;

public :
	FORCEINLINE void SetZAxisFSM(AZAxisFSM* fsm)
	{
		ZAxisFSM = fsm;
	}

	FORCEINLINE AZAxisFSM* GetZAxisFSM()
	{
		return ZAxisFSM;
	}
	
};
