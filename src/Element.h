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
		std::vector<unsigned int> getMintermSources();
		std::vector<char> getMintermBinary();
		bool getIsReduced();
		unsigned int getGroupNumber();

		void setIsReduced(bool r);

		Element(unsigned int numElements, unsigned int elementValue);
		Element(std::vector<char> mBinary, std::vector<unsigned int> mSources);
		virtual ~Element();
	private:
		void updateGroupNumber();
		bool isReduced;
		std::vector<unsigned int> mintermSources;
		unsigned int groupNumber; //Number of 1s in the mintermBinary
		std::vector<char> mintermBinary;
};

#endif /* ELEMENT_H_ */
