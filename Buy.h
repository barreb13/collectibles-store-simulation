//---------------------------------------------------------------------------------
// Buy.h
// Author: Brent Barrese
// Class Declarations
//---------------------------------------------------------------------------------
// Buy Class:	A class that "buys" a collectible item object. It is derived from the
//				Transaction class. It is represented by a 'B' in a command file.
//   --	derived from the transaction class
//   --	increases the quantity of an object
//   -- allows for creating a Buy object
//	 -- allows for performing an action
//	 -- allows for displaying the object
//
// Assumptions:
//   -- a factory class for creating transactions has been previously instantiated
//   -- Transaction class is the parent class
//	 -- Transaction class has virtual methods
//---------------------------------------------------------------------------------

#pragma once
#include "Transaction.h"


class Buy :	public Transaction {
public:
	//----------------------------  constructor  -----------------------------------------
	//	Default constructor for the Buy class
	//	Preconditions:	there is enough space in memory for Buy object to be instantiated
	//	Postconditions:	transactionType has been set to "Buy"
	Buy();


	//----------------------------  destructor  ------------------------------------------
	//	Destructor for the Buy class
	//	Preconditions:	calling Buy object has previously been instantiated
	//	Postconditions:	Buy object is destructed
	virtual ~Buy();


	//----------------------------  virtual create  -------------------------------------
	//	Virtual create method for Buy class.
	//	Preconditions:	hash table of dummy objects has been set up in TransactionFactory
	//					class object. There is an index in the table that instantiates
	//					a new Buy object
	//	Postconditions:	Buy object is created and passed to factory class
	virtual Transaction* create();
	

	//--------------------------  virtual perform  -------------------------------------
	//	A virtual perform method that allows the Buy object to perform it's actions
	//	Preconditions:	Buy object has been instantiated. store has already been instantiated
	//					and store points to object. store != nullptr. char type matches a 
	//					valid collectibleItem type.
	//	Postconditions:	the comparable object has its quantity increased if it is already
	//					in the BSTree of collectibleItems. Else, it is added to the correct
	//					BST in the store object. char type is not changed.
	//buy adds an item to the store inventory
	virtual bool perform(Store* store, Comparable* comparable, char type);	//added


	//---------------------------  virtual display -------------------------------------
	//	A virtual display method that allows the Buy object to be displayed within other
	//	class methods
	//	Preconditions:	transactionType was filled correctly when the object was constructed.
	//					the comparable points to correct object
	//	Postconditions:	the transaction type is printed to the screen. the comparableObject 
	//					displayForTransaction method is called for the comparable object
	//					which prints the object information to the screen.
	virtual void display();

private:

};

