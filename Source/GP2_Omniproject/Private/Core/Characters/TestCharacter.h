// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;
struct FInputActionValue;
class UInputMappingContext;

UCLASS()
class ATestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PawnClientRestart() override; //This runs when you respawn character

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	UFUNCTION() FVector GetCameraForwardDir() const;
	UFUNCTION() FVector GetCameraRightDir() const;
	UFUNCTION() void MoveCharacter(const FInputActionValue& value);
	UFUNCTION() void Look(const FInputActionValue& value);

	/******************************************/
	/*         INPUT                          */
	/******************************************/
	UPROPERTY(EditAnywhere, Category = "Input") UInputMappingContext* MappingContext;
	UPROPERTY(EditAnywhere, Category = "Input") UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, Category = "Input") UInputAction* LookAction;
	UPROPERTY(EditAnywhere, Category = "Input") UInputAction* JumpAction;

	/******************************************/
	/*        Camera                          */
	/******************************************/
	UPROPERTY(VisibleAnywhere, Category = "Camera") USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, Category = "Camera") UCameraComponent* GameCamera;
	
	UPROPERTY(EditAnywhere, Category = "Player Settings") float SprintMultiplier {2.0f};
};
