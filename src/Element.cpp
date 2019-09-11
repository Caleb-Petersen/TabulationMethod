/*
 * Element.cpp
 *
 *  Created on: Jun. 22, 2019
 *      Author: Caleb
 */

#include "Element.h"

Element::Element(unsigned int numElements, unsigned int elementValue) {
	this->isReduced = false;
	this->mintermSources.push_back(elementValue);
	this->mintermBinary = convertToBinary(numElements, elementValue); //need to get the number of possible elements here
	this->groupNumber = 0; //just to initialize it, it is changed in the update group number function
	updateGroupNumber();
}

Element::Element(std::vector<char> mBinary, std::vector<unsigned int> mSources) {
	this->isReduced = false;
	this->mintermSources = mSources;
	this->mintermBinary = mBinary;
	this->groupNumber = 0;
	updateGroupNumber();
}
void Element::updateGroupNumber() {
	//Updates the group number based on the minterm binary array which may not be initialized or may change
	unsigned int groupCounter;
	for(char element: this->mintermBinary) {
		if(element == '1') {
			groupCounter++;
		}
	}
	this->groupNumber = groupCounter;
}
std::vector<unsigned int> Element::getMintermSources() {
	return this->mintermSources;
}

std::vector<char> Element::getMintermBinary() {
	return this->mintermBinary;
}

bool Element::getIsReduced() {
	return this->isReduced;
}
void Element::setIsReduced(bool r) {
	this->isReduced = r;
}

unsigned int Element::getGroupNumber() {
	return this->groupNumber;
}

Element::~Element() {
	// TODO Auto-generated destructor stub
}

