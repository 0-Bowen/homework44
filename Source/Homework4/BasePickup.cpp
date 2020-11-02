// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePickup.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Homework4Character.h"


// Sets default values
ABasePickup::ABasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//---------------------------------------------------------------------------------------------------------------------------Bowen Code Here

	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PICK ME UP"));
	RootComponent = PickupRoot;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PICK UP MESH COMP"));
	PickupMesh->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetIncludingScale);

	PickupCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("PICK UP COLLISION"));
	PickupCollision->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
	PickupCollision->SetCollisionProfileName("OverlapAll");
	PickupCollision->SetGenerateOverlapEvents(true);
	PickupCollision->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetIncludingScale);
	PickupCollision->OnComponentBeginOverlap.AddDynamic(this, &ABasePickup::OnCharacterOverlap);



}

// Called when the game starts or when spawned
void ABasePickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePickup::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

