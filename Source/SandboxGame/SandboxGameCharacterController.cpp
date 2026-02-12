// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxGameCharacterController.h"
#include "DeskLamp.h"

void ASandboxGameCharacterController::SetupDeskLampInput(ADeskLamp* deskLamp)
{
	InputComponent->BindAction("TestDeskLamp", EInputEvent::IE_Pressed, deskLamp, &ADeskLamp::ToggleTheLight);
}
