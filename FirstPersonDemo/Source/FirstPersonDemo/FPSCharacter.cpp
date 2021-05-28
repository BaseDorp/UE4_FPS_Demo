// Fill out your copyright notice in the Description page of Project Settings.
/* 
	Accelerate code derived from http://adrianb.io/2015/02/14/bunnyhop.html
*/

#include "DrawDebugHelpers.h"
#include "Misc/App.h"
#include "FPSCharacter.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	check(Camera != nullptr);

	// Setup Camera
	Camera->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	// Set default camera height (this is slightly above eye height)
	Camera->SetRelativeLocation(FVector(0, 0, 50 + BaseEyeHeight));

	Camera->bUsePawnControlRotation = true; // Allows the camera rotation control
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
	PlayerInputComponent->BindAction("PrimaryFire", IE_Pressed, this, &AFPSCharacter::PrimaryFire);
}

void AFPSCharacter::MoveForwardBackward(float Value)
{
	// Find the forward vector
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	
	// Move the player along that vector
	AddMovementInput(Direction, Value);
}

void AFPSCharacter::MoveRightLeft(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);

	AddMovementInput(Direction, Value);
}

FVector AFPSCharacter::Accelerate(FVector AccelDir, FVector prevVelocity, float accelerate, float maxVelocity)
{
	// Vector projection from Current Velocity to Acceleration Direction
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
	bPressedJump = true;
}

void AFPSCharacter::EndJump()
{
	bPressedJump = false;
}

void AFPSCharacter::StartCrouch()
{
	bIsCrouched = true;
	Crouch();
}

void AFPSCharacter::EndCrouch()
{
	bIsCrouched = false;
}

void AFPSCharacter::PrimaryFire()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello"));

	FHitResult outHit;
	FVector Direction = Camera->GetForwardVector();
	FVector Start = Camera->GetComponentLocation();
	FVector End = Start + (Direction * 5000.0f); // TODO promote to variable

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this->GetOwner());
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);

	/* Dont think i need. Doesnt work anyways*/
	//if (ProjectileClass) // Fire a projectile if possible
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Hello"));
	//	// Camera Properties
	//	FVector CameraLocation;
	//	FRotator CameraRotation;
	//	GetActorEyesViewPoint(CameraLocation, CameraRotation);

	//	MuzzleOffset.Set(100.0f, 0.0f, 0.0f); // Spawn projectile slightly infront of the camera

	//	FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset); // MuzzleOffset from local space to world space

	//	// Makes the aim slightly upwards
	//	FRotator MuzzleRotation = CameraRotation;
	//	MuzzleRotation.Pitch += 10.0f;

	//	UWorld* World = GetWorld();
	//	if (World)
	//	{
	//		FActorSpawnParameters SpawnParams;
	//		SpawnParams.Owner = this;
	//		SpawnParams.Instigator = GetInstigator();

	//		// Spawns the actor
	//		AProjectile* Projectile = World->SpawnActor<AProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
	//		if (Projectile)
	//		{
	//			// Sets trajectory
	//			FVector LaunchDirection = MuzzleRotation.Vector();
	//			Projectile->FireInDirection(LaunchDirection);
	//		}
	//	}
	//}
}