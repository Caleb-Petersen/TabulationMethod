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
}

Element::~Element() {
	// TODO Auto-generated destructor stub
}

