//---------------------------------------------------------------------------------
// ComparableFactory.h
// Author: Brent Barrese
// Class Declarations
//---------------------------------------------------------------------------------
// ComparableFactory Class:	A factory class that initializes a table of objects to
//							be created. Ushes a hash function to determine which 
//							comparable-->collectibleItem-->derivedObject to create
//   --	allows for using a hash function to hash a char and return an integer value
//   --	allows for creating an object derived from the CollectibleItem class
//   -- uses a table that stores new objects
//
// Assumptions:
//   -- a valid char is passed into the create method
//   -- Comparable class is instantiated
//	 -- CollectibleItem class is instantiated
//	 -- Derived CollectibleItem classes are instantiated
//---------------------------------------------------------------------------------


#pragma once
#include "Comparable.h"
#include "Coin.h"
#include "ComicBook.h"
#include "SportsCard.h"
#include <string>

using namespace std;

#define TABLE_SIZE 26

class ComparableFactory {
public:
	//----------------------------  constructor  -----------------------------------------
	//	Default constructor for the ComparableFactory class object
	//	Preconditions:	there is enough space in memory for the ComparableFactory object
	//					to be instantiated. table index point to new objects of associated
	//					derived classes from CollectibleItem
	//	Postconditions:	comparableTable is instantiated. the chars being hashed are set to 
	//					get a new object of a derived Comparable class object. all other 
	//					table entries are set to nullptr to help in store class when processing
	ComparableFactory();


	//----------------------------  destructor  -----------------------------------------
	//	Destructor for the ComparableFactory class (virtual)
	//	Preconditions:	comparableTable was initialized
	//	Postconditions:	dynamic memory is freed. all indexes of comparableTable are set
	virtual ~ComparableFactory();


	//------------------------------  create  -------------------------------------------
	//	Create method for ComparableFactory class
	//	Preconditions:	a valid char is being passed in to the method. an istream object 
	//					is being passed in as the 1st parameter
	//	Postconditions:	a Comparable* (a derived class object) is returned to calling 
	//					object / method
	Comparable* create(istream& inStream, char key);

	

private:
	//------------------------------  hashChar  -------------------------------------------
	//	Hashes a char and returns an integer
	//	Preconditions:	a char is passed into the method  		
	//	Postconditions:	an integer is returned to the calling object
	int hashChar(char key);

	Comparable* comparableTable[TABLE_SIZE];
};

