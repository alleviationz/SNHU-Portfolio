#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <fstream>
using namespace std;
#include "MenuHandler.h"

void MenuHandler::PrintMenu() {																	// print menu with options and formatting
	cout << setfill('-') << setw(50) << "" << endl;
	cout << setfill(' ') <<  setw(25) << "Menu" << endl;
	cout << setfill('-') << setw(50) << "" << endl;
	cout << setfill(' ') << "1.) Check for the purchase frequency a specific item" << endl;		// option to retrieve specific item and count
	cout << "2.) Print the frequency of all item purchases" << endl;							// option to retrieve all items and count
	cout << "3.) Print the frequency of all item purchases as a histogram" << endl;				// option to retrieve all items and count as histogram
	cout << "4.) Exit" << endl;																	// option to exit program
	cout << setfill('-') << setw(50) << "" << endl;
}

unordered_map<string, int> MenuHandler::GetMap() {												// MenuHandler map getter
	return this->itemFrequency;
}

void MenuHandler::SetMap(unordered_map<string, int> itemFrequency) {							// MenuHandler map setter
	this->itemFrequency = itemFrequency;
}

void MenuHandler::OptionOne() {																	// first option function to retrieve specific item
	string userItem;
	cout << "Please enter item to search for (case-sensitive): " << endl;						// get input item as string

	cin >> userItem;
	if (this->itemFrequency.count(userItem) == 1) {												// check if item in map
		cout << userItem << ": " << this->itemFrequency.at(userItem) << endl;					// output item and frequency
	}
	else {
		cout << userItem << " not in purchases" << endl;										// item not found -> output and notify user
	}
}

void MenuHandler::OptionTwo() {																	// second option function to retrieve all items and purchase counts
	unordered_map<string, int>::iterator itr;
	for (itr = this->itemFrequency.begin(); itr != this->itemFrequency.end(); itr++) {			// iterate over all items in map
		cout << itr->first << ": " << itr->second << endl;										// output each item and its purchase count
	}
}

void MenuHandler::OptionThree() {																// third option function to retrieve all items and purchase counts as a histogram
	unordered_map<string, int>::iterator itr;
	for (itr = this->itemFrequency.begin(); itr != this->itemFrequency.end(); itr++) {			// iterate over map
		cout << itr->first << string(itr->second, '*') << endl;									// output item name and repeat '*' purchase number of times
	}
}

void MenuHandler::WriteItems(string path) {														// function to iterate over items and write item and count to a new file
	ofstream outFS;
	outFS.open(path);

	if (!outFS.is_open()) {																		// ensure file opened properly, else notify user and exit function
		cout << "Could not open output file." << endl;
		return;
	}

	unordered_map<string, int>::iterator itr;
	for (itr = this->itemFrequency.begin(); itr != this->itemFrequency.end(); itr++) {			// iterate over all items in map
		outFS << itr->first << ": " << itr->second << endl;										// output each item and its purchase count
	}

	outFS.close();																				// close filestream
}

void MenuHandler::OptionChooser(int choice) {													// menu choice function to take in user choice and call appropriate option function
	if (choice == 1) {
		OptionOne();
	}
	else if (choice == 2) {
		OptionTwo();
	}
	else if (choice == 3) {
		OptionThree();
	}
	else if (choice == 4) {
		return;
	}
	else {																						// user entered a non-acceptable choice, recall function
		cout << "Invalid option. Please pick a valid option." << endl;
	}

	return;
}