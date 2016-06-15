/*
 * Bishop.cpp
 *
 *  Created on: 2 febr. 2016
 *      Author: Jordi Marco
 */

#include<cstdlib>
#include "Bishop.h"
#include "ChessBoard.h"

Bishop::Bishop(Color color) : ChessPiece(color) {
	// TODO Auto-generated constructor stub
}

Bishop::~Bishop() {
	// TODO Auto-generated destructor stub
}

bool Bishop::canMoveTo(int row, int column) const {
	if(!ChessPiece::canMoveTo(row,column)) return false;
	int dr = row-this->row;
	int dc = column-this->column;
	// Bishop can only move in diagonal
	if(abs(dr)!=abs(dc)) return false;
	int incR = dr/abs(dr);
	int incC = dc/abs(dc);
	int r = this->row+incR;
	int c = this->column+incC;
	while(r!=row || c!=column) {
		// Bishop cannot move through an occupied square
		if(!chessBoard->isEmpty(r,c)) return false;
		r += incR;
		c += incC;
	}
	return true;
}

std::string Bishop::toString() const {
	return ChessPiece::toString().replace(0,1,"B");
}

