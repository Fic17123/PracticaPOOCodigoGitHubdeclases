// Fill out your copyright notice in the Description page of Project Settings.


#include "NewActorComponentBaul.h"

// Sets default values for this component's properties
UNewActorComponentBaul::UNewActorComponentBaul()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UNewActorComponentBaul::BeginPlay()
{

	UE_LOG(LogTemp, Warning, TEXT("Holaaaa es el componente baúl"))
		VerSalud();
	Super::BeginPlay();

	// ...

}




// Called every frame
void UNewActorComponentBaul::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UNewActorComponentBaul::VerSalud()
{
	UE_LOG(LogTemp, Warning, TEXT("El valor de la variable es : % f"), Salud)
}

