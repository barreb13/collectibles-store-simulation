//---------------------------------------------------------------------------------
// CollectibleItem.cpp
// Author: Brent Barrese
// Class Definitions
//---------------------------------------------------------------------------------
// CollectibleItem Class:	A class that is derived from a Comparable class object.
//							It represents a collectible item that is the parent class
//							of different collectible item types
//   --	derived from Comparable class
//   --	stores a quantity (all collectible items have a quantity)
//   -- allows for getting the current quantity of object
//	 -- allows for increasing the current quantity of object
//	 -- allows for decreasing the current quantity of object
//	 -- allows for creating derived class objects
//	 -- allows for comparing < and > of derived class objects
//	 -- allows for comparing equality of derived class objects
//	 -- allows for displaying the information of a derived class object
//	 -- allows for displaying the transaction information of a derived class object
//
// Assumptions:
//   -- Comparable parent class is included
//   -- Comparable class has pure virtual and virtual methods
//	 -- there are derived class objects of different types of collectible items
//---------------------------------------------------------------------------------



#include "CollectibleItem.h"

//------------------------------  constructor  -----------------------------------------
//	Default constructor for the CollectibleItem class
//	Preconditions:	there is enough space in memory for CollectibleItem to be instantiated
//	Postconditions:	collectibleItem is created
CollectibleItem::CollectibleItem() {
}


//------------------------------  destructor  ------------------------------------------
//	Destructor for the CollectibleItem class
//	Preconditions:	calling CollectibleItem object has previously been instantiated
//	Postconditions:	CollectibleItem object is destroyed
CollectibleItem::~CollectibleItem() {
}


//------------------------------  getQuantity  ------------------------------------------
//	A virtual method that allows for getting the current quantity of a collectible item 
//	Preconditions:	quantity has been defined and set
//	Postconditions:	an integer of quantity is returned to the calling object
int CollectibleItem::getQuantity() {
	return quantity;
}


//----------------------------  increaseQuantity  ------------------------------------------
//	A method that increases the integer value of quantity by 1 when it is called
//	Preconditions:	quantity has been set and is an integer value
//	Postconditions:	quantity is increased by a value of 1. true is returned if quantity is 
//					increased
bool CollectibleItem::increaseQuantity() {
	quantity++;
	return true;
}


//---------------------------  decreaseQuantity  -----------------------------------------
//	A method that decreases the integer value of quantity by 1 when it is called
//	Preconditions:	quantity has been set and is an integer value. in order to decrease the 
//					quantity, the value of quantity must be greater than 0
//	Postconditions:	quantity is decreased by a value of 1. true is returned if quantity is 
//					decreased, otherwise false is returned.
bool CollectibleItem::decreaseQuantity() {
	if (quantity > 0) {
		quantity--;
		return true;
	}
	return false;
}
