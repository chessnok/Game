// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Character.h"
#include "GCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;

UCLASS()
class MYPROJECT2_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    USpringArmComponent *SpringArmComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent *CameraComp;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
    UStaticMeshComponent *MeshComp;
    virtual void BeginPlay() override;
protected:
	// Called when the game starts or when spawned
    void MoveForward(float value);
    void MoveRight(float value);
    void TurnAtRate(float value);
    void LookAtRate(float value);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
    float BaseTurnRate;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
    float BaseLookUprate;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
    float TreceDistance;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
