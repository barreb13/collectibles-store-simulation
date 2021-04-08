//---------------------------------------------------------------------------------
// ComicBook.cpp
// Author: Brent Barrese
// Class Definitions
//---------------------------------------------------------------------------------
// ComicBook Class:	A class that is derived from CollectibleItem class. It represents
//					a comic book which is a collectible item.
//   --	derived from CollectibleItem class
//   --	stores a string title, string publisher, string grade, and integer year
//   -- allows for creating the object
//	 -- allows for setting the information in the object from an istream object
//	 -- allows for comparing < and > of ComicBook objects
//	 -- allows for comparing equality and non equality of ComicBook objects
//	 -- allows for displaying the information stored in the object
//	 -- allows for displaying the information of object for a transaction (no quantity)
//
// Assumptions:
//   -- CollectibleItem parent class is included
//   -- parent classes have virtual or pure virtual methods
//---------------------------------------------------------------------------------


#include "ComicBook.h"

//------------------------------  constructor  -----------------------------------------
//	Default constructor for the ComicBook class
//	Preconditions:	there is enough space in memory for ComicBook to be instantiated
//	Postconditions:	ComicBook is created
ComicBook::ComicBook() {

}


//------------------------------  destructor  ------------------------------------------
//	Virtual destructor for the ComicBook class
//	Preconditions:	calling ComicBook object has previously been instantiated
//	Postconditions:	ComicBook object is destroyed
ComicBook::~ComicBook() {

}


//---------------------------------  create  -------------------------------------------
//	A virtual create method for ComicBook class that allows creating an object
//	Preconditions:	a hash table of derived class objects has been set up
//					in a ComparableFactory class and the object has been 
//					instantiated. There are indexes associated with creating
//					ComicBook class objects
//	Postconditions:	ComicBook object is created. a derived CollectibleItem object pointer
//					is created and returned
Comparable* ComicBook::create() {
	return new ComicBook;
}


//---------------------------  setInformation  -------------------------------------
//	A virtual function that allows ComicBook objects to set their information.
//	Preconditions:	an istream is being passed in as a parameter
//	Postconditions:	members in the ComicBook object are changed and their information
//					is set
void ComicBook::setInformation(istream& inStream) {
	inStream.ignore();					//ignore the comma
	inStream >> quantity;				//get quantity
	inStream.ignore();					//ignore the comma
	inStream >> year;					//get year
	inStream.ignore();					//ignore the comma
	getline(inStream, grade, ',');		//get grade
	inStream.ignore();					//ignore the comma
	getline(inStream, title, ',');		//get title
	inStream.ignore();					//ignore the comma
	getline(inStream, publisher, '\n');	//get publisher
}


//-----------------------  setTransactionInformation  -------------------------------
//	A virtual function that allows ComicBook objects to set their information for
//	a transaction method
//	Preconditions:	an istream is being passed in as a parameter.
//	Postconditions:	members in the ComicBook object are changed and their information
//					is set for a transaction
void ComicBook::setTransactionInformation(istream& inStream) {
	inStream.ignore();					//ignore the comma
	inStream >> year;					//get year
	inStream.ignore();					//ignore the comma
	getline(inStream, grade, ',');		//get grade
	inStream.ignore();					//ignore the comma
	getline(inStream, title, ',');		//get title
	inStream.ignore();					//ignore the comma
	getline(inStream, publisher, '\n');	//get publisher
}


//--------------------------------  <  ----------------------------------------------
//	A virtual method that checks for less than between 2 ComicBook objects
//	Preconditions:	this and comparable both point to ComicBook objects
//	Postconditions:	true is returned if this is less than comparable, else false
//					is returned
//Sort by Publisher, Title, Year, Grade
bool ComicBook::operator<(const Comparable& comparable) const {
	//cast to ComicBook
	const ComicBook& comparableComicBook = static_cast<const ComicBook&>(comparable);

	if (publisher < comparableComicBook.publisher) {
		return true;
	}
	else if (publisher == comparableComicBook.publisher) {
		if (title < comparableComicBook.title) {
			return true;
		}
		else if (title == comparableComicBook.title) {
			if (year < comparableComicBook.year) {
				return true;
			}
			else if (year == comparableComicBook.year) {
				if (grade < comparableComicBook.grade) {
					return true;
				}
			}
		}
	}
	return false;
}


//--------------------------------  ==  ----------------------------------------------
//	A virtual method that checks for equality between 2 ComicBook objects
//	Preconditions:	this and comparable both point to ComicBook objects
//	Postconditions:	true is returned if this is equal to comparable, else false
//					is returned
bool ComicBook::operator==(const Comparable& comparable) const {
	//cast to ComicBook
	const ComicBook& comparableComicBook = static_cast<const ComicBook&>(comparable);

	return (publisher == comparableComicBook.publisher && title == comparableComicBook.title 
		&& year == comparableComicBook.year && grade == comparableComicBook.grade);
}


//--------------------------------  !=  ----------------------------------------------
//	A virtual method that checks for non-equality between 2 ComicBook objects
//	Preconditions:	this and comparable both point to ComicBook objects
//	Postconditions:	true is returned if this is not equal to comparable, else false
//					is returned
bool ComicBook::operator!=(const Comparable& comparable) const {
	//cast to ComicBook
	const ComicBook& comparableComicBook = static_cast<const ComicBook&>(comparable);

	return !(*this == comparableComicBook);
}


//--------------------------------  >  ----------------------------------------------
//	A virtual method that checks for greater than between 2 ComicBook objects
//	Preconditions:	this and comparable both point to ComicBook objects
//	Postconditions:	true is returned if this is greater than comparable, else false
//					is returned
bool ComicBook::operator>(const Comparable& comparable) const {
	//cast to ComicBook
	const ComicBook& comparableComicBook = static_cast<const ComicBook&>(comparable);

	if (publisher > comparableComicBook.publisher) {
		return true;
	}
	else if (publisher == comparableComicBook.publisher) {
		if (title > comparableComicBook.title) {
			return true;
		}
		else if (title == comparableComicBook.title) {
			if (year > comparableComicBook.year) {
				return true;
			}
			else if (year == comparableComicBook.year) {
				if (grade > comparableComicBook.grade) {
					return true;
				}
			}
		}
	}
	return false;
}


//------------------------  displayInformation  ----------------------------------------
//	A virtual method that allows ComicBook objects to display their stored information
//	Preconditions:	a parent class object must have a pure virtual or virtual method
//	Postconditions:	the information from the calling object is printed to the screen 
//					in specified order
void ComicBook::displayInformation() const {
	cout << title << " " << publisher << " " << year << " " << grade << " QUANTITY: " << quantity;
}


//------------------------  displayForTransaction  ----------------------------------------
//	A virtual method that allows ComicBook objects to display information when being
//	called by a transaction.
//	Preconditions:	the parent class object must have a pure virtual or virtual method. 
//					transaction information has been set before displayForTransaction is called
//	Postconditions:	the information from the calling object is printed to the screen in
//					the specified order
void ComicBook::displayForTransaction() const {
	cout << " " << title << " " << publisher << " " << year << " " << grade;
}


//------------------------  getTitle  ----------------------------------------
//	A method that returns a string that is stored in variable title
//	Preconditions:	ComicBook has been created. a string is stored in title
//	Postconditions:	a string is returned to calling object
std::string ComicBook::getTitle() {
	return title;
}


//------------------------  getPublisher  ----------------------------------------
//	A method that returns a string that is stored in variable publisher
//	Preconditions:	ComicBook has been created. a string is stored in publisher
//	Postconditions:	a string is returned to calling object
string ComicBook::getPublisher() {
	return publisher;
}


//------------------------  getYear  ----------------------------------------
//	A method that returns an integer that is stored in variable year
//	Preconditions:	ComicBook has been created. an int is stored in year
//	Postconditions:	an int is returned to calling object
int ComicBook::getYear() {
	return year;
}


//------------------------  getGrade  ----------------------------------------
//	A method that returns a string that is stored in variable grade
//	Preconditions:	ComicBook has been created. a string is stored in grade
//	Postconditions:	a string is returned to calling object
string ComicBook::getGrade() {
	return grade;
}
