#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include <map>
#include <unordered_map>

class MenuHandler {													// class initialization
	public:															// public attributes and functions
		void SetMap(unordered_map<string, int>);
		unordered_map<string, int> GetMap();
		void PrintMenu();
		void OptionChooser(int choice);
		void WriteItems(string path);
	private:														// private attributes and functions
		int choice;
		unordered_map<string, int> itemFrequency;
		void OptionOne();
		void OptionTwo();
		void OptionThree();
};

#endif