// Lostre productions.


#include "AnimInstances/Hero/WarriorHeroAnimInstance.h"
#include "Characters/WarriorHeroCharacter.h"

void UWarriorHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwningCharacter) {
		OwningHeroCharacter = Cast<AWarriorHeroCharacter>(OwningCharacter);
	}
}

void UWarriorHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (bHasAcceleration) {
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxedState = false;
	}
	else {
		IdleElapsedTime += DeltaSeconds;
		bShouldEnterRelaxedState = IdleElapsedTime>=EnterRelaxStateThreshold;
	}
}
