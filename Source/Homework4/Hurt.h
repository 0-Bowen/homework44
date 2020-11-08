// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Hurt.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOMEWORK4_API UHurt : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	 UHurt();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CubeMesh;

	UPROPERTY(EditAnywhere)
	UMaterial* aMaterial;

	UPROPERTY(EditAnywhere)
	UMaterial* bMaterial;

	UPROPERTY(EditAnywhere)
	int hp = 3;

	float HitValue;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
		virtual void OnHit(UPrimitiveComponent* MyComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit);

	
	// UFUNCTION(BlueprintCallable)
		// virtual void OnComponentHit()
};
