//---------------------------------------------------------------------------------
// Store.cpp
// Author: Brent Barrese
// Class Definitions
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


#include "Store.h"


//------------------------------  constructor  -----------------------------------------
//	Default constructor for Store class
//	Preconditions:	there is enough space in memory for Store object to be instantiated.
//					initializeStore has been defined
//	Postconditions:	all names in customerArray are set to "blank"
Store::Store() {
	initializeStore();
}


//------------------------------  destructor  -----------------------------------------
//	Default destructor for the Store class
//	Preconditions:	calling Store object has previously been instantiated
//	Postconditions:	Store object is destroyed
Store::~Store() {
}


//------------------------------  setCustomers  -----------------------------------------
//	Sets all of the customer objects and stores in the private variable customerArray
//	Preconditions:	inStream is an istream object being passed in as a parameter. Customer
//					objects are able to be instantiated. setCustomerInfo has been defined
//					in the Customer class. customerArray is available
//	Postconditions:	all Customer objects are created from the istream object and objects
//					are added to customerArray. they are stored based on their ID Number
void Store::setCustomers(istream& inStream) {
	//for (;;) {
	while (inStream.peek() != EOF) {
		Customer* customer = new Customer();
		customer->setCustomerInfo(inStream);

		if (inStream.eof()) {
			delete customer;			
			return;
		}

		//Add to array
		customerArray[customer->getIdNumber()] = *customer;
		
		delete customer;	//added 6.3
		customer = nullptr;	//added 6.3
	}
}


//----------------------------  setCollectibleItems  -----------------------------------------
//	Sets all of the CollectibleItem derived class objects in their appropriate Binary Search Tree
//	Preconditions:	inStream is an istream object being passed in as a parameter. CollectibleItem 
//					objects and their derived class objects are able to be instantiated. 
//					ComparableFactory is included and has been defined to create objects that are
//					in inStream.
//	Postconditions:	all CollectibleItem derived class objects (Coin, Sports Card, Comic Book) are
//					created and stored in their associated Binary Search Tree.
void Store::setCollectibleItems(istream& inStream) {
	while (inStream.peek() != EOF) {
		//start at beginning of each line
		char type;
		//int quantity;
		inStream >> type;
		//inStream.ignore();
		//inStream >> quantity;

		//call factory method to create object
		Comparable* comparable = comparableFactoryObj.create(inStream, type);


		//put data into object if valid comparable object
		if (comparable != nullptr) {
			comparable->setInformation(inStream);

			////insert into BSTree
			//if (type == 'M') {
			//	coinTree.insert(comparable);
			//}
			//if (type == 'C') {
			//	comicBookTree.insert(comparable);
			//}
			//if (type == 'S') {
			//	sportsCardTree.insert(comparable);
			//}

			//Putting into array of BSTs
			collectibleItemTreesArray[type - 'A'].insert(comparable);
		}
	}
}


//------------------------------  validCustomer  -------------------------------------------
//	Checks to see if a customer is created based on the given customerID integer
//	Preconditions:	customerID is an integer. customerArray has been instantiated.
//	Postconditions:	true is returned if there is a customer with a name other than "blank" 
//					stored in the index of customerID in the customerArray member
bool Store::validCustomer(int customerID) const {
	if (customerArray[customerID].getName() != "blank") {
		return true;
	}
	else {
		return false;
	}
}


//----------------------------  processTransactions  -----------------------------------------
//	Sets all of the Transaction derived class objects and performs an action if necessary on
//	a given CollectibleItem object
//	Preconditions:	inStream is an istream object being passed in as a parameter. Customer 
//					objects can be created. Transaction objects can be created. insertTransaction
//					has been defined
//	Postconditions:	a transaction object is created and stored if necessary. a transaction is
//					performed. the transaction is stored in the store history as well as the 
//					customer history if a customer performed the transaction
void Store::processTransactions(istream& inStream) {
	Customer* customerPtr = nullptr;
	char transactionChar;

	while (inStream.peek() != EOF) {
		//start at beginning of each line
		inStream >> transactionChar;

		//create transaction object
		Transaction* transactionPtr = transactionFactoryObj.create(inStream, transactionChar);
		

		//handle case where invalid transaction type gets passed in and purge line
		if (transactionPtr == nullptr) {
			string garbage;
			getline(inStream, garbage, '\n');
			cout << "\nInvalid Transaction Requested\n";
		}
		//only proceeds further if valid transaction returned
		else {
			//check to see if file line needs to be parsed further or perform() if not
			if (inStream.peek() != ',') {
				transactionPtr->perform(this);
				delete transactionPtr;
				transactionPtr = nullptr;
			}
			//else there is a customer ID and line needs further parsing
			else {
				int customerID = 0;				
				inStream.ignore();					//ignore the comma
				inStream >> customerID;				//get the integer				
				if (inStream.peek() == ',') {		//there is more to transaction
					inStream.ignore();				//ignore the comma after ID

					//verify customer in database
					if (validCustomer(customerID)) {
						//create pointer to customer
						customerPtr = &customerArray[customerID];

						// customer is valid so can proceed
						char objectType;
						inStream >> objectType;

						//call factory method to create object that is bought or sold
						Comparable* comparablePtr = comparableFactoryObj.create(inStream, objectType);

						//put data into object if valid comparable object
						if (comparablePtr != nullptr) {
							comparablePtr->setTransactionInformation(inStream);

							//if it makes it here it is buy or sell transaction. 
							//search for comparable in collectibleItem BSTs
							Comparable* findComparable = collectibleItemTreesArray[objectType - 'A'].retrieve(*comparablePtr);

							bool successfulPerform;
							successfulPerform = transactionPtr->perform(this, findComparable, objectType);							

							//if successful, add transaction to customer transaction and store transaction histories
							if (successfulPerform) {
								insertTransaction(*transactionPtr, customerID);
								delete transactionPtr;			//added for mem leak
								transactionPtr = nullptr;		//added for mem leak
								delete comparablePtr;			//added for mem leak
								comparablePtr = nullptr;		//added for mem leak
							}
							else {
								cout << "Could not perform transaction\n";
								delete transactionPtr;			//added for mem leak
								transactionPtr = nullptr;		//added for mem leak
								delete comparablePtr;			//added for mem leak
								comparablePtr = nullptr;		//added for mem leak
							}
						}
					}
					else {
						cout << "Customer ID Not Found";
					}
				}
				else {
					// it is a customer history command. call history command
					transactionPtr->perform(this, customerID);
					//free memory
					delete transactionPtr;			//added for mem leak
					transactionPtr = nullptr;		//added for mem leak
				}
			}
		}
	}
}



//----------------------------  displayAllHistory  -----------------------------------------
//	Displays all of the history that has taken place inside of the Store object
//	Preconditions:	the vector sortedCustomerList is able to be filled with Customer objects.
//					customerArray has been filled with Customer objects. Customer class has
//					defined displayAllTransactions
//	Postconditions:	sortedCustomerList is filled with Customer objects from customerArray and
//					sorted by name. each Customer then prints all of their history to the screen
//history of customers sorted alphabetically
void Store::displayAllHistory() {
	cout << "\nAll History: " << endl;
	//Customer* customerPtr = nullptr;
	//clear vector in case called multiple times
	sortedCustomerList.clear();

	//add customers to vector
	for (int i = 0; i < MAX_CUSTOMERS; i++) {
		if (customerArray[i].getName() != "blank") {
			//customerPtr = &customerArray[i];
			sortedCustomerList.push_back(customerArray[i]);
		}
	}

	//sortedCustomerList has all customers in it. Sort by name
	sort(sortedCustomerList.begin(), sortedCustomerList.end(), [](const Customer& lhs, const Customer& rhs)->bool {
		return lhs.getName() < rhs.getName();
	});

	//vector is sorted - now print
	for (auto i : sortedCustomerList) {		
		string name = i.getName();
		cout << "Transaction History For " << name << ": " << endl;
		i.displayAllTransactions();
	}
}


//----------------------------  displayAllInventory  -----------------------------------------
//	Displays all of the inventory that is currently stored in the Store object
//	Preconditions:	setCollectibleItems has already ran and set and stored objects in their
//					Binary Search Trees. << is overloaded to cout a Binary Search Tree
//	Postconditions:	Binary Search Trees that are populated are printed to the screen with all
//					objects that are in them and what the current quantity is
void Store::displayAllInventory() const {
	cout << "\nAll Inventory:" << endl;
	//cout << coinTree;
	//cout << comicBookTree;
	//cout << sportsCardTree;
	for (int i = 0; i < MAX_TREES; i++)	{
		if (!(collectibleItemTreesArray[i].isRootNull())) {
			cout << collectibleItemTreesArray[i];
		}
	}
}


//void Store::buy(Comparable& comparable) { }


//void Store::sell(Comparable& comparable) { }


//----------------------------  customerHistory  -----------------------------------------
//	Displays the history of Transaction objects stored in a Customer object
//	Preconditions:	customerID is an integer. there is a Customer object stored at the index
//					customerID in customerArray
//	Postconditions:	displayAllTransactions is called for the found Customer object which 
//					displays all Transaction objects
void Store::customerHistory(int customerID) {
	Customer* customerPtr = &customerArray[customerID];
	customerPtr->displayAllTransactions();
}


//----------------------------  initializeStore  -----------------------------------------
//	Initializes the customerArray inside of Store object to help other functions work properly
//	Preconditions:	customerArray must be a Store variable. Customer objects must have setName
//					defined
//	Postconditions:	all Customer objects in customerArray have their name set to "blank"
void Store::initializeStore() {
	//initialize customer array
	for (int i = 0; i < MAX_CUSTOMERS; i++) {
		customerArray[i].setName("blank");
	}
}


//----------------------------  insertTransaction  -----------------------------------------
//	Helper method to insert a Transaction object into transactionsVector and also insert
//	into the Transaction vector stored in each Customer object
//	Preconditions:	transactionsVector has been declared. addTransaction has been declared
//					in the Customer class. transaction is a Transaction object and customerID
//					is an integer
//	Postconditions:	transactionsVector and the found Customer object's transactionHistory 
//					have a new Transaction object added
//add to customer object and store history
void Store::insertTransaction(Transaction transaction, int customerID) {
	//add to store history of transactions
	transactionsVector.push_back(transaction);

	//add to customer history of transactions
	customerArray[customerID].addTransaction(transaction);
}


//----------------------------  insertComparableToBST  -----------------------------------------
//	Inserts a Comparable object into a BST
//	Preconditions:	comparable is a Comparable* and  type is a char. Binary Search Trees have
//					been defined and the insert method has been defined
//	Postconditions:	a CollectibleItem Binary Search Tree has a Comparable * inserted
bool Store::insertComparableToBST(Comparable* comparable, char type) {
	return (collectibleItemTreesArray[type - 'A'].insert(comparable));
}

