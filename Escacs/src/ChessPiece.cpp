/*
 * ChessPiece.cpp
 *
 *  Created on: 25 gen. 2016
 *      Author: Jordi Marco
 */

#include "ChessPiece.h"
#include "ChessBoard.h"

static const std::string colorStrings[] = {" W", " B"};

ChessPiece::ChessPiece(Color color): chessBoard(nullptr), row(-1), column(-1), color(color) {
}

ChessPiece::~ChessPiece() {

}

void ChessPiece::putOnChessBoard(ChessBoard* chessBoard, int row, int column) {
	if(ChessBoard::isOnChessBoard(row, column)) {
		if(this->chessBoard!=nullptr) this->chessBoard->empty(this->row,this->column);
		this->chessBoard = chessBoard;
		this->row = row;
		this->column = column;
		this->chessBoard->put(this, row, column);
	}
}

void ChessPiece::removeFromChessBoard() {
	if(chessBoard!=nullptr) chessBoard->empty(this->row,this->column);
	this->chessBoard = nullptr;
	this->row = -1;
	this->column = -1;
}

bool ChessPiece::moveTo(int row, int column) {
	if(!this->canMoveTo(row, column)) return false;
	this->chessBoard->empty(this->row,this->column);
	this->chessBoard->put(this, row, column);
	return true;
}

bool ChessPiece::canMoveTo(int row, int column) const {
	if(!ChessBoard::isOnChessBoard(row, column)) return false;
	if(this->chessBoard==nullptr) return false;
	return (this->chessBoard->isEmpty(row, column) || this->getColor()!=this->chessBoard->get(row,column)->getColor());
}


const ChessPiece::Color& ChessPiece::getColor() const {
	return this->color;
}

std::string ChessPiece::toString() const {
	return colorStrings[(int)this->getColor()];
}

