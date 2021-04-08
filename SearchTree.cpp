//----------------------------------------------------------------------------------
// SearchTree.cpp
// Author: Brent Barrese
// Class Definitions
//----------------------------------------------------------------------------------
// SearchTree class:	A binary search tree class that stores nodes consisting of 
//						comparable objects in BST fashion. The class allows for 
//						multiple methods:
//   --	allows insert of a comparable object
//   --	allows copying of one tree into another tree
//   -- allows clearing an entire tree and deleting all dynamically allocated memory
//   -- allows comparison of 2 trees that checks for comparable objects and also 
//		checks the occurrences of each comparable object if found more than once
//		in the tree
//   -- allows in order printing of the binary search tree into a table that shows
//		occurrences of comparable objects
//   -- allows removing of comparable objects that deletes the node if the comparable 
//		object only has one occurrence, otherwise the occurrence count is decremented
//		to reflect the count decrease
//   -- allows for finding the height of a given comparable object in respect to 
//		its descendants
//   --	allows for retrieving a comparable object if it is found in the search tree
//   --	allows for creating a new search tree with a parameter of an already existing
//		search tree
//
// Assumptions:
//   -- default constructor creates a search tree object and sets the root to nullptr
//   -- the comparable objects being stored in the search tree have a way of being
//		compared to another comparable object
//   -- in <<, the search tree will print nodes in an in order fashion
//   -- all pointers are initialized to nullptr unless instructed otherwise
//----------------------------------------------------------------------------------

#include "SearchTree.h"


//-----------------------------  Default Constructor  -----------------------------
//	Default constructor for SearchTree class
//	Preconditions:	Enough memory for object to be created
//	Postconditions:	SearchTree object exists. Root pointer is nullptr.
SearchTree::SearchTree() {
	root = nullptr;
}


//-------------------------------  Copy Constructor  -------------------------------
//	Copy constructor for SearchTree class that takes in a parameter of another
//	SearchTree
//	Preconditions:	Enough memory for new SearchTree object to be created. searchTree
//					being passed in is a SearchTree object that has previously been
//					isntantiated. = operator has been built and functions properly.
//	Postconditions:	searchTree is copied into *this. 
SearchTree::SearchTree(const SearchTree& searchTree) {
	root = nullptr;
	*this = searchTree;
}


//----------------------------------  Destructor  ----------------------------------
//	Destructor for SearchTree class. 
//	Preconditions:	root points to memory that was dynamically allocated
//	Postconditions:	root and all of the following dynamically allocated nodes are 
//					deleted. All mememory is freed.
SearchTree::~SearchTree() {
	// deallocate all memory
	makeEmpty();
}


//---------------------------------------  =  ---------------------------------------
//	Overloaded assignment operator that assigns a SearchTree object to a pre-existing
//	SearchTree object
//	Preconditions:	sufficient space for *this. fromSearchTree.root points to a node 
//					in the SearchTree object or nullptr
//	Postconditions:	a new SearchTree object is created that matches fromSearchTree
//					and *this is assigned to it. fromSearchTree is not changed.
SearchTree& SearchTree::operator=(const SearchTree& fromSearchTree) {
	if (this != &fromSearchTree) {
		makeEmpty();
		// Call copyTree method and pass in the root of both trees
		copyTree(root, fromSearchTree.root);
	}
	return *this;
}


//-----------------------------------  copyTree  -----------------------------------
//	A helper function to copy a SearchTree object into another SearchTree object.
//	Preconditions:	current and fromSearchTreeNode point to Node objects, or nullptr,
//					in SearchTree objects. There is enough space for *this to be built
//	Postconditions:	fromSearchTreeNode and its details are copied into a dynamically 
//					allocated node that current is assigned to. This is done recursively
//					for all nodes linked to fromSearchTreeNode, which results in a 
//					complete and deep copy of the SearchTree object.
void SearchTree::copyTree(Node*& current, const Node* fromSearchTreeNode) {
	//// Handle case where Tree being copied is empty
	//if (fromSearchTreeNode == nullptr) {
	//	current = nullptr;
	//}
	//// Tree not empty
	//else {
	//	current = new Node;
	//	current->item = new Comparable(*fromSearchTreeNode->item);
	//	current->count = fromSearchTreeNode->count;

	//	// Recursion
	//	copyTree(current->left, fromSearchTreeNode->left);
	//	copyTree(current->right, fromSearchTreeNode->right);
	//}
}


//---------------------------------------  ==  ---------------------------------------
//	Checks for equality between 2 searchTree objects.
//	Preconditions:	*this and searchTree.root point to node objects or nullptr
//	Postconditions:	bool value is returned. True is returned if *this matches searchTree
//					for every node and all details in the node match (occurrences match 
//					for both *this node and searchTree node. Otherwise, false is returned.
bool SearchTree::operator==(const SearchTree& searchTree) const {
	// Handle 2 empty trees
	if (this->root == nullptr && searchTree.root) {
		return true;
	}
	else {
		return compareTree(root, searchTree.root);
	}
}


//-----------------------------------  compareTree  -----------------------------------
//	Helper function to compare 2 SearchTree objects. Nodes are passed in and compared 
//	recursively.
//	Preconditions:	current and fromSearchTreeNode point to Node objects, or nullptr,
//					in SearchTree objects. Comparable objects have a way of being compared
//	Postconditions:	true is returned if all nodes match including number occurrences,  
//					otherwise false is returned.
bool SearchTree::compareTree(Node* current, Node* fromSearchTreeNode) const {
	// Both nodes nullptr
	if (current == nullptr && fromSearchTreeNode == nullptr) {
		return true;
	}
	// Handle case when 1 node == null and 1 node != null
	else if (current != nullptr && fromSearchTreeNode == nullptr) {
		return false;
	}
	else if (current == nullptr && fromSearchTreeNode != nullptr) {
		return false;
	}
	else {
		if (*current->item == *fromSearchTreeNode->item) {
			if (current->count == fromSearchTreeNode->count && compareTree(current->left, fromSearchTreeNode->left)
				&& compareTree(current->right, fromSearchTreeNode->right)) {
				return true;
			}
			return false;			//Added 4/19/20 to fix bug
		}
		else {
			return false;
		}
	}
}


//---------------------------------------  !=  ---------------------------------------
//	Checks for not equality between 2 SearchTree objects.
//	Preconditions:	*this and searchTree.root point to node objects or nullptr
//	Postconditions:	bool value is returned. True is returned if *this does not match
//					searchTree for any node, starting from the root of both objects.
//					Otherwise, false is returned.
bool SearchTree::operator!=(const SearchTree& searchTree) const {
	return !(*this == searchTree);
}


//--------------------------------------  insert  --------------------------------------
//	Inserts a comparable object into a SearchTree object
//	Preconditions:	There is enough memory available for the insert to complete. this.root
//					points to a node in a SearchTree object.
//	Postconditions:	Comparable object is inserted into a Node object and added to the 
//					*this if comparable is not already in *this. True is returned if 
//					comparable is inserted. Otherwise, false is returned.
bool SearchTree::insert(Comparable* comparable) {
	return insertHelper(root, comparable);
}


//-----------------------------------  insertHelper  -----------------------------------
//	Helper function that inserts comparable object into *this recursively.
//	Preconditions:	There is enough memory available for nodes to be added. current points
//					to node in *this or nullptr. comparable encapsualtes a char.
//	Postconditions:	bool value is returned. if comparable is not found in *this and therefore
//					inserted, true is returned. if comparable object is already found in
//					*this, the count for current is incremented and false is returned.
bool SearchTree::insertHelper(Node*& current, Comparable* comparable) {
	// If nodeptr is nullptr (can be inserted)
	if (current == nullptr) {
		current = new Node;
		current->item = comparable;
		current->left = nullptr;
		current->right = nullptr;
		current->count = 1;
		return true;
	}
	// Handle when object already in tree
	else if (*current->item == *comparable) {
		current->count++;
		return false;
	}
	// comparable less than current->item so traverse left
	else if (*comparable < *current->item) {
		return insertHelper(current->left, comparable);
	}
	// comparable is greater than current->item so traverse right
	else {
		return insertHelper(current->right, comparable);
	}
}


//--------------------------------------  remove  --------------------------------------
//	Removes a comparable object from the SearchTree object
//	Preconditions:	comparable is an object that encapsulates a char. *this.root points 
//					to a node or nullptr in a SearchTree object.
//	Postconditions:	bool value is returned. true is returned if comparable object is 
//					found and Node object is deleted if only 1 occurrence or count is 
//					decremented if more than 1 occurrence. Otherwise, false is returned.
//					searchTree object is changed by having node or occurrence removed.
bool SearchTree::remove(const Comparable& comparable) {
	return removeHelper(root, comparable);
}


//----------------------------------  removeHelper  ----------------------------------
//	Helper method to remove that supports recursively searching SearchTree object to 
//	find comparable object and delete or decrement count if found.
//	Preconditions:	comparable encapsulates a char. current points to nullptr or a node
//					object in the searchTree object.
//	Postconditions:	bool value is returned. If comparable is found in the SearchTree
//					then it is deleted, or current.count is decremented if more than 1
//					occurrance. Otherwise, false is returned.
bool SearchTree::removeHelper(Node*& current, const Comparable& comparable) {
	if (current == nullptr) {
		return false;
	}
	else if (comparable == *current->item) {
		// Check for occurrences and handle appropriately
		if (current->count > 1) {
			current->count--;
			return true;
		}
		// Last occurrence - remove node
		else {
			deleteRoot(current);
			return true;
		}
	}
	else if (comparable < *current->item) {
		return removeHelper(current->left, comparable);
	}
	else {
		return removeHelper(current->right, comparable);
	}
}


//----------------------------------  deleteRoot  ----------------------------------
//	Helper method to remove that deletes a root node.
//	Preconditions:	current points to a node in the searchTree object. 
//	Postconditions:	void function and nothing is returned. root node is deleted and
//					another helper method is called to maintain proper binary search
//					tree qualities. current->item is changed to the value returned
//					from the smallest value in the right subtree.
void SearchTree::deleteRoot(Node*& current) {
	delete current->item;

	// Case where node has no children
	if (current->left == nullptr && current->right == nullptr) {
		delete current;
		current = nullptr;
	}

	// Case where node has 1 child
	else if (current->left == nullptr || current->right == nullptr) {
		Node* temp = current;
		current = current->left == nullptr ? current->right : current->left;
		delete temp;
	}

	// Case where node has 2 children
	// Traverse and find / replace with smallest value on right subtree
	else {
		//occurrence helper to get count of comparable that will move into node
		current->count = occurrenceHelper(current->right);
		current->item = findAndDeleteMostLeft(current->right);
	}
}


//-----------------------------  findAndDeleteMostLeft  -----------------------------
//	Supports the deleteRoot method and finds the smallest value in the right subtree
//	of the root being deleted.
//	Preconditions:	current points to a node in the searchTree object or nullptr.
//	Postconditions:	current-> item is returned to deleteRoot method which stores 
//					the value returned. smallest node in the subtree is deleted and
//					pointers are corrected to maintain searchTree.
Comparable* SearchTree::findAndDeleteMostLeft(Node*& current) {
	if (current->left == nullptr) {
		Comparable* item = current->item;
		Node* temp = current;
		current = current->right;
		delete temp;
		return item;
	}
	else {
		return findAndDeleteMostLeft(current->left);
	}
}


//-------------------------------------  occurrenceHelper  --------------------------------------
//	Helper method to get occurrence count of node being deleted
//	Preconditions:	 current points to a node in a SearchTree object			
//	Postconditions:	integer is returned with the occurrence count of a node that will be deleted
int SearchTree::occurrenceHelper(Node* current) const {
	if (current->left == nullptr) {
		//Node* temp = current;	
		return current->count;
	}
	else {
		return occurrenceHelper(current->left);
	}
}


//-------------------------------------  makeEmpty  -------------------------------------
//	Makes the searchTree object empty and deallocates memory.
//	Preconditions:	this is pointing to a node in a SearchTree object.
//	Postconditions:	the SearchTree object is empty and has no nodes or dynamically 
//					allocated memory
void SearchTree::makeEmpty() {
	// call clearTree and pass in root node
	clearTree(root);
}


//-----------------------------------  clearTree  -------------------------------------
//	Clears and deletes nodes in a SearchTree object recursively.
//	Preconditions:	current points to a node in a SearchTree object.
//	Postconditions:	nothing is returned. the SearchTree object is empty and has no 
//					nodes or dynamically allocated memory. comparable objects are deleted
void SearchTree::clearTree(Node*& current) {
	if (current != nullptr) {
		clearTree(current->left);
		clearTree(current->right);
		delete current->item;
		current->item = nullptr;
		delete current;
		current = nullptr;
	}
}


//-------------------------------------  retrieve  --------------------------------------
//	Finds a comparable object in a SearchTree object
//	Preconditions:	comparable encapsulates a char. this.root points to a node in a SearchTree 
//					object
//	Postconditions:	Comparable object is returned if found, otherwise nullptr is returned
Comparable* SearchTree::retrieve(const Comparable& comparable) const {
	return retrieveHelper(root, comparable);
}


//-------------------------------------  retrieveHelper  --------------------------------------
//	Helper method to retrieve that searches a SearchTree object recursively
//	Preconditions:	comparable encapsulates a char. current points to a node in a SearchTree
//					object
//	Postconditions:	if the comparable object is found in the SearchTree object then the pointer 
//					to comparable is returned. Otherwise, nullptr is returned.
Comparable* SearchTree::retrieveHelper(const Node* current, const Comparable& comparable) const {
	if (current == nullptr) {
		return nullptr;
	}
	else if (*current->item == comparable) {
		return current->item;
	}
	else if (comparable < *current->item) {
		return retrieveHelper(current->left, comparable);
	}
	else {
		return retrieveHelper(current->right, comparable);
	}
}


//---------------------------------------  height  ---------------------------------------
//	Get the height of a Comparable object in relation to its desendants
//	Preconditions:	comparable encapsulates a char. this.root points to a node in a 
//					SearchTree object
//	Postconditions:	the height of comparable in integer form is returned if comparable is
//					found. Otherwise, -1 is returned.
int SearchTree::height(const Comparable& comparable) const {
	Node* current = root;
	while (current != nullptr) {
		if (*current->item == comparable) {
			return (heightHelper(current) - 1);
		}
		else if (comparable < *current->item) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	// comparable not found
	return -1;
}

bool SearchTree::isRootNull() const {
	return (root == nullptr);
}


//----------------------------------  heightHelper  ----------------------------------
//	Find the height of a node in relation to its descendants
//	Preconditions:	current points to a in the searchTree object
//	Postconditions:	the height of current in relation to its descendants is returned in 
//					integer form. If it is a leaf node, 0 is returned. Otherwise, the 
//					larger height between its left subtree an right subtree is returned
int SearchTree::heightHelper(Node* current) const {
	if (current == nullptr) {
		return 0;
	}
	else {
		int leftTreeDepth = heightHelper(current->left);
		int rightTreeDepth = heightHelper(current->right);
		// return the larger of the 2 subtree depths
		return (leftTreeDepth > rightTreeDepth ? leftTreeDepth + 1 : rightTreeDepth + 1);
	}
}


//---------------------------------------  <<  ---------------------------------------
//	Overloaded output operator for SearchTree class
//	Preconditions:	this.root points to a node in searchTree
//	Postconditions:	searchTree is traversed in an inorder fashion and all values are 
//					sent to ostream. ostream is returned
ostream& operator<<(ostream& outStream, const SearchTree& searchTree) {
	searchTree.inOrderPrint(outStream, searchTree.root);
	return outStream;
}


//----------------------------------  inOrderPrint  ----------------------------------
//	Print values in the searchTree object in an inorder traversal
//	Preconditions:	current points to a node in the searchTree object
//	Postconditions:	the searchTree is traversed recursively in inorder fashion and the
//					comparable objects and their count are printed from each node 
//					visited
void SearchTree::inOrderPrint(ostream& outStream, const Node* current) const {
	if (current != nullptr) {
		inOrderPrint(outStream, current->left);
		current->item->displayInformation();
		cout << endl;
		inOrderPrint(outStream, current->right);
	}
}