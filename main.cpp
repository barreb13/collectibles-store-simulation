//---------------------------------------------------------------------------------
// main.cpp
// Author: Brent Barrese
// 
//---------------------------------------------------------------------------------
// main.cpp
//  Driver program for Program 4
//   --	Opens customer file
//   --	Opens inventory file
//   -- Opens command file
//   -- Processes all files
//   -- Closes all files
//
// Assumptions:
//   -- All classes have been created and compile
//   -- input files are in project folder
//---------------------------------------------------------------------------------

//#include "vld.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Store.h"

using namespace std;


int main() {
    {
        int i = 1;
    // Store file names
    string customerFile = "hw4customers.txt";
    string inventoryFile = "hw4inventory.txt";
    //string commandFile = "hw4commands.txt";
    string commandFile = "brentsCommands.txt";

    // Open file stream
    ifstream customerStream(customerFile);
    if (!customerStream) {
        cerr << "File could not be opened" << endl;
        return 1;
    }

    ifstream inventoryStream(inventoryFile);
    if (!inventoryStream) {
        cerr << "File could not be opened" << endl;
        return 1;
    }

    ifstream commandStream(commandFile);
    if (!commandStream) {
        cerr << "File could not be opened" << endl;
        return 1;
    }

    //Open store
    Store BrentsCollectibles;

    BrentsCollectibles.setCustomers(customerStream);

    BrentsCollectibles.setCollectibleItems(inventoryStream);

    BrentsCollectibles.processTransactions(commandStream);

    //close the streams
    customerStream.close();
    inventoryStream.close();
    commandStream.close();
}
}
