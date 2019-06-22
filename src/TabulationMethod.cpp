#include <iostream>
#include <vector>
#include <ctype.h>
#include <cmath>
#include "Conversions.h"

//should put declarations into a .h file
int main();
void getMinterms();

int main() {
	getMinterms();
	return 0;
}

void getMinterms() {
	unsigned int n=0;
	std::string mintermStr = "";
	std::vector<unsigned int> minterms;

	//Get the number of inputs
	std::cout << "Please enter the number of inputs to the boolean function" << std::endl;
	std::cin >> n;

	//Get the minterms in a string separated by commas
	std::cout << "Enter all of the minterms in integer form for the boolean function separated by commas, (e.g. 1,2,3,4,5,6)" << std::endl;
	std::cin >> mintermStr;

	//Convert the string into an array of unsigned integers
	minterms = parseMinterms(mintermStr);
}


