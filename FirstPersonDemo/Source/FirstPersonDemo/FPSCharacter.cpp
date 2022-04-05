// Fill out your copyright notice in the Description page of Project Settings.
/* 
	Accelerate code derived from http://adrianb.io/2015/02/14/bunnyhop.html
*/

#include "FPSCharacter.h"
#include "DrawDebugHelpers.h"
#include "Misc/App.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "Math/UnrealMathUtility.h"


// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Camera
	//Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	//check(Camera != nullptr);

	// Setup Camera
	//Camera->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	// Set default camera height (this is slightly above eye height)
	//Camera->SetRelativeLocation(FVector(0, 0, 50 + BaseEyeHeight));

	//Camera->bUsePawnControlRotation = true; // Allows the camera rotation control

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Player Mesh"));

	// Default Movement Variables
	/*Acceleration = 10.0f;
	Friction = 0.0f;
	MaxVelocity = 50.0f;*/

	JumpMaxCount = 2;
	SprintMultiplier = 1.5f;
	bSprinting = false;
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// TODO check for player velocity to be zero, if sprinting, then stop sprinting


#if WITH_EDITOR
	//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Yellow, FString::Printf(TEXT("%s"), this->GetVelocity().Size())); // Crashes editor
#endif // WITH_EDITOR
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	// Setup bindings
	PlayerInputComponent->BindAxis("MoveForwardBackward", this, &AFPSCharacter::MoveForwardBackward);
	PlayerInputComponent->BindAxis("MoveRightLeft", this, &AFPSCharacter::MoveRightLeft);
	PlayerInputComponent->BindAxis("LookUpDown", this, &AFPSCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRightLeft", this, &AFPSCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::EndJump);
	PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AFPSCharacter::StartCrouch);
	PlayerInputComponent->BindAction("Crouch", IE_Released, this, &AFPSCharacter::EndCrouch);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AFPSCharacter::StartSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFPSCharacter::StopSprint);
	PlayerInputComponent->BindAction("PrimaryFire", IE_Pressed, this, &AFPSCharacter::PrimaryFire);
}

void AFPSCharacter::MoveForwardBackward(float Value)
{
	// Find the forward vector
	/*FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	FVector Velocity = GetVelocity();*/

	//if (AFPSCharacter::GetCharacterMovement()->IsMovingOnGround())
	//{
	//	float speed = GetVelocity().Size();
	//	if (speed != 0) // avoids n/0
	//	{
	//		float drop = speed * Friction * GetWorld()->GetDeltaSeconds(); // * Time.fixedDeltaTime
	//		Velocity *= FMath::Max(speed - drop, 0.0f) / speed;
	//	}

	//	Direction = Accelerate(Direction, Velocity, Acceleration, MaxVelocity); // might have to be groundAcceleration and maxGroundVelocity?
	//}
	//else // MovesAir Function
	//{
	//	Direction = Accelerate(Direction, Velocity, Acceleration, MaxVelocity); // might have to be airAcceleration and maxAirVelocity?
	//}

	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFPSCharacter::MoveRightLeft(float Value)
{
	/*FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	FVector Velocity = GetVelocity();*/

	//if (AFPSCharacter::GetCharacterMovement()->IsMovingOnGround())
	//{
	//	float speed = GetVelocity().Size();
	//	if (speed != 0) // avoids n/0
	//	{
	//		float drop = speed * Friction * GetWorld()->GetDeltaSeconds(); // * Time.fixedDeltaTime
	//		Velocity *= FMath::Max(speed - drop, 0.0f) / speed;
	//	}

	//	Direction = Accelerate(Direction, Velocity, Acceleration, MaxVelocity); // might have to be groundAcceleration and maxGroundVelocity?
	//}
	//else // MovesAir Function
	//{
	//	Direction = Accelerate(Direction, Velocity, Acceleration, MaxVelocity); // might have to be airAcceleration and maxAirVelocity?
	//}

	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

// accelDir: normalized direction that the player has requested to move (taking into account the movement keys and look direction)
// prevVelocity: The current velocity of the player, before any additional calculations
// accelerate: The server-defined player acceleration value
// max_velocity: The server-defined maximum player velocity (this is not strictly adhered to due to strafejumping)
//FVector MoveGround(FVector accelDir, FVector prevVelocity, float DeltaTime)
//{
//	// Apply Friction
//	float speed = prevVelocity.Size();
//	if (speed != 0) // To avoid divide by zero errors
//	{
//		float drop = speed * friction * DeltaTime;
//		prevVelocity *= std::max(speed - drop, 0.0f) / speed; // Scale the velocity based on friction.
//	}
//
//	// ground_accelerate and max_velocity_ground are server-defined movement variables
//	return Accelerate(accelDir, prevVelocity, ground_accelerate, max_velocity_ground);
//}
//
//FVector MoveAir(FVector accelDir, FVector prevVelocity)
//{
//	// air_accelerate and max_velocity_air are server-defined movement variables
//	return Accelerate(accelDir, prevVelocity, air_accelerate, max_velocity_air);
//}

FVector AFPSCharacter::Accelerate(FVector AccelDir, FVector prevVelocity, float accelerate, float maxVelocity)
{
	// Vector projection from Current Velocity onto Acceleration Direction
	float projVelocity = Dot3(prevVelocity, AccelDir);
	// Accelerated Velocity in direction of movement
	float accelVelocity = accelerate * GetWorld()->GetTimeSeconds(); // TODO time.deltatimefixed?

	// Makes sure character doesn't exceed Max Velocity
	if (projVelocity + accelVelocity > maxVelocity)
	{ accelVelocity = maxVelocity - projVelocity; }

	return prevVelocity + AccelDir * accelVelocity;
}

void AFPSCharacter::StartJump()
{
	Jump();
}

void AFPSCharacter::EndJump()
{
	bPressedJump = false;
}

void AFPSCharacter::StartCrouch()
{
	Crouch();
}

void AFPSCharacter::EndCrouch()
{
	UnCrouch();
}

void AFPSCharacter::StartSprint()
{
	/*if (bSprinting || CharacterMovement->Velocity <= 1)
	{
		GetCharacterMovement()->MaxWalkSpeed /= SprintMultiplier;
		bSprinting = false;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed *= SprintMultiplier;
		bSprinting = true;
	}*/

	GetCharacterMovement()->MaxWalkSpeed *= SprintMultiplier;
	bSprinting = true;
}

void AFPSCharacter::StopSprint()
{
	//GetCharacterMovement()->MaxWalkSpeed /= SprintMultiplier;
}

void AFPSCharacter::PrimaryFire()
{
	FHitResult outHit;
	FVector Direction = Camera->GetForwardVector();
	FVector Start = Camera->GetComponentLocation();
	FVector End = Start + (Direction * 5000.0f); // TODO promote to variable

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this->GetOwner());
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);

	/*bool isHit = GetWorld()->LineTraceSingleByChannel(outHit, Start, End, ECC_Visibility, CollisionParams);
	if (AFPSCharacter* otherPlayer = Cast<AFPSCharacter>(outHit.GetActor()))
	{
		UE_LOG(LogTemp, Warning, TEXT("You have hit %s"), *outHit.GetActor()->GetName());
		otherPlayer->Death();
	}*/
}

void AFPSCharacter::Death()
{
	DisableInput(Cast<APlayerController>(this));
}

void AFPSCharacter::Respawn()
{
	EnableInput(Cast<APlayerController>(this));
}