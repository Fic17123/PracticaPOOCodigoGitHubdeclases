// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "NewActorComponentBaul.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PRACTICASPOO_API UNewActorComponentBaul : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UNewActorComponentBaul();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(VisibleAnywhere)
	float Salud = 100.0f;
	void VerSalud();


};
