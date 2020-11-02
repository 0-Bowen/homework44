// Fill out your copyright notice in the Description page of Project Settings.


#include "MSPickup.h"
#include "Engine.h"
#include "Homework4Character.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMSPickup::AMSPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MSBoost = 2000.0;
	canBoost = false;
	
}

// Called when the game starts or when spawned
void AMSPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMSPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	if (canBoost)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, FString::Printf(TEXT("Timer started")));
		timeElapse = -DeltaTime;

		if (timeElapse <= 0.0f)
		{
			canBoost = false;
			GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, FString::Printf(TEXT("End boost")));
		}

	}
	*/
}

void AMSPickup::Boost(AActor* OtherActor)
{
	
}

void AMSPickup::OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AHomework4Character::StaticClass()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Green, FString::Printf(TEXT("Start Boost")));

		canBoost = true;
		auto character = Cast<AHomework4Character>(OtherActor);
		if (character != nullptr)
		{
			// float baseSpeed = character->GetCharacterMovement()->MaxWalkSpeed;
			character->GetCharacterMovement()->MaxWalkSpeed =+ MSBoost;
		}

		GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Red, FString::Printf(TEXT("5 Seconds")));

		if (timeElapse <= 5)
		{
			//character->GetCharacterMovement()->MaxWalkSpeed =- MSBoost;
		}

		//-----------------------------------------------------
		Destroy();
	}
}
