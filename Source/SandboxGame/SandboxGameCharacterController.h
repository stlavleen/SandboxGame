// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SandboxGameCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class SANDBOXGAME_API ASandboxGameCharacterController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;
};
