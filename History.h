//---------------------------------------------------------------------------------
// History.h
// Author: Brent Barrese
// Class Declarations
//---------------------------------------------------------------------------------
// History Class:	A class that displays the transaction history for every customer
//					with the customers being in alphabetical order
//   --	derived from the Transaction class
//   --	displays all transaction history in the store, sorted by customer's name
//   -- allows for creating a History object
//	 -- allows for performing an action
//	 -- allows for displaying the object (not used)
//
// Assumptions:
//   -- a factory class for creating transactions has been previously instantiated
//   -- Transaction class is the parent class
//	 -- Transaction class has virtual methods
//---------------------------------------------------------------------------------


#pragma once
#include "Transaction.h"


class History :	public Transaction {
public:
	//----------------------------  constructor  -----------------------------------------
	//	Default constructor for the History class
	//	Preconditions:	there is enough space in memory for History object to 
	//					be instantiated
	//	Postconditions:	transactionType has been set to "History"
	History();


	//----------------------------  destructor  ------------------------------------------
	//	Destructor for the History class
	//	Preconditions:	calling History object has previously been instantiated
	//	Postconditions:History object is destroyed
	virtual ~History();


	//----------------------------  virtual create  -------------------------------------
	//	Virtual create method for History class.
	//	Preconditions:	hash table of dummy objects has been set up in TransactionFactory
	//					class object. There is an index in the table that instantiates
	//					a new History object
	//	Postconditions:	History object is created and passed to factory class
	virtual Transaction* create();


	//virtual bool perform(Store* store, Comparable* comparable, char type);	//added

	//--------------------------  virtual perform  -------------------------------------
	//	A virtual perform method that allows the History object to perform its actions
	//	Preconditions:	History object has been instantiated. store has already 
	//					been instantiated and store points to object. store != nullptr. 
	//	Postconditions:	the history of transactions for  all customers that have made 
	//					a transaction inside store are printed to the screen in alphabetical
	//					order of the customer's names.
	virtual bool perform(Store* store);


	// NOT USED
	//---------------------------  virtual display -------------------------------------
	//	A virtual display method that allows the History object to be displayed 
	//	within other class methods
	//	Preconditions:	transactionType was filled correctly when the object was constructed.
	//					the comparableObject points to correct object
	//	Postconditions:	the transaction type is printed to the screen. the comparableObject 
	//					displayForTransaction method is called for the comparable object
	//					which prints the object information to the screen.
	virtual void display();
	
private:

};

