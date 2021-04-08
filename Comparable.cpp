//---------------------------------------------------------------------------
// Comparable.cpp
// Author: Brent Barrese
// Class Definitions
//---------------------------------------------------------------------------
// Comparable class:	Takes in a char from istream and stores in a
//						comparable object	
//   --	allows comparing of binary objects including:
//   --	greater than, less than
//   --	equal to, not equal to
//   --	allows printing of binary object member variable
//   --	allows user input of char into comparable object
//
// Assumptions:
//   --	uses default constructor and destructor provided by compiler	
//   -- user will enter a char when using >>
//----------------------------------------------------------------------------


#include "Comparable.h"


//-----------------------------  constructor=  -----------------------------------------
//	A default constructor for Comparable object
//	Preconditions:	There is enough memory
//	Postconditions:	Comparable is created
Comparable::Comparable() {
}


//-----------------------------  destructor  -----------------------------------------
//	A virtual destructor for Comparable object
//	Preconditions:	Comparable has previously been instantiated
//	Postconditions:	Comparable is destroyed
Comparable::~Comparable() {
}

//--------------------------------  ==  ----------------------------------------------
//	A pure virtual method that checks for equality between 2 Comparable objects
//	Preconditions:	this and comparable both point to comparable objects
//	Postconditions:	true is returned if this is equal to comparable, else false
//					is returned
bool Comparable::operator==(const Comparable& comparable) const {
	return (data == comparable.data);
}

//--------------------------------  !=  ----------------------------------------------
//	A pure virtual method that checks for non-equality between 2 Comparable objects
//	Preconditions:	this and comparable both point to comparable objects
//	Postconditions:	true is returned if this is not equal to comparable, else false
//					is returned
bool Comparable::operator!=(const Comparable& comparable) const {
	return (data != comparable.data);
}


//-----------------------------  <  -----------------------------------------
//	Checks for less than between 2 comparable objects
//	Preconditions:	this and comparable both point to comparable objects
//	Postconditions:	true is returned if the private member "data" of this is
//					less than the private member "data" of comparable, 
//					otherwise false is returned
bool Comparable::operator<(const Comparable& comparable) const {
	return (data < comparable.data);
}


//--------------------------------  >  ----------------------------------------------
//	A pure virtual method that checks for greater than between 2 Comparable objects
//	Preconditions:	this and comparable both point to comparable objects
//	Postconditions:	true is returned if this is greater than comparable, else false
//					is returned
bool Comparable::operator>(const Comparable& comparable) const {
	return (data > comparable.data);
}


//-----------------------------  <<  -----------------------------------------
//	Overloaded output operator for class Comparable
//	Preconditions:	Comparable object has been instantiated.
//	Postconditions:	The comparable's private member "data" is sent to ostream
//
ostream& operator<<(ostream& outStream, const Comparable& comparable) {
	outStream << comparable.data;
	return outStream;
}


//-----------------------------  >>  -----------------------------------------
//	Overloaded input operator for class Comparable
//	Preconditions:	comparable.data is ready for a char
//	Postconditions:	private member variable "data" is populated with the value
//					of the char passed into the istream
istream& operator>>(istream& inStream, Comparable& comparable) {
	inStream >> comparable.data;
	return inStream;
}
