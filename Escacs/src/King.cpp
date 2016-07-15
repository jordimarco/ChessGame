/*
 * King.cpp
 *
 *  Created on: 28 gen. 2016
 *      Author: Jordi Marco
 */

#include<cstdlib>
#include "King.h"
#include "ChessBoard.h"

King::King(Color color) : ChessPiece(color) {
	// TODO Auto-generated constructor stub
}

King::~King() {
	// TODO Auto-generated destructor stub
}

bool King::isInCheck() const {
	for(int r=0; r<ChessBoard::CHESS_BOARD_SIZE; r++) {
		for(int c=0; c<ChessBoard::CHESS_BOARD_SIZE; c++) {
			ChessPiece* chessPiece = this->chessBoard->get(r,c);
			if(chessPiece!=nullptr && chessPiece->getColor()!=this->getColor() && chessPiece->canMoveTo(row,column)) {
				return true;
			}
		}
	}
	return false;
}

bool King::canMoveTo(int row, int column) const {
	int dr = abs(this->row-row);
	int dc = abs(this->column-column);
	if(dr>1 || dc>1 || !ChessPiece::canMoveTo(row,column)) return false;
	return this->tryToMove(row,column);
}

bool King::tryToMove(int row, int column) const {
	ChessPiece* chessPiece = this->chessBoard->get(row,column);
	ChessPiece* king = this->chessBoard->get(this->row,this->column);
	int currentRow = this->row;
	int currentColumn = this->column;
	king->putOnChessBoard(this->chessBoard,row,column);
	bool ok = !this->isInCheck();
	king->putOnChessBoard(this->chessBoard,currentRow,currentColumn);
	if(chessPiece!=nullptr)
		chessPiece->putOnChessBoard(this->chessBoard,row,column);
	return ok;
}

std::string King::toString() const {
	return ChessPiece::toString().replace(0,1,"K");
}

// Manca comprovar si es pot possar un altre peça al mig que eviti l'escac
bool King::isAlive() const {
	if(!isInCheck()) return true;
	for(int r=row-1; r<=row+1; r++) {
		for(int c=column-1; c<column+1; c++) {
			if(canMoveTo(r,c)) return true;
		}
	}
	return false;
}
