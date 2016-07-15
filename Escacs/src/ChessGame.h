/*
 * ChessGame.h
 *
 *  Created on: 15 juny 2016
 *      Author: Jordi Marco
 */

#ifndef CHESSGAME_H_
#define CHESSGAME_H_

#include "ChessBoard.h"
#include "ChessPiece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"

class ChessGame {
	ChessPiece::Color player;
	ChessBoard board;
	bool checkmate;

	King* whiteKing = new King(ChessPiece::Color::WHITE);
	King* blackKing = new King(ChessPiece::Color::BLACK);
	ChessPiece* whitePieces[8] = {
			new Rook(ChessPiece::Color::WHITE),
			new Knight(ChessPiece::Color::WHITE),
			new Bishop(ChessPiece::Color::WHITE),
			whiteKing,
			new Queen(ChessPiece::Color::WHITE),
			new Bishop(ChessPiece::Color::WHITE),
			new Knight(ChessPiece::Color::WHITE),
			new Rook(ChessPiece::Color::WHITE)
	};
	ChessPiece* blackPieces[8] = {
			new Rook(ChessPiece::Color::BLACK),
			new Knight(ChessPiece::Color::BLACK),
			new Bishop(ChessPiece::Color::BLACK),
			blackKing,
			new Queen(ChessPiece::Color::BLACK),
			new Bishop(ChessPiece::Color::BLACK),
			new Knight(ChessPiece::Color::BLACK),
			new Rook(ChessPiece::Color::BLACK)
	};
	Pawn whitePawns[8] = {
			Pawn(ChessPiece::Color::WHITE),
			Pawn(ChessPiece::Color::WHITE),
			Pawn(ChessPiece::Color::WHITE),
			Pawn(ChessPiece::Color::WHITE),
			Pawn(ChessPiece::Color::WHITE),
			Pawn(ChessPiece::Color::WHITE),
			Pawn(ChessPiece::Color::WHITE),
			Pawn(ChessPiece::Color::WHITE)
	};
	Pawn blackPawns[8] = {
			Pawn(ChessPiece::Color::BLACK),
			Pawn(ChessPiece::Color::BLACK),
			Pawn(ChessPiece::Color::BLACK),
			Pawn(ChessPiece::Color::BLACK),
			Pawn(ChessPiece::Color::BLACK),
			Pawn(ChessPiece::Color::BLACK),
			Pawn(ChessPiece::Color::BLACK),
			Pawn(ChessPiece::Color::BLACK)
	};

	void updateCheckmate();
public:
	ChessGame();
	ChessPiece::Color currentPlayer() const;
	bool move(int ro,int co,int rd,int cd);
	bool isCheckmate() const;
    friend std::ostream& operator<< (std::ostream &out, const ChessGame &chessGame);
	virtual ~ChessGame();
};

#endif /* CHESSGAME_H_ */
