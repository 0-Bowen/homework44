// Fill out your copyright notice in the Description page of Project Settings.


#include "Question3.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AQuestion3::AQuestion3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void AQuestion3::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuestion3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


