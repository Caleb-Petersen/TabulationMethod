/*
 * Column.cpp
 *
 *  Created on: Jun. 22, 2019
 *      Author: Caleb
 */

#include "Column.h"

Column::Column(std::vector<Element> c) {
	this->column = c;
}

void Column::sortByGroup() {
	//insertion sort the column by group
	for(std::size_t i=0; i< this->column.size(); i++) {
		for(std::size_t j=i+1; j<this->column.size(); j++) {
			if(this->column.at(j).getGroupNumber() < this->column.at(i).getGroupNumber()) {
				std::swap(this->column.at(j), this->column.at(i));
			}
		}
	}
}

Column Column::reduceColumn() {
	//Reduces the column
	//Sorts
	std::vector<Element> reducedElements;
	//Sort the column before reducing in case it isn't already sorted
	this->sortByGroup();

	unsigned int currentGroup = 0;
	unsigned int lowerBound = 0;
	unsigned int upperBound = 0;
	bool columnReduced = false;

	for(std::size_t i=0; i< this->column.size(); i++) {
		if(this->column.at(i).getGroupNumber() == currentGroup) {
			//check for reduction possibilities by computing the differences for the lowerBound to the upperBound
			for(std::size_t j=lowerBound; j<=upperBound; j++) {
				if(mintermBinaryDiff(this->column.at(i).getMintermBinary(),this->column.at(j).getMintermBinary()) == 1 &&
						this->column.at(i).getGroupNumber() != this->column.at(j).getGroupNumber()) {
					//The columns are only reduced if they are in different groups with a difference of 1
					columnReduced = true;
					this->column.at(i).setIsReduced(true);
					this->column.at(j).setIsReduced(true);

					//combine the minterms and sources for the new element
					std::vector<char> mB = combineMinterms(this->column.at(i).getMintermBinary(),this->column.at(j).getMintermBinary());
					std::vector<unsigned int> mS = this->column.at(i).getMintermSources();

					mS.insert(mS.end(), this->column.at(j).getMintermSources().begin(), this->column.at(j).getMintermSources().end()); //may have shallow copies

					Element element{mB, mS};
					reducedElements.push_back(element);
				}

			}
		}else if(this->column.at(i).getGroupNumber() == currentGroup + 1) {
			//reset the group and bounds
			currentGroup += 1;
			lowerBound = upperBound + 1;
			upperBound = i-i;

			//compute diff for all elements between the lower and upper bounds and reduce
		}else if(this->column.at(i).getGroupNumber() > currentGroup + 1) {
			//handles missing groups
			lowerBound = i;
			upperBound = i;
			currentGroup = i;
			// NOTE: this will cause an issue when the next element is of the same group as this current group as it will try to compute
			// a diff between members of the same group. I suppose diff could only be computed if the groups of elements are equal....
		}
	}

	return Column(reducedElements);
}

Column::~Column() {
	// TODO Auto-generated destructor stub
}
