// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Item.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	Capacity = 20;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	for (auto& Item : DefaultItems) {
		AddItem(Item);
	}

}

bool UInventoryComponent::AddItem(UItem* Item)
{
	// check inventory capacity before giving player the item
	// or if item in NULL
	if (Items.Num() >= Capacity || !Item) {
		return false;
	}

	// Tell item its world
	Item->OwningInventory = this;
	Item->World = GetWorld();

	Items.Add(Item);

	// Update UI
	OnInventoryUpdated.Broadcast();

	return true;
}

bool UInventoryComponent::RemoveItem(UItem* Item)
{
	if (Item) {
		/* Change owning inventory and world of item to Null
		   and remove from inventory */
		Item->OwningInventory = nullptr;
		Item->World = nullptr;
		Items.RemoveSingle(Item);
		OnInventoryUpdated.Broadcast();
		return true;
	}
	return false;
}