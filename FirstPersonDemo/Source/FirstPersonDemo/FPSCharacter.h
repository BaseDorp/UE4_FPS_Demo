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
	//UPROPERTY(VisibleAnywhere)
//	UMaterial DefaultMaterial;
	//UPROPERTY(VisibleAnywhere)
	//UMaterial DeadMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FVector MuzzleOffset;

	UPROPERTY(EditAnywhere, Category="Movement")
	float MovementSpeed;
	UPROPERTY(EditAnywhere, Category="Movement")
	float SprintMultiplier;
	UPROPERTY(VisibleAnywhere, Category="Movement")
	bool bSprinting;

	/*UPROPERTY(EditAnywhere, Category = "Movement")
	float Friction;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Acceleration;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxVelocity;*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
	TSubclassOf<class AProjectile> ProjectileClass;


	/// <summary>
	/// Calculates the acceleration for straffing
	/// </summary>
	/// <param name="AccelDir"> normalized direction that the player is moving to</param>
	/// <param name="prevVelocity"> current velocity of the player </param>
	/// <param name="accelerate"> the server-defined player acceleration value </param>
	/// <param name="maxVelocity"> the server-defined player max velocity </param>
	FVector Accelerate(FVector AccelDir, FVector prevVelocity, float accelerate, float maxVelocity);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// moves the character forwards/backwards
	UFUNCTION()
	void MoveForwardBackward(float Value);

	// moves the character left/right
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

	void Death();

	void Respawn();
};
