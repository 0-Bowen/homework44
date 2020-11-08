// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Homework4Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Hurt.h"
#include "Engine.h"
#include "Components/SphereComponent.h"

AHomework4Projectile::AHomework4Projectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AHomework4Projectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AHomework4Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 15.0f, GetActorLocation());
		GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Purple, FString::Printf(TEXT("111111111111111111111")));

		/*
		auto cubehurt = Cast<UHurt>(OtherActor);
		if (OtherActor->IsA(cubehurt))
		{
			GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Purple, FString::Printf(TEXT("222222222222222")));
			
		}
		//(cubehurt->hp == 0) &&
		OtherActor->Destroy();
		*/

		GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Purple, FString::Printf(TEXT("3333333333333333333")));
		Destroy();
	}
}

