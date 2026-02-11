// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DeskLamp.generated.h"

UCLASS()
class SANDBOXGAME_API ADeskLamp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeskLamp();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DeskLamp;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Toggle;

	UPROPERTY(VisibleAnywhere)
	class UPointLightComponent* PointLight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void ToggleTheLight();

private:
	const TCHAR* DeskLampMeshPath = TEXT("StaticMesh'/Game/ExternalAssets/StaticMeshes/deskLamp_DeskLamp.deskLamp_DeskLamp'");
	const TCHAR* ToggleMeshPath = TEXT("StaticMesh'/Game/ExternalAssets/StaticMeshes/deskLamp_Toggle.deskLamp_Toggle'");

private:
	void InitializeDeskLampComponents();
	void BuildComponentsHierarchy();
	void SetSMComponent(UStaticMeshComponent* component, const TCHAR* smPath);
};
