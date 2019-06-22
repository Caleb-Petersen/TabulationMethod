#include <iostream>
#include <vector>
#include <ctype.h>

//should put declarations into a .h file
int main();
void getMinterms();
std::vector<unsigned int>parseMinterms (std::string const minterms);

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
	//Convert the string
	minterms = parseMinterms(mintermStr);
}

std::vector<unsigned int> parseMinterms (std::string const minterms) {
	//takes in a string with the minterms (and whatever separators the user adds)
	//returns an array of the minterms
	std::vector<unsigned int> parsedMinterms;

	for(std::size_t i=0; i<minterms.size(); i++) {
		if(isdigit(minterms.at(i)) && (int)minterms.at(i) >= 0) {
			parsedMinterms.push_back(minterms.at(i));
		}
	}

	return parsedMinterms;
}
