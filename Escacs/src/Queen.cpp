/*
 * Queen.cpp
 *
 *  Created on: 2 febr. 2016
 *      Author: Jordi Marco
 */

#include<cstdlib>
#include "Queen.h"
#include "ChessBoard.h"

Queen::Queen(Color color) : ChessPiece(color) {
	// TODO Auto-generated constructor stub
}

Queen::~Queen() {
	// TODO Auto-generated destructor stub
}

bool Queen::canMoveTo(int row, int column) const {
	if(!ChessPiece::canMoveTo(row,column)) return false;
	int dr = row-this->row;
	int dc = column-this->column;
	// Queen can move in diagonal or in one direction, horizontally or vertically
	if(abs(dr)!=abs(dc) && dr!=0 && dc!=0) return false;
	int incR = dr==0?0:dr/abs(dr);
	int incC = dc==0?0:dc/abs(dc);
	int r = this->row+incR;
	int c = this->column+incC;
	while(r!=row || c!=row) {
		// Bishop cannot move through an occupied square
		if(!chessBoard->isEmpty(r,c)) return false;
		r += incR;
		c += incC;
	}
	return true;
}

std::string Queen::toString() const {
	return ChessPiece::toString().replace(0,1,"Q");
}

