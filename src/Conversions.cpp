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

	for(int i=numDigits-1; i>=0; i--) {
		if(value-pow(2, i) >=0) {
			binary.push_back('1');
			value -= pow(2,i);
		}else {
			binary.push_back('0');
		}
	}
	return binary;
}

unsigned int mintermBinaryDiff(std::vector<char> a, std::vector<char> b) {
	//could be put somewhere else too. Computes the diff between two element minterm binarys
	if(a.size() != b.size()) {
		return 0; //Error case that should never occur. Diff 0 should cause as few problems as possible
	}

	unsigned int diff = 0;
	for(std::size_t i=0; i<a.size(); i++) {
		if(a.at(i) != b.at(i)) {
			diff++;
		}
	}

	return diff;
}

std::vector<char> combineMinterms(std::vector<char> a, std::vector<char> b) {
	//the assumption is diff is 1
	//this also could be put elsewhere

	//This function replaces the single different term with a dash
	std::vector<char> combinedMintermBinary;

	for(std::size_t i=0; i<a.size(); i++) {
		if(a.at(i) != b.at(i)) {
			combinedMintermBinary.push_back('-');
		}else {
			combinedMintermBinary.push_back(a.at(i));
		}
	}

	return combinedMintermBinary;
}
