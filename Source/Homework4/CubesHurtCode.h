// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Materials/Material.h"
#include "CubesHurtCode.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HOMEWORK4_API UCubesHurtCode : public UActorComponent
{
	GENERATED_BODY()

		UFUNCTION()
		
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Sets default values for this component's properties
	UCubesHurtCode();

	UPROPERTY(EditAnywhere)
		UMaterial* OnMaterial1;

	UPROPERTY(EditAnywhere)
		UMaterial* OffMaterial2;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
