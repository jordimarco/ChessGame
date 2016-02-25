/*
 * ChessBoard.h
 *
 *  Created on: 25 gen. 2016
 *      Author: Jordi Marco
 */

#ifndef CHESSBOARD_H_
#define CHESSBOARD_H_

#include<string>

class ChessPiece;

class ChessBoard {
public:
	static const int CHESS_BOARD_SIZE = 8;
private:
	ChessPiece* chessBoard[CHESS_BOARD_SIZE][CHESS_BOARD_SIZE];
public:
	ChessBoard();
	virtual ~ChessBoard();
	static bool isOnChessBoard(int row, int column);
	bool put(ChessPiece* chessPiece, int row, int column);
	ChessPiece* get(int row, int column) const;
	void empty(int row, int column);
	bool isEmpty(int row, int column) const;
	std::string toString() const;
};

#endif /* CHESSBOARD_H_ */
