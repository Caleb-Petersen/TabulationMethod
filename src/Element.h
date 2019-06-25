/*
 * Element.h
 *
 *  Created on: Jun. 22, 2019
 *      Author: Caleb
 */
#include <vector>
#include "Conversions.h"

#ifndef ELEMENT_H_
#define ELEMENT_H_

class Element {
	public:
		int getMintermInt();
		std::vector<char> getMintermBinary();
		bool getIsReduced();
		unsigned int getGroupNumber();

		Element(unsigned int n);
		virtual ~Element();
	private:
		bool isReduced;
		unsigned int mintermInt;
		unsigned int groupNumber; //Number of 1s in the mintermBinary
		std::vector<char> mintermBinary;
};

#endif /* ELEMENT_H_ */
