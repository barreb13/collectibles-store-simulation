//---------------------------------------------------------------------------------
// Customer.h
// Author: Brent Barrese
// Class Declarations
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

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;

class Customer {
public:
	//----------------------------  constructor  -----------------------------------------
	//	Default constructor for the Customer class object
	//	Preconditions:	there is enough space in memory for the Customer object to be 
	//					instantiated. 
	//	Postconditions:	customer is created. idNumber is set to 0 as a holding integer
	Customer();


	//----------------------------  destructor  -----------------------------------------
	//	Default virtual destructor for the Customer class object
	//	Preconditions:	Customer object is already instantiated
	//	Postconditions:	Customer object is destroyed
	virtual ~Customer();


	//----------------------------  getIdNumber  -----------------------------------------
	//	Returns the integer stored in Customer's idNumber variable
	//	Preconditions:	customer has been created. there is an integer stored in idNumber
	//	Postconditions:	an integer is returned to the calling object / method
	int getIdNumber() const;


	//------------------------------  getName  ---------------------------------------------
	//	Returns the string stored in Customer's name variable
	//	Preconditions:	customer has been created. there is a string stored in name
	//	Postconditions:	a string is returned to the calling object / method
	string getName() const;


	//------------------------  displayAllTransactions  -------------------------------------
	//	Displays all of the transactions stored in Customer's transactionHistory vector
	//	Preconditions:	customer has been created. transactionHistory vector has been created
	//	Postconditions:	transactionHistory vector is walked through and each transaction has 
	//					its display method called which prints the transaction to the screen
	void displayAllTransactions();


	//----------------------------  setCustomerInfo  ------------------------------------------
	//	Sets the Customer's private variables, idNumber and name
	//	Preconditions:	customer has been created. customer has private variables idNumber and name
	//	Postconditions:	idNumber is updated with an integer and name is updated with a string
	void setCustomerInfo(istream& inStream);


	//--------------------------------  setName  ---------------------------------------------
	//	A method that sets the private variable, name, in the Customer object
	//	Preconditions:	customer has been created. customer has private name variable. the 
	//					parameter passed in is a string
	//	Postconditions:	name is updated with newName
	void setName(string newName);


	//------------------------------  addTransaction  -----------------------------------------
	//	A method that adds a Transaction object to the vector transactionHistory that is stored
	//	in Customer object
	//	Preconditions:	customer has been created. the parameter being passed in is a Transaction
	//					object
	//	Postconditions:	a transaction object, transaction, is pushed onto transactionHistory vector
	void addTransaction(Transaction transaction);


	//------------------------------------  <  ------------------------------------------------
	//	Checks for less than between 2 Customer objects based off their name
	//	Preconditions:	this and customer both point to Customer objects
	//	Postconditions:	true is returned if this.name is less than customer.name, else false
	//					is returned
	bool operator<(const Customer& customer)const;

private:
	int idNumber;
	string name;
	// vector of strings or Transaction* ???
	//vector <string> transactionHistory;
	vector <Transaction> transactionHistory;
};

