/*
 * Rook.cpp
 *
 *  Created on: 2 febr. 2016
 *      Author: Jordi
 */

#include<cstdlib>
#include "Rook.h"
#include "ChessBoard.h"

Rook::Rook(Color color) : ChessPiece(color) {
	// TODO Auto-generated constructor stub
}

Rook::~Rook() {
	// TODO Auto-generated destructor stub
}

bool Rook::canMoveTo(int row, int column) const {
	if(!ChessPiece::canMoveTo(row,column)) return false;
	int dr = row-this->row;
	int dc = column-this->column;
	// Rook can only move in one direction, horizontally or vertically
	if(dr!=0 && dc!=0) return false;
	int incR = dr==0?0:dr/abs(dr);
	int incC = dc==0?0:dc/abs(dc);
	int r = this->row+incR;
	int c = this->column+incC;
	while(r!=row || c!=row) {
		// Rook cannot move through an occupied square
		if(!chessBoard->isEmpty(r,c)) return false;
		r += incR;
		c += incC;
	}
	return true;
}

std::string Rook::toString() const {
	return ChessPiece::toString().replace(0,1,"R");
}

bool Rook::isOnStartingRank() const {
	return true;
}
