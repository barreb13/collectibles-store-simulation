//---------------------------------------------------------------------------------
// Coin.cpp
// Author: Brent Barrese
// Class Definitions
//---------------------------------------------------------------------------------
// Coin Class:	A class that is derived from CollectibleItem class. It represents
//				a coin which is a collectible item.
//   --	derived from CollectibleItem class
//   --	stores a string type, integer year, and integer grade
//   -- allows for creating the object
//	 -- allows for setting the information in the object from an istream object
//	 -- allows for comparing < and > of coin objects
//	 -- allows for comparing equality and non equality of coin objects
//	 -- allows for displaying the information stored in the object
//	 -- allows for displaying the information of object for a transaction (no quantity)
//
// Assumptions:
//   -- CollectibleItem parent class is included
//   -- parent classes have virtual or pure virtual methods
//---------------------------------------------------------------------------------

#include "Coin.h"


//------------------------------  constructor  -----------------------------------------
//	Default constructor for the Coin class
//	Preconditions:	there is enough space in memory for Coin to be instantiated
//	Postconditions:	Coin is created
Coin::Coin() {
}


//------------------------------  destructor  ------------------------------------------
//	Virtual destructor for the Coin class
//	Preconditions:	calling Coin object has previously been instantiated
//	Postconditions:	Coin object is destroyed
Coin::~Coin() {
}


//---------------------------------  create  -------------------------------------------
//	A virtual create method for Coin class that allows creating an object
//	Preconditions:	a hash table of derived class objects has been set up
//					in a ComparableFactory class and the object has been 
//					instantiated. There are indexes associated with creating
//					Coin class objects
//	Postconditions:	Coin object is created. a derived CollectibleItem object pointer
//					is created and returned
Comparable* Coin::create() {
	return new Coin;
}


//---------------------------  setInformation  -------------------------------------
//	A virtual function that allows Coin objects to set their information.
//	Preconditions:	an istream is being passed in as a parameter
//	Postconditions:	members in the coin object are changed and their information
//					is set
void Coin::setInformation(istream& inStream) {
	inStream.ignore();				//ignore the comma
	inStream >> quantity;			//get quantity
	inStream.ignore();				//ignore the comma
	inStream >> year;				//get year
	inStream.ignore();				//ignore the comma
	inStream >> grade;				//get grade
	inStream.ignore();				//ignore the comma
	//inStream.ignore();			//????
	getline(inStream, type, '\n');	//get type
}


//-----------------------  setTransactionInformation  -------------------------------
//	A virtual function that allows Coin objects to set their information for
//	a transaction method
//	Preconditions:	an istream is being passed in as a parameter.
//	Postconditions:	members in the Coin object are changed and their information
//					is set for a transaction
void Coin::setTransactionInformation(istream& inStream) {
	inStream.ignore();				//ignore the comma
	inStream >> year;				//get year
	inStream.ignore();				//ignore the comma
	inStream >> grade;				//get grade
	inStream.ignore();				//ignore the comma
	getline(inStream, type, '\n');	//get type
}


//--------------------------------  <  ----------------------------------------------
//	A virtual method that checks for less than between 2 Coin objects
//	Preconditions:	this and comparable both point to Coin objects
//	Postconditions:	true is returned if this is less than comparable, else false
//					is returned
// Sort by type, year, grade
bool Coin::operator<(const Comparable& comparable) const {
	//cast to Coin
	const Coin& comparableCoin = static_cast<const Coin&>(comparable);

	if (type < comparableCoin.type) {
		return true;
	}
	else if (type == comparableCoin.type) {
		if (year < comparableCoin.year) {
			return true;
		}
		else if (year == comparableCoin.year) {
			if (grade < comparableCoin.grade) {
				return true;
			}
		}
	}
	return false;
}


//--------------------------------  ==  ----------------------------------------------
//	A virtual method that checks for equality between 2 Coin objects
//	Preconditions:	this and comparable both point to Coin objects
//	Postconditions:	true is returned if this is equal to comparable, else false
//					is returned
bool Coin::operator==(const Comparable& comparable) const {
	//cast to Coin
	const Coin& comparableCoin = static_cast<const Coin&>(comparable);
	
	return (type == comparableCoin.type && year == comparableCoin.year 
		&& grade == comparableCoin.grade);
}


//--------------------------------  !=  ----------------------------------------------
//	A virtual method that checks for non-equality between 2 Coin objects
//	Preconditions:	this and comparable both point to Coin objects
//	Postconditions:	true is returned if this is not equal to comparable, else false
//					is returned
bool Coin::operator!=(const Comparable& comparable) const {
	//cast to Coin
	const Coin& comparableCoin = static_cast<const Coin&>(comparable);

	return !(*this == comparableCoin);
}


//--------------------------------  >  ----------------------------------------------
//	A virtual method that checks for greater than between 2 Coin objects
//	Preconditions:	this and comparable both point to Coin objects
//	Postconditions:	true is returned if this is greater than comparable, else false
//					is returned
bool Coin::operator>(const Comparable& comparable) const {
	//cast to Coin
	const Coin& comparableCoin = static_cast<const Coin&>(comparable);

	if (type > comparableCoin.type) {
		return true;
	}
	else if (type == comparableCoin.type) {
		if (year > comparableCoin.year) {
			return true;
		}
		else if (year == comparableCoin.year) {
			if (grade > comparableCoin.grade) {
				return true;
			}
		}
	}
	return false;
}


//------------------------  displayInformation  ----------------------------------------
//	A virtual method that allows Coin objects to display their stored information
//	Preconditions:	a parent class object must have a pure virtual or virtual method
//	Postconditions:	the information from the calling object is printed to the screen 
//					in specified order
void Coin::displayInformation() const {
	cout << type << " " << year << " " << grade << " QUANTITY: " << quantity;
}


//------------------------  displayForTransaction  ----------------------------------------
//	A virtual method that allows Coin objects to display information when being
//	called by a transaction.
//	Preconditions:	the parent class object must have a pure virtual or virtual method. 
//					transaction information has been set before displayForTransaction is called
//	Postconditions:	the information from the calling object is printed to the screen in
//					the specified order
void Coin::displayForTransaction() const {
	cout << " " << type << " " << year << " " << grade;
}

//void Coin::setType()
//{
//}
//
//void Coin::setYear()
//{
//}
//
//void Coin::setGrade()
//{
//}


//------------------------  getType  ----------------------------------------
//	A method that returns a string that is stored in variable type
//	Preconditions:	Coin has been created. a string is stored in type
//	Postconditions:	a string is returned to calling object
string Coin::getType() {
	return type;
}


//------------------------  getYear  ----------------------------------------
//	A method that returns an integer that is stored in variable year
//	Preconditions:	Coin has been created. an int is stored in year
//	Postconditions:	an int is returned to the calling object
int Coin::getYear() {
	return year;
}


//------------------------  getGrade  ----------------------------------------
//	A method that returns an integer that is stored in variable grade
//	Preconditions:	Coin has been created. an int is stored in grade
//	Postconditions:	an int is returned to the calling object
int Coin::getGrade() {
	return grade;
}
