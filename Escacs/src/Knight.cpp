/*
 * Knight.cpp
 *
 *  Created on: 28 gen. 2016
 *      Author: Jordi Marco
 */

#include<cstdlib>
#include "Knight.h"

Knight::Knight(Color color) : ChessPiece(color) {
	// TODO Auto-generated constructor stub
}

Knight::~Knight() {
	// TODO Auto-generated destructor stub
}

bool Knight::canMoveTo(int row, int column) const {
	int dr = abs(this->row-row);
	int dc = abs(this->column-column);
	return ChessPiece::canMoveTo(row,column) && ((dr==2 && dc==1) || (dr==1 && dc==2));
}

std::string Knight::toString() const {
	return ChessPiece::toString().replace(0,1,"N");
}
