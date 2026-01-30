// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include <Camera/CameraComponent.h> 
#include <Components/InputComponent.h> 

// Sets default values
AMyPawn::AMyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	//crear componente raiz
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//crear subobjetos
	UCameraComponent* camara = CreateDefaultSubobject<UCameraComponent>(TEXT("Camara"));
	VisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visible"));
	//adjuntar los subojetos a la raiz
	camara->SetupAttachment(RootComponent);
	camara->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	camara->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	VisibleComponent->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Manejar la escala
	float EscalaActual = VisibleComponent->GetComponentScale().X;
	if (crecer)
	{
		EscalaActual += DeltaTime;
	}
	else
	{
		EscalaActual -= (DeltaTime * 0.5f);
	}
	//escala oscila entre 1 y el maximo doble
	EscalaActual = FMath::Clamp(EscalaActual, 1.0f, 2.0f);
	VisibleComponent->SetWorldScale3D(FVector(EscalaActual));
	//Maneja el movimiento basado en moverx, movery
	if (!VelocidadActual.IsZero())
	{
		FVector NuevaPosicion = GetActorLocation() + (VelocidadActual * DeltaTime);

		SetActorLocation(NuevaPosicion);
	}

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Accion responde cuando se preciona la barra espaciadora o se suelta
	InputComponent->BindAction("Aumentar", IE_Pressed, this, &AMyPawn::inicioAumento);
	InputComponent->BindAction("Aumentar", IE_Released, this, &AMyPawn::finAumento);
	//Eje responde cuando se mueve en el eje x o y
	InputComponent->BindAxis("MoverX", this, &AMyPawn::MoverEjeX);
	InputComponent->BindAxis("MoverY", this, &AMyPawn::MoverEjeY);


}

void AMyPawn::MoverEjeX(float valorEje)
{
	VelocidadActual.X = FMath::Clamp(valorEje, -1.0f, 1.0f) * 100.0f;
}

void AMyPawn::MoverEjeY(float valorEje)
{
	VelocidadActual.Y = FMath::Clamp(valorEje, -1.0f, 1.0f) * 100.0f;
}

void AMyPawn::inicioAumento()
{
	crecer = true;
}

void AMyPawn::finAumento()
{
	crecer = false;
}

