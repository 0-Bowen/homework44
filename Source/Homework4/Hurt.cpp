// Fill out your copyright notice in the Description page of Project Settings.


#include "Hurt.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Homework4Projectile.h"
#include "ComponentHelper.h"

// Sets default values for this component's properties
UHurt::UHurt()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHurt::BeginPlay()
{
	Super::BeginPlay();

	// ...
	CubeMesh = Cast<UStaticMeshComponent>(ComponentHelper::GetComponentByName(GetOwner(), "Cube")); 
}


// Called every frame
void UHurt::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHurt::OnHit(UPrimitiveComponent* MyComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{

	auto bullet = Cast<AHomework4Projectile>(OtherActor);
	if ((bullet != nullptr))
	{	
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Red, FString::Printf(TEXT("Hit Cube")));
		}
		GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Red, FString::Printf(TEXT("Destory Bullet")));
		OtherActor->Destroy();
		

		hp--;

		if (hp == 2)
		{
			CubeMesh->SetMaterial(0, aMaterial);
		}
		else if (hp == 1)
		{
			CubeMesh->SetMaterial(0, bMaterial);
		}
			
		else if (hp == 0)
		{
			GEngine->AddOnScreenDebugMessage(-1, 4.0f, FColor::Red, FString::Printf(TEXT("Cube Died")));
			
			K2_DestroyComponent(this);
			
			//Destroy();

			// CubeMesh->DestroyComponent();
		}

		return;
	}

	/*	*/

}
