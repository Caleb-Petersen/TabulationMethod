/*
 * Column.h
 *
 *  Created on: Jun. 22, 2019
 *      Author: Caleb
 */
#include <iostream>
#include <vector>
#include "Element.h"
#include "Conversions.h"

#ifndef COLUMN_H_
#define COLUMN_H_

class Column {
	public:
		std::vector<Element> columnElements;

		void sortByGroup();
		Column reduceColumn(bool &reductionComplete);

		Column(std::vector<Element> c);
		virtual ~Column();
};

#endif /* COLUMN_H_ */
