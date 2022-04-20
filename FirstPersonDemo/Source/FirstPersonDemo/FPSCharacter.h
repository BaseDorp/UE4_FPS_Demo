// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"
#include "FPSCharacter.generated.h"

UCLASS()
class FIRSTPERSONDEMO_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();


	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh; // Temporary since I don't have a skeletal mesh for the character
	UPROPERTY()
	USkeletalMeshComponent* ThirdPersonMesh; // TODO for when third person mode

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FVector MuzzleOffset;

	UPROPERTY(EditAnywhere, Category="Movement")
	float MovementSpeed;
	UPROPERTY(EditAnywhere, Category="Movement")
	float SprintMultiplier;
	UPROPERTY(VisibleAnywhere, Category="Movement")
	bool bSprinting;

	FTimerHandle FireRateTimerHandle;
	FTimerHandle RespawnTimerHandle;
	UPROPERTY()
	float respawnTime;
	UPROPERTY()
	float fireRate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<class AProjectile> ProjectileClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForwardBackward(float Value);
	UFUNCTION()
	void MoveRightLeft(float Value);
	
	UFUNCTION()
	void StartJump();
	UFUNCTION()
	void EndJump();

	UFUNCTION()
	void StartCrouch();
	UFUNCTION()
	void EndCrouch();

	UFUNCTION()
	void StartSprint();
	UFUNCTION()
	void StopSprint();

	UFUNCTION()
	void PrimaryFire();

	UFUNCTION()
	void Death();

	UFUNCTION()
	void Respawn();
};
