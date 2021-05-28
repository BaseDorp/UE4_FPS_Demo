// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Projectile.generated.h"

UCLASS()
class FIRSTPERSONDEMO_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, Category = "Projectile")
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	UStaticMeshComponent* ProjectileMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void FireInDirection(const FVector& Direction);

};
