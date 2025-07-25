// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 *
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInLineNew, DefaultToInstanced)
class INVENTORYSYSTEM_API UItem : public UObject
{
	GENERATED_BODY()

public:
	UItem();

	/* Override the world */
	virtual class UWorld* GetWorld() const { return World; };

	/* World for the items */
	UPROPERTY(Transient)
	class UWorld* World;

	/* Text for using the item (Equip, Eat, etc) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Item)
	FText UseActionText;

	/* Mesh to display for this item to be picked up */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Item)
	class UStaticMesh* PickupMesh;

	/* Thumbnail for the item */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item)
	class UTexture2D* Thumbnail;

	/* Display name for the item in the inventory */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item)
	FText ItemDisplayName;

	/* Optional description for the item */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item, meta = (MultiLine = true))
	FText ItemDescription;

	/* The inventory that owns this item (Reference to inventory comp) */
	UPROPERTY()
	class UInventoryComponent* OwningInventory;

	/* Not to be used on item itself. Use on child of this class */
	virtual void Use(class AInventorySystemCharacter* Character);

	/* Function that can be implemented in blueprints
	   Can also be used to spawn particles */
	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(class AInventorySystemCharacter* Character);
};
