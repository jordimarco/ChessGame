/*
 * King.cpp
 *
 *  Created on: 28 gen. 2016
 *      Author: Jordi Marco
 */

#include<cstdlib>
#include "King.h"

King::King(Color color) : ChessPiece(color) {
	// TODO Auto-generated constructor stub
}

King::~King() {
	// TODO Auto-generated destructor stub
}

bool King::canMoveTo(int row, int column) const {
	int dr = abs(this->row-row);
	int dc = abs(this->column-column);
	return ChessPiece::canMoveTo(row,column) && dr<=1 && dc<=1;
}

std::string King::toString() const {
	return ChessPiece::toString().replace(0,1,"K");
}
