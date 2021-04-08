//---------------------------------------------------------------------------------
// Store.h
// Author: Brent Barrese
// Class Declarations
//---------------------------------------------------------------------------------
//	Store Class:	A class that acts a manager class for this program. The store object
//					takes in different istreams and parses the lines to set necessary
//					information. It then processes all information utilizing the 
//					different classes included in it
//   --	stores an array of Binary Search Trees
//   --	stores an array of Customer objects
//   -- stores a vector of Transaction objects
//	 -- stores a vector of Customer objects that is used to sort by name
//	 -- stores 2 factory objects - comparableFactory and transactionFactory
//	 -- allows for setting all customers from an istream
//	 -- allows for setting collectible items from an istream
//	 -- allows for validating customers based on a given idNumber
//	 -- allows for processing transactions from an istream
//	 -- allows for storing and displaying all Transaction history
//	 -- allows for displaying (printing) all inventory in sorted order
//
// Assumptions:
//   -- SearchTree class is included
//   -- Customer class is included
//	 -- Transaction class is included
//	 -- Comparable class is included
//	 -- ComparableFactory class is included
//	 -- TransactionFactory class is included
//	 
//---------------------------------------------------------------------------------

#pragma once

#include "SearchTree.h"
#include "Customer.h"
#include "Transaction.h"
#include "Comparable.h"
#include "ComparableFactory.h"
#include "TransactionFactory.h"
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_CUSTOMERS 1000
#define MAX_TREES 26		//# alphabetical possibilities

using namespace std;

class Store {
private:
	//SearchTree coinTree;
	//SearchTree comicBookTree;
	//SearchTree sportsCardTree;
	
	SearchTree collectibleItemTreesArray[MAX_TREES];
	Customer customerArray[MAX_CUSTOMERS];	
	vector <Transaction> transactionsVector;
	//vector for sorted customers
	vector <Customer> sortedCustomerList;	
	ComparableFactory comparableFactoryObj;
	TransactionFactory transactionFactoryObj;

public:
	//------------------------------  constructor  -----------------------------------------
	//	Default constructor for Store class
	//	Preconditions:	there is enough space in memory for Store object to be instantiated.
	//					initializeStore has been defined
	//	Postconditions:	all names in customerArray are set to "blank"
	Store();


	//------------------------------  destructor  -----------------------------------------
	//	Default destructor for the Store class
	//	Preconditions:	calling Store object has previously been instantiated
	//	Postconditions:	Store object is destroyed
	virtual ~Store();


	//------------------------------  setCustomers  -----------------------------------------
	//	Sets all of the customer objects and stores in the private variable customerArray
	//	Preconditions:	inStream is an istream object being passed in as a parameter. Customer
	//					objects are able to be instantiated. setCustomerInfo has been defined
	//					in the Customer class. customerArray is available
	//	Postconditions:	all Customer objects are created from the istream object and objects
	//					are added to customerArray. they are stored based on their ID Number
	void setCustomers(istream& inStream);


	//----------------------------  setCollectibleItems  -----------------------------------------
	//	Sets all of the CollectibleItem derived class objects in their appropriate Binary Search Tree
	//	Preconditions:	inStream is an istream object being passed in as a parameter. CollectibleItem 
	//					objects and their derived class objects are able to be instantiated. 
	//					ComparableFactory is included and has been defined to create objects that are
	//					in inStream.
	//	Postconditions:	all CollectibleItem derived class objects (Coin, Sports Card, Comic Book) are
	//					created and stored in their associated Binary Search Tree.
	void setCollectibleItems(istream& inStream);
	
	
	//------------------------------  validCustomer  -------------------------------------------
	//	Checks to see if a customer is created based on the given customerID integer
	//	Preconditions:	customerID is an integer. customerArray has been instantiated.
	//	Postconditions:	true is returned if there is a customer with a name other than "blank" 
	//					stored in the index of customerID in the customerArray member
	bool validCustomer(int customerID) const;
	
	//comparable --> collectibleItem --> coin/sportsCard/comicBook
	//insert comparable into its collectibleItem tree


	//----------------------------  processTransactions  -----------------------------------------
	//	Sets all of the Transaction derived class objects and performs an action if necessary on
	//	a given CollectibleItem object
	//	Preconditions:	inStream is an istream object being passed in as a parameter. Customer 
	//					objects can be created. Transaction objects can be created. insertTransaction
	//					has been defined
	//	Postconditions:	a transaction object is created and stored if necessary. a transaction is
	//					performed. the transaction is stored in the store history as well as the 
	//					customer history if a customer performed the transaction
	void processTransactions(istream& inStream);


	//----------------------------  displayAllHistory  -----------------------------------------
	//	Displays all of the history that has taken place inside of the Store object
	//	Preconditions:	the vector sortedCustomerList is able to be filled with Customer objects.
	//					customerArray has been filled with Customer objects. Customer class has
	//					defined displayAllTransactions
	//	Postconditions:	sortedCustomerList is filled with Customer objects from customerArray and
	//					sorted by name. each Customer then prints all of their history to the screen
	//history of customers sorted alphabetically
	void displayAllHistory();


	//----------------------------  displayAllInventory  -----------------------------------------
//	Displays all of the inventory that is currently stored in the Store object
//	Preconditions:	setCollectibleItems has already ran and set and stored objects in their
//					Binary Search Trees. << is overloaded to cout a Binary Search Tree
//	Postconditions:	Binary Search Trees that are populated are printed to the screen with all
//					objects that are in them and what the current quantity is
	void displayAllInventory() const;


	//void buy(Comparable& comparable);


	//void sell(Comparable& comparable);


	//----------------------------  customerHistory  -----------------------------------------
	//	Displays the history of Transaction objects stored in a Customer object
	//	Preconditions:	customerID is an integer. there is a Customer object stored at the index
	//					customerID in customerArray
	//	Postconditions:	displayAllTransactions is called for the found Customer object which 
	//					displays all Transaction objects
	void customerHistory(int customerID);


	//----------------------------  initializeStore  -----------------------------------------
	//	Initializes the customerArray inside of Store object to help other functions work properly
	//	Preconditions:	customerArray must be a Store variable. Customer objects must have setName
	//					defined
	//	Postconditions:	all Customer objects in customerArray have their name set to "blank"
	void initializeStore();
	//initializes variables to 0 or nullptr


	//----------------------------  insertTransaction  -----------------------------------------
	//	Helper method to insert a Transaction object into transactionsVector and also insert
	//	into the Transaction vector stored in each Customer object
	//	Preconditions:	transactionsVector has been declared. addTransaction has been declared
	//					in the Customer class. transaction is a Transaction object and customerID
	//					is an integer
	//	Postconditions:	transactionsVector and the found Customer object's transactionHistory 
	//					have a new Transaction object added
	//add to customer object and store history
	void insertTransaction(Transaction transaction, int customerID);
	//push transaction* into transactionsVector


	//----------------------------  insertComparableToBST  -----------------------------------------
	//	Inserts a Comparable object into a BST
	//	Preconditions:	comparable is a Comparable* and  type is a char. Binary Search Trees have
	//					been defined and the insert method has been defined
	//	Postconditions:	a CollectibleItem Binary Search Tree has a Comparable * inserted
	bool insertComparableToBST(Comparable* comparable, char type);

};

