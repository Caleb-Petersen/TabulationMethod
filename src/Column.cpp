/*
 * Column.cpp
 *
 *  Created on: Jun. 22, 2019
 *      Author: Caleb
 */

#include "Column.h"

Column::Column(std::vector<Element> c) {
	this->columnElements = c;
}

void Column::sortByGroup() {
	//insertion sort the column by group
	for(std::size_t i=0; i< this->columnElements.size(); i++) {
		for(std::size_t j=i+1; j<this->columnElements.size(); j++) {
			if(this->columnElements.at(j).getGroupNumber() < this->columnElements.at(i).getGroupNumber()) {
				std::swap(this->columnElements.at(j), this->columnElements.at(i));
			}
		}
	}
}

Column Column::reduceColumn() {
	std::vector<Element> reducedElements;

	this->sortByGroup(); //The column has to be sorted in order for reduction to work.
	unsigned int highestGroupNumber = this->columnElements.at(this->columnElements.size() - 1).getGroupNumber();

	for(std::size_t group=0; group<highestGroupNumber; group++) {
		for(std::size_t i=0; i<this->columnElements.size(); i++) {
			if(this->columnElements.at(i).getGroupNumber() == group) {
				//Loop through all elements from the current one to the end of the array or until the next group number is reached
				for(std::size_t j=i+1; (j < this->columnElements.size()) && (this->columnElements.at(j).getGroupNumber() < (group + 2)); j++) {
					//Reduce the columns if they are in different groups with a difference of 1
					if(mintermBinaryDiff(this->columnElements.at(i).getMintermBinary(),this->columnElements.at(j).getMintermBinary()) == 1) {
						std::cout << "Found a diff of 1" << std::endl;

						this->columnElements.at(i).setIsReduced(true);
						this->columnElements.at(j).setIsReduced(true);

						//combine the minterms and sources for the new element
						std::vector<char> mB = combineMinterms(this->columnElements.at(i).getMintermBinary(),this->columnElements.at(j).getMintermBinary());
						std::vector<unsigned int> mS = this->columnElements.at(i).getMintermSources();

						mS.insert(mS.end(), this->columnElements.at(j).getMintermSources().begin(), this->columnElements.at(j).getMintermSources().end()); //may have shallow copies

						Element element{mB, mS};
						reducedElements.push_back(element);
					}
				}
			}
		}
	}

	return Column(reducedElements);
}

Column::~Column() {
	// TODO Auto-generated destructor stub
}
