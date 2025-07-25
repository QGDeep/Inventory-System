// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "FoodItem.generated.h"

/**
 *
 */
UCLASS()
class INVENTORYSYSTEM_API UFoodItem : public UItem
{
	GENERATED_BODY()

protected:
	/* What do do with the food item (Functionality) */
	virtual void Use(class AInventorySystemCharacter* Character) override;

public:
	/* Health to heal */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item, meta = (ClampMin = 0.0))
	float HealthtoHeal;
};
