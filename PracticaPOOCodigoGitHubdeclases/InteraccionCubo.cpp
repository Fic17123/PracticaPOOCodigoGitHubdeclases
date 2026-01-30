// Fill out your copyright notice in the Description page of Project Settings.


#include "InteraccionCubo.h"
#include "Engine/World.h" 

// Sets default values for this component's properties
UInteraccionCubo::UInteraccionCubo()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInteraccionCubo::BeginPlay()
{
	Super::BeginPlay();
	cube = GetOwner();
	actorColisiona = GetWorld()->GetFirstPlayerController()->GetPawn();
	cube->SetActorHiddenInGame(true);

	// ...

}


// Called every frame
void UInteraccionCubo::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (caja->IsOverlappingActor(actorColisiona))
		cube->SetActorHiddenInGame(false);
	else
		cube->SetActorHiddenInGame(true);

	// ...
}

