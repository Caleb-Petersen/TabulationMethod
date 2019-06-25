/*
 * Element.cpp
 *
 *  Created on: Jun. 22, 2019
 *      Author: Caleb
 */

#include "Element.h"

Element::Element(unsigned int n) {
	this->isReduced = false;
	this->mintermInt = n;
	this->mintermBinary = convertToBinary(4, n); //need to get the number of possible elements here
	this->groupNumber = 0;
}

int Element::getMintermInt() {
	return this->mintermInt;
}

std::vector<char> Element::getMintermBinary() {
	return this->mintermBinary;
}

bool Element::getIsReduced() {
	return this->isReduced;
}

unsigned int Element::getGroupNumber() {
	return this->groupNumber;
}

Element::~Element() {
	// TODO Auto-generated destructor stub
}

