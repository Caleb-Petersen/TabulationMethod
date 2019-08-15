/*
 * Conversions.cpp
 *
 *  Created on: Jun. 22, 2019
 *      Author: Caleb
 */
#include <iostream>
#include <vector>
#include <ctype.h>
#include <cmath>

std::vector<unsigned int> parseMinterms (std::string const minterms) {
	//takes in a string with the minterms (and whatever separators the user adds)
	//returns an array of the minterms
	std::vector<unsigned int> parsedMinterms;

	for(std::size_t i=0; i<minterms.size(); i++) {
		if(isdigit(minterms.at(i)) && (int)minterms.at(i) >= 0) {
			parsedMinterms.push_back(minterms.at(i)-'0');
		}
	}

	return parsedMinterms;
}

std::vector<char> convertToBinary(unsigned const int numDigits, unsigned const int n) {
	//takes in a number of outputs for the binary value and the value n to be converted
	std::vector<char> binary;
	int value = n;

	for(std::size_t i=numDigits; i>0; i--) {
		if(value-pow(2, i) >=0) {
			binary.push_back('1');
			value -= pow(2,i);
		}else {
			binary.push_back('0');
		}
	}
	return binary;
}


