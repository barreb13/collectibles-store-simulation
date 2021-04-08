//---------------------------------------------------------------------------------
// CustomerTransactions.cpp
// Author: Brent Barrese
// Class Definitions
//---------------------------------------------------------------------------------
// CustomerTransactions Class:	A class that displays customer transactions. It is 
//								derived from the Transaction class. It is represented
//								by a 'C' in a command file.
//   --	derived from the Transaction class
//   --	displays a customer's transaction history
//   -- allows for creating a CustomerTransaction object
//	 -- allows for performing an action
//	 -- allows for displaying the object (not used)
//
// Assumptions:
//   -- a factory class for creating transactions has been previously instantiated
//   -- Transaction class is the parent class
//	 -- Transaction class has virtual methods
//---------------------------------------------------------------------------------


#include "Store.h"
#include "CustomerTransactions.h"


//----------------------------  constructor  -----------------------------------------
//	Default constructor for the CustomerTransactions class
//	Preconditions:	there is enough space in memory for CustomerTransaction object to 
//					be instantiated
//	Postconditions:	transactionType has been set to "CustomerTransaction"
CustomerTransactions::CustomerTransactions() {
	transactionType = "CustomerTransaction";
}


//----------------------------  destructor  ------------------------------------------
//	Destructor for the CustomerTransaction class
//	Preconditions:	calling CustomerTransaction object has previously been instantiated
//	Postconditions:	CustomerTransaction object is destroyed
CustomerTransactions::~CustomerTransactions(){
}


//----------------------------  virtual create  -------------------------------------
//	Virtual create method for CustomerTransaction class.
//	Preconditions:	hash table of dummy objects has been set up in TransactionFactory
//					class object. There is an index in the table that instantiates
//					a new CustomerTransaction object
//	Postconditions:	CustomerTransactions object is created and passed to factory class
Transaction* CustomerTransactions::create() {
	return new CustomerTransactions;
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
//bool CustomerTransactions::perform(Store* store, Comparable* comparable, char type)
//{
//	return false;
//}


//--------------------------  virtual perform  -------------------------------------
//	A virtual perform method that allows the CustomerTransactions object to perform 
//	its actions
//	Preconditions:	CustomerTransactions object has been instantiated. store has already 
//					been instantiated and store points to object. store != nullptr. 
//					customerID is a valid customerID in the store customer array
//	Postconditions:	the history of transactions for the given customerID is accessed 
//					and printed to the screen
bool CustomerTransactions::perform(Store* store, int customerID) {
	cout << "\nCustomer History for customerID: " << customerID << endl;
	store->customerHistory(customerID);	
	return true;
}


// NOT USED
//---------------------------  virtual display -------------------------------------
//	A virtual display method that allows the CustomerTransactions object to be displayed 
//	within other class methods
//	Preconditions:	transactionType was filled correctly when the object was constructed.
//					the comparableObject points to correct object
//	Postconditions:	the transaction type is printed to the screen. the comparableObject 
//					displayForTransaction method is called for the comparable object
//					which prints the object information to the screen.
void CustomerTransactions::display() {
}
