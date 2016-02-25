/*
 * Pawn.cpp
 *
 *  Created on: 28 gen. 2016
 *      Author: Jordi Marco
 */

#include<cstdlib>
#include "Pawn.h"
#include "ChessBoard.h"

static const int startingRankByColor[] = {1,6};

Pawn::Pawn(Color color) : ChessPiece(color) {
	// TODO Auto-generated constructor stub
}

Pawn::~Pawn() {
	// TODO Auto-generated destructor stub
}

bool Pawn::canMoveTo(int row, int column) const {
	if(!ChessPiece::canMoveTo(row,column)) return false;
	int dr = this->getColor()==Color::BLACK?this->row-row:row-this->row;
	int dc = abs(this->column-column);
	// Pawn captures a piece
	if(dr==1 && dc==1 && !chessBoard->isEmpty(row,column)) return true;
	// Pawn advances a single square
	if(dr==1 && dc==0 && chessBoard->isEmpty(row,column)) return true;
	// Pawn on its starting rank advances two empty squares
	if(dr==2 && dc==0 && this->isOnStartingRank() && chessBoard->isEmpty(row,column)) {
		int middleRow = this->row>row?row+1:row-1;
		if(chessBoard->isEmpty(middleRow,column)) return true;
	}
	// otherwise is an illegal movement
	return false;
}

std::string Pawn::toString() const {
	return ChessPiece::toString().replace(0,1,"P");
}

bool Pawn::isOnStartingRank() const {
	return startingRankByColor[(int)this->getColor()]==this->row;
}

