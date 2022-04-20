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
	

	JumpMaxCount = 2;
	respawnTime = 3.0f;
	SprintMultiplier = 1.5f;
	bSprinting = false;
	MovementSpeed = 400;
	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;
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
	if (bSprinting && GetCharacterMovement()->Velocity.IsZero())
	{
		bSprinting = false;
		GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("%hs"), "Stopped Sprinting"));
	}
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
	//PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AFPSCharacter::StopSprint);
	PlayerInputComponent->BindAction("PrimaryFire", IE_Pressed, this, &AFPSCharacter::PrimaryFire);
}

void AFPSCharacter::MoveForwardBackward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AFPSCharacter::MoveRightLeft(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
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
	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed * SprintMultiplier;
	bSprinting = true;
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("%hs"), "Sprinting"));
}

void AFPSCharacter::StopSprint()
{
	//GetCharacterMovement()->MaxWalkSpeed /= SprintMultiplier;
}

void AFPSCharacter::PrimaryFire()
{
	
}

void AFPSCharacter::Death()
{
	DisableInput(Cast<APlayerController>(this));
	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &AFPSCharacter::Respawn, respawnTime, false); // TODO this probably should be not in this class
}

void AFPSCharacter::Respawn()
{
	EnableInput(Cast<APlayerController>(this));
}