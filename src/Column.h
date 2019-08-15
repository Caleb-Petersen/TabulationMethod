/*
 * Column.h
 *
 *  Created on: Jun. 22, 2019
 *      Author: Caleb
 */
#include <vector>
#include "Element.h"

#ifndef COLUMN_H_
#define COLUMN_H_

class Column {
	public:
		std::vector<Element> column;

		void sortByGroup();
		Column reduceColumn();

		Column();
		virtual ~Column();
};

#endif /* COLUMN_H_ */
