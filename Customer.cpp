//---------------------------------------------------------------------------------
// Customer.cpp
// Author: Brent Barrese
// Class Definitions
//---------------------------------------------------------------------------------
// Customer Class:	A class that represents a customer at a store. Stores the 
//					customer's information and all of their transaction history
//   --	stores the customer's name 
//   --	stores the customer's ID number
//   -- stores the customer's transaction history
//	 -- allows for displaying customer's transaction history
//	 -- allows for comparing less than of customers
//
// Assumptions:
//   -- there is enough memory to create
//   -- there will be an istream object sending in text
//	 -- Transaction class is included
//---------------------------------------------------------------------------------


#include "Customer.h"


//----------------------------  constructor  -----------------------------------------
//	Default constructor for the Customer class object
//	Preconditions:	there is enough space in memory for the Customer object to be 
//					instantiated. 
//	Postconditions:	customer is created. idNumber is set to 0 as a holding integer
Customer::Customer() {
	idNumber = 0;
}


//----------------------------  destructor  -----------------------------------------
//	Default virtual destructor for the Customer class object
//	Preconditions:	Customer object is already instantiated
//	Postconditions:	Customer object is destroyed
Customer::~Customer() {
}


//----------------------------  getIdNumber  -----------------------------------------
//	Returns the integer stored in Customer's idNumber variable
//	Preconditions:	customer has been created. there is an integer stored in idNumber
//	Postconditions:	an integer is returned to the calling object / method
int Customer::getIdNumber() const { 
	return idNumber; 
}



//------------------------------  getName  ---------------------------------------------
//	Returns the string stored in Customer's name variable
//	Preconditions:	customer has been created. there is a string stored in name
//	Postconditions:	a string is returned to the calling object / method
string Customer::getName() const{ 
	return name; 
}


//------------------------  displayAllTransactions  -------------------------------------
//	Displays all of the transactions stored in Customer's transactionHistory vector
//	Preconditions:	customer has been created. transactionHistory vector has been created
//	Postconditions:	transactionHistory vector is walked through and each transaction has 
//					its display method called which prints the transaction to the screen
void Customer::displayAllTransactions() {
	for (int i = 0; i < transactionHistory.size(); i++) {
		transactionHistory[i].display();
	}

}


//----------------------------  setCustomerInfo  ------------------------------------------
//	Sets the Customer's private variables, idNumber and name
//	Preconditions:	customer has been created. customer has private variables idNumber and name
//	Postconditions:	idNumber is updated with an integer and name is updated with a string
void Customer::setCustomerInfo(istream& inStream) {
	string stringCount;
	
	getline(inStream, stringCount, ',');
	idNumber = atoi(stringCount.c_str());
	inStream.get();
	getline(inStream, name, '\n');
}


//--------------------------------  setName  ---------------------------------------------
//	A method that sets the private variable, name, in the Customer object
//	Preconditions:	customer has been created. customer has private name variable. the 
//					parameter passed in is a string
//	Postconditions:	name is updated with newName
void Customer::setName(string newName) {
	name = newName;
}


//------------------------------  addTransaction  -----------------------------------------
//	A method that adds a Transaction object to the vector transactionHistory that is stored
//	in Customer object
//	Preconditions:	customer has been created. the parameter being passed in is a Transaction
//					object
//	Postconditions:	a transaction object, transaction, is pushed onto transactionHistory vector
void Customer::addTransaction(Transaction transaction) {
	transactionHistory.push_back(transaction);
}


//------------------------------------  <  ------------------------------------------------
//	Checks for less than between 2 Customer objects based off their name
//	Preconditions:	this and customer both point to Customer objects
//	Postconditions:	true is returned if this.name is less than customer.name, else false
//					is returned
bool Customer::operator<(const Customer& customer) const {
	return name < customer.name;
}
