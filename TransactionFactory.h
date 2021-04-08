//---------------------------------------------------------------------------------
// TransactionFactory.h
// Author: Brent Barrese
// Class Declarations
//---------------------------------------------------------------------------------
// TransactionFactory Class:	
//
//   --	
//   --	 
//   -- 
//
// Assumptions:
//   -- 
//   -- 
//	 -- 
//---------------------------------------------------------------------------------

class Store;		//forward declaration
#pragma once
#include "Transaction.h"
//---------------------------------------------------------------------------------
// TransactionFactory.h
// Author: Brent Barrese
// Class Declarations
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


#include "History.h"
#include "Buy.h"
#include "Sell.h"
#include "DisplayInventory.h"
#include "CustomerTransactions.h"

#include <string>

using namespace std;

#define TABLE_SIZE 26

class TransactionFactory {
public:
	//----------------------------  constructor  -----------------------------------------
	//	Default constructor for the TransactionFactory class object
	//	Preconditions:	there is enough space in memory for the TransactionFactory object to 
	//					be instantiated. table indexes point to associated objects of classes
	//					derived from Transaction class
	//	Postconditions:	transactionTable is initialized. the chars being hashed are set to
	//					instantiate a new object of a derived Transaction class
	TransactionFactory();

	
	//----------------------------  destructor  -----------------------------------------
	//	Destructor for the TransactionFactory class (virtual)
	//	Preconditions:	transactionTable was initialized
	//	Postconditions:	dynamic memory is freed. all indexes of transactionTable are set
	//					to nullptr
	virtual ~TransactionFactory();


	//------------------------------  create  -------------------------------------------
	//	Create method for TransactionFactory class
	//	Preconditions:	a valid char is being passed in to the method.  		
	//	Postconditions:	a Transaction* is returned to calling object
	Transaction* create(istream& inStream, char key);
	//pass in char to hash and return a transaction type

private:
	//------------------------------  hashChar  -------------------------------------------
	//	Hashes a char and returns an integer
	//	Preconditions:	a char is passed into the method  		
	//	Postconditions:	an integer is returned to the calling object
	int hashChar(char key);

	//table
	Transaction* transactionTable[TABLE_SIZE];
};

