//---------------------------------------------------------------------------
// Comparable.h
// Author: Brent Barrese
// Class declarations
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

#pragma once
#include <iostream>

using namespace std;

class Comparable {
	//-----------------------------  <<  -----------------------------------------
	//	Overloaded output operator for class Comparable
	//	Preconditions:	Comparable object has been instantiated.
	//	Postconditions:	The comparable's private member "data" is sent to ostream
	//
	friend ostream& operator <<(ostream& outStream, const Comparable& comparable);


	//-----------------------------  >>  -----------------------------------------
	//	Overloaded input operator for class Comparable
	//	Preconditions:	comparable.data is ready for a char
	//	Postconditions:	private member variable "data" is populated with the value
	//					of the char passed into the istream
	friend istream& operator >>(istream& inStream, Comparable& comparable);

public:
	//-----------------------------  constructor=  -----------------------------------------
	//	A default constructor for Comparable object
	//	Preconditions:	There is enough memory
	//	Postconditions:	Comparable is created
	Comparable();


	//-----------------------------  destructor  -----------------------------------------
	//	A virtual destructor for Comparable object
	//	Preconditions:	Comparable has previously been instantiated
	//	Postconditions:	Comparable is destroyed
	virtual ~Comparable();

	//-----------------------------  ==  -----------------------------------------
	//	Checks for equality between 2 comparable objects
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	true is returned if the private member "data" is the same
	//					value for both comparable objects, otherwise false is 
	//					returned
	virtual bool operator==(const Comparable& comparable) const = 0;


	//-----------------------------  !=  -----------------------------------------
	//	Checks for NOT equality between 2 comparable objects
	//	Preconditions: this and comparable both point to comparable objects
	//	Postconditions: false is returned if the private member "data" is the same
	//					value for both comparable objects, otherwise false is 
	//					returned
	virtual bool operator!=(const Comparable& comparable) const = 0;

	//--------------------------------  <  ----------------------------------------------
	//	A pure virtual method that checks for less than between 2 Comparable objects
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	true is returned if this is less than comparable, else false
	//					is returned
	virtual bool operator<(const Comparable& comparable) const = 0;


	//-----------------------------  >  -----------------------------------------
	//	Checks for greater than between 2 comparable objects
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	true is returned if the private member "data" of this is
	//					is greater than the private member "data" of comparable, 
	//					otherwise false is returned
	virtual bool operator>(const Comparable& comparable) const = 0;

	//----------------------------  create  --------------------------------------
	//	A pure virtual create method for Comparable class that allows derived classes
	//	to create an object
	//	Preconditions:	a hash table of derived class objects has been set up
	//					in a ComparableFactory class and the object has been 
	//					instantiated. There are indexes associated with creating
	//					derived Comparable class objects
	//	Postconditions:	Comparable object is created. a derived comparable object
	//					is created and returned
	virtual Comparable* create() = 0;


	//-------------------------  setInformation  -------------------------------------
	//	A pure virtual function that allows derived objects to set their information.
	//	Preconditions:	an istream is being passed in as a parameter
	//	Postconditions:	members in a derived class object are changed and their information
	//					is set
	virtual void setInformation(istream& inStream) = 0;


	//-----------------------  setTransactionInformation  -------------------------------
	//	A pure virtual function that allows derived objects to set their information for
	//	a transaction method
	//	Preconditions:	an istream is being passed in as a parameter. pure virtual
	//	Postconditions:	members in a derived class object are changed and their information
	//					is set for a transaction
	virtual void setTransactionInformation(istream& inStream) = 0;


	//------------------------  displayInformation  ----------------------------------------
	//	A pure virtual function that allows derived objects to display their information
	//	Preconditions:	a derived class object must have an implementation for displayInformation
	//	Postconditions:	the information from the calling object is printed to the screen
	virtual void displayInformation() const = 0;


	//---------------------------  getQuantity  -------------------------------------------
	//	A pure virtual function that returns the integer value of quantity in a derived class
	//	Preconditions:	Quantity has been defined
	//	Postconditions:	Quantity is returned to the calling object
	virtual int getQuantity() = 0;


	//--------------------------  increaseQuantity  -----------------------------------------
	//	A pure virtual function that increases the integer value of Quantity when called
	//	Preconditions:	Quantity has been set to an integer value
	//	Postconditions:	Quantity is increased by a value of 1. true is returned if quantity
	//					is increased
	virtual bool increaseQuantity() = 0;


	//--------------------------  decreaseQuantity  ------------------------------------------
	//	A pure virtual function that decreases the integer value of Quantity, if Quantity is 
	//	greater than 0, otherwise quantity is not decreased
	//	Preconditions:	Quantity has been set to an integer value. 
	//	Postconditions:	Quantity is decreased by a value of 1. true is returned if quantity is
	//					decreased, otherwise false is returned
	virtual bool decreaseQuantity() = 0;


	//------------------------  displayForTransaction  ----------------------------------------
	//	A pure virtual function that allows derived objects to display information when being
	//	called by a transaction.
	//	Preconditions:	there is a derived comparable object. transaction information has been set
	//					before displayForTransaction is called
	//	Postconditions:	derived object prints its previously set members to the screen
	virtual void displayForTransaction() const = 0;

private:
	char data;
	//int stock;
};

