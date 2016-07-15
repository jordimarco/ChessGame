/*
 * ChessGame.cpp
 *
 *  Created on: 15 juny 2016
 *      Author: Jordi Marco
 */

#include "ChessGame.h"
#include <iostream>

ChessGame::ChessGame():board(),player(ChessPiece::Color::WHITE),checkmate(false) {
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

void ChessGame::updateCheckmate() {
	King* king = player==ChessPiece::Color::WHITE?blackKing:whiteKing;
	checkmate = !king->isAlive();
}

ChessPiece::Color ChessGame::currentPlayer() const {
	return player;
}

bool ChessGame::move(int ro,int co,int rd,int cd) {
	if(isCheckmate()) return false;
	ChessPiece* p = board.get(ro,co);
	if(p==nullptr) return false;
	if(p->getColor()!=player) return false;
	King* kingPlayer = player==ChessPiece::Color::WHITE?whiteKing:blackKing;
	if(kingPlayer->isInCheck() && p!=kingPlayer) return false;
	bool ok = p->moveTo(rd,cd);
	if(!ok) return false;
	updateCheckmate();
	if(!isCheckmate()) {
		player = (ChessPiece::Color)(((int)player+1)%2);
	}
	return true;
}

bool ChessGame::isCheckmate() const {
	return checkmate;
}

std::ostream& operator<< (std::ostream &out, const ChessGame &chessGame) {
	return std::cout << chessGame.board.toString();
}
