//---------------------------------------------------------------------------------
// SportsCard.cpp
// Author: Brent Barrese
// Class Definitions
//---------------------------------------------------------------------------------
// SportsCard Class:	A class that is derived from CollectibleItem class. It represents
//						a Sports Card which is a collectible item
//   --	derived from CollectibleItem class
//   --	stores a string player, string manufacturer, string grade, and integer year
//   -- allows for creating the object
//	 -- allows for setting the information in the object from an istream object
//	 -- allows for comparing < and > of SportsCard objects
//	 -- allows for comparing equality and non equality of SportsCard objects
//	 -- allows for displaying the information stored in the object
//	 -- allows for displaying the information of object for a transaction (no quantity)
//
// Assumptions:
//   -- CollectibleItem parent class is included
//   -- parent classes have virtual or pure virtual methods
//---------------------------------------------------------------------------------


#include "SportsCard.h"
//------------------------------  constructor  -----------------------------------------
//	Default constructor for the SportsCard class
//	Preconditions:	there is enough space in memory for SportsCard to be instantiated
//	Postconditions:	SportsCard is created
SportsCard::SportsCard() {

}


//------------------------------  destructor  ------------------------------------------
//	Virtual destructor for the SportsCard class
//	Preconditions:	calling SportsCard object has previously been instantiated
//	Postconditions:	SportsCard object is destroyed
SportsCard::~SportsCard() {

}


//---------------------------------  create  -------------------------------------------
//	A virtual create method for SportsCard class that allows creating an object
//	Preconditions:	a hash table of derived class objects has been set up
//					in a ComparableFactory class and the object has been 
//					instantiated. There are indexes associated with creating
//					SportsCard class objects
//	Postconditions:	SportsCard object is created. a derived CollectibleItem object pointer
//					is created and returned
Comparable* SportsCard::create() {
	return new SportsCard;
}


//---------------------------  setInformation  -------------------------------------
//	A virtual function that allows SportsCard objects to set their information.
//	Preconditions:	an istream is being passed in as a parameter
//	Postconditions:	members in the SportsCard object are changed and their information
//					is set
void SportsCard::setInformation(istream& inStream) {
	
	inStream.ignore();						//ignore the comma
	inStream >> quantity;					//get quantity
	inStream.ignore();						//ignore the comma
	inStream >> year;						//get year
	inStream.ignore();						//ignore the comma
	getline(inStream, grade, ',');			//get grade
	inStream.ignore();						//ignore the comma
	getline(inStream, player, ',');			//get player
	inStream.ignore();						//ignore the comma
	getline(inStream, manufacturer, '\n');	//get manufacturer
}


//-----------------------  setTransactionInformation  -------------------------------
//	A virtual function that allows SportsCard objects to set their information for
//	a transaction method
//	Preconditions:	an istream is being passed in as a parameter.
//	Postconditions:	members in the SportsCard object are changed and their information
//					is set for a transaction
void SportsCard::setTransactionInformation(istream& inStream) {
	inStream.ignore();						//ignore the comma
	inStream >> year;						//get year
	inStream.ignore();						//ignore the comma
	getline(inStream, grade, ',');			//get grade
	inStream.ignore();						//ignore the comma
	getline(inStream, player, ',');			//get player
	inStream.ignore();						//ignore the comma
	getline(inStream, manufacturer, '\n');	//get manufacturer
}


//--------------------------------  <  ----------------------------------------------
//	A virtual method that checks for less than between 2 SportsCard objects
//	Preconditions:	this and comparable both point to SportsCard objects
//	Postconditions:	true is returned if this is less than comparable, else false
//					is returnedv
//Sort by player, year, manufacturer, grade
bool SportsCard::operator<(const Comparable& comparable) const {
	//cast to SportsCard
	const SportsCard& comparableSportsCard = static_cast<const SportsCard&>(comparable);

	if (player < comparableSportsCard.player) {
		return true;
	}
	else if (player == comparableSportsCard.player) {
		if (year < comparableSportsCard.year) {
			return true;
		}
		else if (year == comparableSportsCard.year) {
			if (manufacturer < comparableSportsCard.manufacturer) {
				return true;
			}
			else if (manufacturer == comparableSportsCard.manufacturer) {
				if (grade < comparableSportsCard.grade) {
					return true;
				}
			}
		}
	}
	return false;
}


//--------------------------------  ==  ----------------------------------------------
//	A virtual method that checks for equality between 2 SportsCard objects
//	Preconditions:	this and comparable both point to SportsCard objects
//	Postconditions:	true is returned if this is equal to comparable, else false
//					is returned
bool SportsCard::operator==(const Comparable& comparable) const {
	//cast to SportsCard
	const SportsCard& comparableSportsCard = static_cast<const SportsCard&>(comparable);

	return (player == comparableSportsCard.player && year == comparableSportsCard.year
		&& manufacturer == comparableSportsCard.manufacturer && grade == comparableSportsCard.grade);
}


//--------------------------------  !=  ----------------------------------------------
//	A virtual method that checks for non-equality between 2 SportsCard objects
//	Preconditions:	this and comparable both point to SportsCard objects
//	Postconditions:	true is returned if this is not equal to comparable, else false
//					is returned
bool SportsCard::operator!=(const Comparable& comparable) const {
	//cast to SportsCard
	const SportsCard& comparableSportsCard = static_cast<const SportsCard&>(comparable);

	return !(*this == comparableSportsCard);
}


//--------------------------------  >  ----------------------------------------------
//	A virtual method that checks for greater than between 2 SportsCard objects
//	Preconditions:	this and comparable both point to SportsCard objects
//	Postconditions:	true is returned if this is greater than comparable, else false
//					is returned
bool SportsCard::operator>(const Comparable& comparable) const {
	//cast to SportsCard
	const SportsCard& comparableSportsCard = static_cast<const SportsCard&>(comparable);

	if (player > comparableSportsCard.player) {
		return true;
	}
	else if (player == comparableSportsCard.player) {
		if (year > comparableSportsCard.year) {
			return true;
		}
		else if (year == comparableSportsCard.year) {
			if (manufacturer > comparableSportsCard.manufacturer) {
				return true;
			}
			else if (manufacturer == comparableSportsCard.manufacturer) {
				if (grade > comparableSportsCard.grade) {
					return true;
				}
			}
		}
	}
	return false;
}


//------------------------  displayInformation  ----------------------------------------
//	A virtual method that allows SportsCard objects to display their stored information
//	Preconditions:	a parent class object must have a pure virtual or virtual method
//	Postconditions:	the information from the calling object is printed to the screen 
//					in specified order
void SportsCard::displayInformation() const {
	cout << player << " " << manufacturer << " " << year << " " << grade << " QUANTITY: " << quantity;
}


//------------------------  displayForTransaction  ----------------------------------------
//	A virtual method that allows SportsCard objects to display information when being
//	called by a transaction.
//	Preconditions:	the parent class object must have a pure virtual or virtual method. 
//					transaction information has been set before displayForTransaction is called
//	Postconditions:	the information from the calling object is printed to the screen in
//					the specified order
void SportsCard::displayForTransaction() const {
	cout << " " << player << " " << manufacturer << " " << year << " " << grade;
}


//--------------------------  getPlayer  ----------------------------------------
//	A method that returns a string that is stored in variable player
//	Preconditions:	SportsCard has been created. a string is stored in player
//	Postconditions:	a string is returned to calling object
string SportsCard::getPlayer() {
	return player;
}


//------------------------  getManufacturer  ------------------------------------
//	A method that returns a string that is stored in variable manufacturer
//	Preconditions:	SportsCard has been created. a string is stored in manufacturer
//	Postconditions:	a string is returned to calling object
string SportsCard::getManufacturer() {
	return manufacturer;
}


//------------------------  getYear  ----------------------------------------
//	A method that returns an integer that is stored in variable year
//	Preconditions:	SportsCard has been created. an int is stored in year
//	Postconditions:	an int is returned to calling object
int SportsCard::getYear() {
	return year;
}


//------------------------  getGrade  ----------------------------------------
//	A method that returns a string that is stored in variable grade
//	Preconditions:	SportsCard has been created. a string is stored in grade
//	Postconditions:	a string is returned to calling object
string SportsCard::getGrade() {
	return grade;
}
