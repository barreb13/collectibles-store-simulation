//---------------------------------------------------------------------------------
// CollectibleItem.h
// Author: Brent Barrese
// Class Declarations
//---------------------------------------------------------------------------------
// CollectibleItem Class:	A class that is derived from a Comparable class object.
//							It represents a collectible item that is the parent class
//							of different collectible item types
//   --	derived from Comparable class
//   --	stores a quantity (all collectible items have a quantity)
//   -- allows for getting the current quantity of object
//	 -- allows for increasing the current quantity of object
//	 -- allows for decreasing the current quantity of object
//	 -- allows for creating derived class objects
//	 -- allows for comparing < and > of derived class objects
//	 -- allows for comparing equality of derived class objects
//	 -- allows for displaying the information of a derived class object
//	 -- allows for displaying the transaction information of a derived class object
//
// Assumptions:
//   -- Comparable parent class is included
//   -- Comparable class has pure virtual and virtual methods
//	 -- there are derived class objects of different types of collectible items
//---------------------------------------------------------------------------------

#pragma once
#include "Comparable.h"

#include <string>
using namespace std;

class CollectibleItem :	public Comparable {
public:
	//------------------------------  constructor  -----------------------------------------
	//	Default constructor for the CollectibleItem class
	//	Preconditions:	there is enough space in memory for CollectibleItem to be instantiated
	//	Postconditions:	collectibleItem is created
	CollectibleItem();


	//------------------------------  destructor  ------------------------------------------
	//	Virtual destructor for the CollectibleItem class
	//	Preconditions:	calling CollectibleItem object has previously been instantiated
	//	Postconditions:	CollectibleItem object is destroyed
	virtual ~CollectibleItem();


	//---------------------------------  create  -------------------------------------------
	//	A pure virtual create method for CollectibleItem class that allows derived classes
	//	to create an object
	//	Preconditions:	a hash table of derived class objects has been set up
	//					in a ComparableFactory class and the object has been 
	//					instantiated. There are indexes associated with creating
	//					derived CollectibleItem class objects
	//	Postconditions:	CollectibleItem object is created. a derived CollectibleItem object ptr
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


	//--------------------------------  <  ----------------------------------------------
	//	A pure virtual method that checks for less than between 2 CollectibleItem objects
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	true is returned if this is less than comparable, else false
	//					is returned
	virtual bool operator<(const Comparable& comparable) const = 0;


	//--------------------------------  ==  ----------------------------------------------
	//	A pure virtual method that checks for equality between 2 CollectibleItem objects
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	true is returned if this is equal to comparable, else false
	//					is returned
	virtual bool operator==(const Comparable& comparable) const = 0;


	//--------------------------------  !=  ----------------------------------------------
	//	A pure virtual method that checks for non-equality between 2 CollectibleItem objects
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	true is returned if this is not equal to comparable, else false
	//					is returned
	virtual bool operator!=(const Comparable& comparable) const = 0;


	//--------------------------------  >  ----------------------------------------------
	//	A pure virtual method that checks for greater than between 2 CollectibleItem objects
	//	Preconditions:	this and comparable both point to comparable objects
	//	Postconditions:	true is returned if this is greater than comparable, else false
	//					is returned
	virtual bool operator>(const Comparable& comparable) const = 0;


	//------------------------  displayInformation  ----------------------------------------
	//	A pure virtual function that allows derived objects to display their information
	//	Preconditions:	a derived class object must have an implementation for displayInformation
	//	Postconditions:	the information from the calling object is printed to the screen
	virtual void displayInformation() const = 0;


	//------------------------  displayForTransaction  ----------------------------------------
	//	A pure virtual function that allows derived objects to display information when being
	//	called by a transaction.
	//	Preconditions:	there is a derived comparable object. transaction information has been set
	//					before displayForTransaction is called
	//	Postconditions:	derived object prints its previously set members to the screen
	virtual void displayForTransaction() const = 0;


	//------------------------------  getQuantity  ------------------------------------------
	//	A virtual method that allows for getting the current quantity of a collectible item 
	//	Preconditions:	quantity has been defined and set
	//	Postconditions:	an integer of quantity is returned to the calling object
	virtual int getQuantity();


	//----------------------------  increaseQuantity  ------------------------------------------
	//	A method that increases the integer value of quantity by 1 when it is called
	//	Preconditions:	quantity has been set and is an integer value
	//	Postconditions:	quantity is increased by a value of 1. true is returned if quantity is 
	//					increased
	bool increaseQuantity();


	//---------------------------  decreaseQuantity  -----------------------------------------
	//	A method that decreases the integer value of quantity by 1 when it is called
	//	Preconditions:	quantity has been set and is an integer value. in order to decrease the 
	//					quantity, the value of quantity must be greater than 0
	//	Postconditions:	quantity is decreased by a value of 1. true is returned if quantity is 
	//					decreased, otherwise false is returned.
	bool decreaseQuantity();

private:

protected:
	int quantity;
};

