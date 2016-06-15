/*
 * ChessGame.cpp
 *
 *  Created on: 15 juny 2016
 *      Author: Jordi
 */

#include "ChessGame.h"
#include <iostream>

ChessGame::ChessGame():board(),player(ChessPiece::Color::WHITE) {
	for(int c=0; c<ChessBoard::CHESS_BOARD_SIZE;c++) {
		whitePieces[c]->putOnChessBoard(&board, 0, c);
		whitePawns[c].putOnChessBoard(&board, 1, c);
		blackPieces[c]->putOnChessBoard(&board, 7, c);
		blackPawns[c].putOnChessBoard(&board, 6, c);
	}
}

ChessGame::~ChessGame() {
	for(int c=0; c<ChessBoard::CHESS_BOARD_SIZE;c++) {
		delete whitePieces[c];
		delete blackPieces[c];
	}
}

bool ChessGame::move(int ro,int co,int rd,int cd) {
	ChessPiece* p = board.get(ro,co);
	if(p==nullptr) return false;
	if(p->getColor()!=player) return false;
	bool ok = p->moveTo(rd,cd);
	if(!ok) return false;
	player = (ChessPiece::Color)(((int)player+1)%2);
	return true;
}

bool ChessGame::isFinished() const {
	return false;
}

void ChessGame::play() const {
	std::cout << board.toString();
}
