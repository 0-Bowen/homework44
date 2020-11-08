// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePickup.h"
#include "Materials/Material.h"
#include "GameFramework/Actor.h"
#include "Question3.generated.h"

UCLASS()
class HOMEWORK4_API AQuestion3 : public ABasePickup
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestion3();

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
		UMaterial* aMaterial;
	
	UPROPERTY(EditAnywhere)
		UMaterial* bMaterial;

	UPROPERTY(EditAnywhere)
		int hp = 3;
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION()
	//virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};


