//---------------------------------------------------------------------------------
// DisplayInventory.cpp
// Author: Brent Barrese
// Class Definitions
//---------------------------------------------------------------------------------
// DisplayInventory Class:	A class that displays the inventory of a Store object in
//							sorted order. 
//   --	derived from the Transaction class
//   --	displays inventory of collectible item objects in a store object
//   -- allows for creating a DisplayInventory object
//	 -- allows for performing an action
//	 -- allows for displaying the object (not used)
//
// Assumptions:
//   -- a factory class for creating transactions has been previously instantiated
//   -- Transaction class is the parent class
//	 -- Transaction class has virtual methods
//---------------------------------------------------------------------------------


#include "Store.h"
#include "DisplayInventory.h"


//----------------------------  constructor  -----------------------------------------
//	Default constructor for the DisplayInventory class
//	Preconditions:	there is enough space in memory for DisplayInventory object to 
//					be instantiated
//	Postconditions:	transactionType has been set to "DisplayInventory"
DisplayInventory::DisplayInventory() {
	transactionType = "DisplayInventory";
}


//----------------------------  destructor  ------------------------------------------
//	Destructor for the DisplayInventory class
//	Preconditions:	calling DisplayInventory object has previously been instantiated
//	Postconditions:	DisplayInventory object is destroyed
DisplayInventory::~DisplayInventory() {
}


//----------------------------  virtual create  -------------------------------------
//	Virtual create method for DisplayInventory class.
//	Preconditions:	hash table of dummy objects has been set up in TransactionFactory
//					class object. There is an index in the table that instantiates
//					a new History object
//	Postconditions:	DisplayInventory object is created and passed to factory class
Transaction* DisplayInventory::create() {
	return new DisplayInventory;
}



//bool DisplayInventory::perform(Store* store, Comparable* comparable, char type) {
//	store->displayAllInventory();
//	return false;
//}


// NOT USED
//---------------------------  virtual display -------------------------------------
//	A virtual display method that allows the DisplayInventory object to be displayed 
//	within other class methods
//	Preconditions:	transactionType was filled correctly when the object was constructed.
//					the comparableObject points to correct object
//	Postconditions:	the transaction type is printed to the screen. the comparableObject 
//					displayForTransaction method is called for the comparable object
//					which prints the object information to the screen.
void DisplayInventory::display() {
}


//--------------------------  virtual perform  -------------------------------------
//	A virtual perform method that allows the DisplayInventory object to perform its actions
//	Preconditions:	DisplayInventory object has been instantiated. store has already 
//					been instantiated and store points to object. store != nullptr. 
//	Postconditions:	the inventory of all collectible items inside of the store are printed
//					to the screen by group, and in specific order
bool DisplayInventory::perform(Store* store) {
	store->displayAllInventory();
	return true;
}
