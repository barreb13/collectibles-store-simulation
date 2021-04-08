//---------------------------------------------------------------------------------
// Sell.cpp
// Author: Brent Barrese
// Class Definitions
//---------------------------------------------------------------------------------
// Sell Class:	A class that that "sells" a collectible item object. It is derived
//				from the Transaction class. It is represented by a 'S' in a command file
//   --	derived from the Transaction class
//   --	decreases the quantity of an object
//   -- allows for creating a Sell object
//	 -- allows for performing an action
//	 -- allows for displaying the object
//
// Assumptions:
//   -- a factory class for creating transactions has been previously instantiated
//   -- Transaction class is the parent class
//	 -- Transaction class has virtual methods
//---------------------------------------------------------------------------------


#include "Store.h"
#include "Sell.h"


//----------------------------  constructor  -----------------------------------------
//	Default constructor for the Sell class
//	Preconditions:	there is enough space in memory for Sell object to be instantiated
//	Postconditions:	transactionType has been set to "Sell"
Sell::Sell() {
	transactionType = "Sell";
}


//----------------------------  destructor  ------------------------------------------
//	Destructor for the Sell class
//	Preconditions:	calling Sell object has previously been instantiated
//	Postconditions:	Sell object is destroyed
Sell::~Sell() {
}


//----------------------------  virtual create  -------------------------------------
//	Virtual create method for Sell class.
//	Preconditions:	hash table of dummy objects has been set up in TransactionFactory
//					class object. There is an index in the table that instantiates
//					a new Sell object
//	Postconditions:	Sell object is created and passed to factory class
Transaction* Sell::create() {
	return new Sell;
}


//--------------------------  virtual perform  -------------------------------------
//	A virtual perform method that allows the Sell object to perform its actions
//	Preconditions:	Sell object has been instantiated. store has already been instantiated
//					and store points to object. store != nullptr. char type matches a 
//					valid collectibleItem type.
//	Postconditions:	the comparable object has its quantity decreased if the current 
//					quantity is greater than 0. Otherwise, an error message is displayed
//					and false is returned
//sell decreases stock quantity
bool Sell::perform(Store* store, Comparable* comparable, char type) {
	if (comparable->getQuantity() > 0) {
		comparable->decreaseQuantity();
		comparableObject = comparable;
		return true;
	}
	cout << "Not Enough Stock - No Transaction";
	return false;
}


//---------------------------  virtual display -------------------------------------
//	A virtual display method that allows the Sell object to be displayed within other
//	class methods
//	Preconditions:	transactionType was filled correctly when the object was constructed.
//					the comparableObject points to correct object
//	Postconditions:	the transaction type is printed to the screen. the comparableObject 
//					displayForTransaction method is called for the comparable object
//					which prints the object information to the screen.
void Sell::display() const {
	cout << "Transaction: " << transactionType;
	comparableObject->displayForTransaction();
	cout << endl;
}
