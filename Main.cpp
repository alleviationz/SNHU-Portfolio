#include <iostream>																						// sourcing setup
#include <fstream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
#include "MenuHandler.h"

int main() {
	int userInput = -1;																					// variable declarations
	string item;
	ifstream itemFS;
	MenuHandler menuHandler;
	string path = "/CS210_Project_Three_Input_File.txt";
																										// path to file, prepend local path
	string outPath = "/Novak CS-210 Project 3/Novak CS-210 Project 3/frequency.dat";					// output file path
	unordered_map<string, int> itemFrequency;

	itemFS.open(path);																					// open file

	if (!itemFS.is_open()) {																			// check that file opened properly, notify user if unable to open
		cout << "Could not open file" << endl;
		cout << "If local path not prepended to txt file, please prepend path." << endl;
		return 1;
	}

	while (!itemFS.fail()) {																			// iterate through items in file
		getline(itemFS, item);
		
		if (itemFrequency.count(item) == 0) {															// if item isnt already in map, emplace it
			itemFrequency.emplace(item, 1);
		}
		else {
			itemFrequency.at(item) += 1;																// if item is already mapped, increase the value count
		}
	}

	itemFS.close();																						// close file

	menuHandler.SetMap(itemFrequency);																	// set the map info inside the MenuHandler class object

	while (userInput != 4) {																			// loop until user wants to quit
		menuHandler.PrintMenu();																		// call display menu

		cin >> userInput;																				// get user choice and validate
		cin.clear();
		cin.ignore(256, '\n');

		while ((cin.fail()) || (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4)) {
			cout << "Please enter a valid number." << endl;
			cin >> userInput;
			cin.clear();
			cin.ignore(256, '\n');
		}

		menuHandler.OptionChooser(userInput);															// input the choice into the class object to process
	}

	menuHandler.WriteItems(outPath);																	// call menu handler's write output file function

	cout << "Goodbye!" << endl;																			// indicate end of program after loop

	return 0;
};