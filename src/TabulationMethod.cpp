#include <iostream>
#include <vector>
#include <ctype.h>
#include <cmath>
#include "Conversions.h"
#include "Column.h"

//should put declarations into a .h file
int main();
std::vector<unsigned int> getMinterms(unsigned int &numInputs);

int main() {
	//Get all of the minterms from cin
	unsigned int numInputs = 0; //The total number of minterms possible
	std::vector<unsigned int> minterms = getMinterms(numInputs);

	//convert the minterms to elements
	std::vector<Element> elements;

	for(unsigned int minterm : minterms) {
		Element element{numInputs, minterm};
		elements.push_back(element);
	}

	//Create the first column
	Column column{elements};
	column.sortByGroup();
	//Print out to check correctness of elements
	for(Element e : column.column) {
		std::cout << "Group Number: " << e.getGroupNumber() << std::endl;
		std::cout << "Minterm value: " << e.getMintermSources().at(0) << std::endl;

		std::cout << "Character Array: ";
		for(char c : e.getMintermBinary()) {
			std::cout << c;
		}
		std::cout << std::endl;
	}

	return 0;
}

std::vector<unsigned int> getMinterms(unsigned int &numInputs) {
	std::string mintermStr = "";
	std::vector<unsigned int> minterms;

	//Get the number of inputs
	std::cout << "Please enter the number of inputs to the boolean function" << std::endl;
	std::cin >> numInputs;

	//Get the minterms in a string separated by commas
	std::cout << "Enter all of the minterms in integer form for the boolean function separated by commas, (e.g. 1,2,3,4,5,6)" << std::endl;
	std::cin >> mintermStr;

	//Convert the string into an array of unsigned integers
	minterms = parseMinterms(mintermStr);

	return minterms;
}


