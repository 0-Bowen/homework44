// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Homework4Character.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BasePickup.h"
#include "MSPickup.generated.h"

//class UCharacterMovementComponent* CharacterMovement = Cast<UCharacterMovementComponent>(Homework4Character->GetMaxWalkSpeed());

UCLASS()
class HOMEWORK4_API AMSPickup : public ABasePickup
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMSPickup();

	UPROPERTY(EditAnywhere)
		float MSBoost;

	////////////////////////////
	bool canBoost;
	FTimerHandle timer;
	float timeElapse = 5.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

	void OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	void Boost(AActor* OtherActor);

private:


	
};
