//---------------------------------------------------------------------------------
// TransactionFactory.cpp
// Author: Brent Barrese
// Class Definitions
//---------------------------------------------------------------------------------
// TransactionFactory Class:	A factory class that initializes a table of objects
//								to be created. Uses a hash function to determine which
//								transaction object to create. It uses a create method
//								that gets passed in an istream and a char as a key
//   --	allows for using a hash function to hash a char and return an integer value
//   --	allows for creating an object derived from the Transaction class
//   -- uses a table that stores new objects
//
// Assumptions:
//   -- a valid char is passed into the create method
//   -- Transaction class is included
//	 -- derived classes from Transaction are included
//---------------------------------------------------------------------------------


#include "TransactionFactory.h"
#include "Store.h"


//----------------------------  constructor  -----------------------------------------
//	Default constructor for the TransactionFactory class object
//	Preconditions:	there is enough space in memory for the TransactionFactory object to 
//					be instantiated. table indexes point to associated objects of classes
//					derived from Transaction class
//	Postconditions:	transactionTable is initialized. the chars being hashed are set to
//					instantiate a new object of a derived Transaction class
TransactionFactory::TransactionFactory() {
	//Initialize table
	for (int i = 0; i < TABLE_SIZE; i++) {
		transactionTable[i] = nullptr;
	}

	//set object values of transaction items
	transactionTable[hashChar('S')] = new Sell;
	transactionTable[hashChar('B')] = new Buy;
	transactionTable[hashChar('C')] = new CustomerTransactions;
	transactionTable[hashChar('D')] = new DisplayInventory;
	transactionTable[hashChar('H')] = new History;
}


//----------------------------  destructor  -----------------------------------------
//	Destructor for the TransactionFactory class (virtual)
//	Preconditions:	transactionTable was initialized
//	Postconditions:	dynamic memory is freed. all indexes of transactionTable are set
//					to nullptr
TransactionFactory::~TransactionFactory() {
	//delete any dynamic memory
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (transactionTable[i] != nullptr) {
			delete transactionTable[i];
			transactionTable[i] = nullptr;
		}
	}
}


//------------------------------  create  -------------------------------------------
//	Create method for TransactionFactory class
//	Preconditions:	a valid char is being passed in to the method.  		
//	Postconditions:	a Transaction* is returned to calling object
Transaction* TransactionFactory::create(istream& inStream, char key) {
	//hash char
	int index = hashChar(key);

	//handle case where invalid transaction type gets passed in
	if (transactionTable[index] == nullptr) {
		//if index was nullptr == no valid transaction type
		string garbage;
		getline(inStream, garbage, '\n');
		return nullptr;
	}
	return transactionTable[index]->create();
}



//------------------------------  hashChar  -------------------------------------------
//	Hashes a char and returns an integer
//	Preconditions:	a char is passed into the method  		
//	Postconditions:	an integer is returned to the calling object
int TransactionFactory::hashChar(char key) {
	return (key - 'A') % TABLE_SIZE;
}

