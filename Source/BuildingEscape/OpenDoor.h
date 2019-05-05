// Copyright Kids Hide Away 2019

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h" 
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();	
	void OpenDoor();
	void CloseDoor();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
 
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// Macros!
	UPROPERTY(VisibleAnywhere)
	float OpenAngle = -90.0f; // Note to self, have to restart unrealEditor to see these changes.

	UPROPERTY(VisibleAnywhere)
	float CloseAngle = 0.0f; // Note to self, have to restart unrealEditor to see these changes.

	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 1.0f;

	// Not macros, and not editible in the EU4Editor
	float LastDoorOpenTime = 0.0f;
	AActor* ActorThatOpensTheDoor; // remember pawn inherits from actor
	AActor* Owner;
};
