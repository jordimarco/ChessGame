/*
 * ChessBoard.cpp
 *
 *  Created on: 25 gen. 2016
 *      Author: Jordi Marco
 */

#include "ChessBoard.h"
#include "ChessPiece.h"

ChessBoard::ChessBoard() {
	for(int row=0; row<CHESS_BOARD_SIZE; row++) {
		for(int column=0; column<CHESS_BOARD_SIZE; column++) {
			this->chessBoard[row][column] = nullptr;
		}
	}
}

ChessBoard::~ChessBoard() {
	// TODO Auto-generated destructor stub
}

bool ChessBoard::isOnChessBoard(int row, int column) {
	return row>=0 && row<CHESS_BOARD_SIZE && column>=0 && column<CHESS_BOARD_SIZE;
}

bool ChessBoard::put(ChessPiece* chessPiece, int row, int column) {
	if(!isOnChessBoard(row,column))
		return false;
	if(!isEmpty(row, column)) {
		this->get(row, column)->removeFromChessBoard();
	}
	this->chessBoard[row][column] = chessPiece;
	return true;
}

ChessPiece* ChessBoard::get(int row, int column) const {
	if(isOnChessBoard(row,column))
		return this->chessBoard[row][column];
	return nullptr;
}

void ChessBoard::empty(int row, int column) {
	if(isOnChessBoard(row,column))
		this->chessBoard[row][column]=nullptr;
}

bool ChessBoard::isEmpty(int row, int column) const {
	if(!isOnChessBoard(row,column))
		return true;
	return this->chessBoard[row][column]==nullptr;
}

std::string ChessBoard::toString() const {
	std::string s = "-------------------------\n|";
	for(int row=CHESS_BOARD_SIZE-1; row>=0; row--) {
		for(int column=0; column < CHESS_BOARD_SIZE; column++) {
			s += this->chessBoard[row][column]==nullptr?"  ": this->chessBoard[row][column]->toString();
			s += "|";
		}
		s += "\n";
		s += "-------------------------\n|";
	}
	return s.substr(0,s.size()-1);
}


