//---------------------------------------------------------------------------------
// Transaction.cpp
// Author: Brent Barrese
// Class Definitions
//---------------------------------------------------------------------------------
// Transaction Class:	A parent class of Transaction objects. Represents a transaction
//						performed by a store object.
//   --	parent class of different transaction types
//   --	allows for creating objects
//   -- allows for different perform types depending on the transaction type
//	 -- allows for displaying the derived object
//	 -- stores a pointer to a comparable object
//	 -- stores a string that is the derived transaction type
//
// Assumptions:
//   -- a factory class for creating transactions has been previously instantiated
//   -- methods are virtual which will allow for derived classes to use properly
//	 -- Store object has already been instantiated and store* is not nullptr
//---------------------------------------------------------------------------------


#include "Transaction.h"

//----------------------------  constructor  -----------------------------------------
//	Default constructor for the Transaction class object
//	Preconditions:	there is enough space in memory for the Transaction object to be
//					instantiated
//	Postconditions:	a derived transaction type has been created
Transaction::Transaction() {	
}


//----------------------------  destructor  -----------------------------------------
//	Destructor for the Transaction class
//	Preconditions:	calling Transaction object has previously been instantiated		
//	Postconditions:	calling Transaction object is destroyed. Derived class object 
//					is also destroyed.
Transaction::~Transaction() {
}


//------------------------------  create  -------------------------------------------
//	Virtual create method for Transaction class
//	Preconditions:	a hash table of dummy objects derived from the Transaction class has
//					been set up in TransactionFactory class object. There are indexes
//					associated with creating Transaction / derived Transaction objects
//	Postconditions:	Transaction object is created. a derived transaction object is created
Transaction* Transaction::create() {
	return new Transaction;
}


//------------------  perform(Store*, Comparable*, char)  ---------------------------
//	A virtual perform method that allows objects derived from Transaction class to 
//	perform their necessary actions. 
//	Preconditions:	Store object has been created and store points to it. store does 
//					not point to nullptr. Comparable* does not point to nullptr. char
//					is valid transaction type 
//	Postconditions:	the derived Transaction object calls its perform method and 
//					performs its action. store is altered according to transaction		
bool Transaction::perform(Store* store, Comparable* comparable, char type) {
	return true;
}


//--------------------------  perform(Store*, int)  ---------------------------------
//	A virtual perform method that allows objects derived from Transaction class to 
//	perform their necessary actions.
//	Preconditions:	Store object has been created and store does not point to nullptr.
//					customerID is a valid customerID that has a value associated with
//					the array stored in store object. perform() is called with store*
//					and an int as parameters
//	Postconditions:	the derived Transaction object calls its performed method and 
//					performs its action. store is altered according to transaction.
//					customerID may be altered according to transaction
bool Transaction::perform(Store* store, int customerID) {
	return true;
}


//-----------------------------  perform(Store*)  -----------------------------------
//	A virtual perform method that allows objects derived from Transaction class to 
//	perform their necessary actions
//	Preconditions:	Store object has been created and store does not point to nullptr.
//					perform() is called with only a Store* as a parameter
//	Postconditions:	the derived Transaction object calls its performed method and 
//					performs its action. store is altered according to transaction.
bool Transaction::perform(Store* store)
{
	return false;
}


//-----------------------------------  display  -------------------------------------
//	A virtual display method that allows the derived Transaction object to be displayed
//	within other class methods
//	Preconditions:	there is a derived transaction object. transactionType was filled
//					correctly when the object was constructed. the comparableObject
//					points to correct object
//	Postconditions:	the transaction type is printed on the screen. the comparableObject
//					displayForTransaction method that is being called for the comparable
//					object prints the object information to the screen
void Transaction::display() const {
	cout << "\t*Transaction: " << transactionType;
	comparableObject->displayForTransaction();
	cout << endl;
}
