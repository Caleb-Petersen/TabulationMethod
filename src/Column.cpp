/*
 * Column.cpp
 *
 *  Created on: Jun. 22, 2019
 *      Author: Caleb
 */

#include "Column.h"

Column::Column() {

}

void Column::sortByGroup() {
	//insertion sort the column by group
	for(std::size_t i=0; i< this->column.size(); i++) {
		for(std::size_t j=i+1; j<this->column.size(); j++) {
			if(this->column.at(j).getGroupNumber() > this->column.at(i).getGroupNumber()) {
				std::swap(this->column.at(j), this->column.at(i));
			}
		}
	}
}

std::vector<Column> Column::reduceColumn() {
	//Reduces the column
	//Sorts
	Column reducedColumn{};

	//Sort the column before reducing
	this->sortByGroup();

	unsigned int currentGroup = 0;
	unsigned int lowerBound = 0;
	unsigned int upperBound = 0;

	for(std::size_t i=0; i< this->column.size(); i++) {
		if(this->column.at(i).groupNumber == currentGroup) {
			//check for reduction possibilities by computing the differences for the lowerBound to the upperBound
			for(std::size_t j=lowerBound; j<=upperBound; j++) {
				//compute diff for column.at(i) and column.at(j). If the diff is equal to one,
				//the is reduced to true and add the new combined element to the reduced column
			}
		}else if(this->column.at(i).groupNumber == currentGroup + 1) {
			//reset the group and bounds
			currentGroup += 1;
			lowerBound = upperBound + 1;
			upperBound = i-i;

			//compute diff for all elements between the lower and upper bounds and reduce
		}else if(this->column.at(i).groupNumber > currentGroup + 1) {
			//handles missing groups
			lowerBound = i;
			upperBound = i;
			currentGroup = i;
			//NOTE: this will cause an issue when the next element is of the same group as this current group as it will try to compute
			// a diff between members of the same group. I suppose diff could only be computed if the groups of elements are equal....
		}
	}

	return reducedColumn;
}

Column::~Column() {
	// TODO Auto-generated destructor stub
}
