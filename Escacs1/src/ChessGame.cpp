#include <iostream>
#include <string>
#include "ChessBoard.h"
#include "ChessPiece.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
using namespace std;

int main() {
	ChessBoard chessBoard;

	Rook rW1(ChessPiece::Color::WHITE);
	rW1.putOnChessBoard(&chessBoard, 0, 0);
	Rook rW2(ChessPiece::Color::WHITE);
	rW2.putOnChessBoard(&chessBoard, 0, 7);

	Rook rB1(ChessPiece::Color::BLACK);
	rB1.putOnChessBoard(&chessBoard, 7, 0);
	Rook rB2(ChessPiece::Color::BLACK);
	rB2.putOnChessBoard(&chessBoard, 7, 7);

	Knight nW1(ChessPiece::Color::WHITE);
	nW1.putOnChessBoard(&chessBoard, 0, 1);
	Knight nW2(ChessPiece::Color::WHITE);
	nW2.putOnChessBoard(&chessBoard, 0, 6);

	Knight nB1(ChessPiece::Color::BLACK);
	nB1.putOnChessBoard(&chessBoard, 7, 1);
	Knight nB2(ChessPiece::Color::BLACK);
	nB2.putOnChessBoard(&chessBoard, 7, 6);

	Bishop bW1(ChessPiece::Color::WHITE);
	bW1.putOnChessBoard(&chessBoard, 0, 2);
	Bishop bW2(ChessPiece::Color::WHITE);
	bW2.putOnChessBoard(&chessBoard, 0, 5);

	Bishop bB1(ChessPiece::Color::BLACK);
	bB1.putOnChessBoard(&chessBoard, 7, 2);
	Bishop bB2(ChessPiece::Color::BLACK);
	bB2.putOnChessBoard(&chessBoard, 7, 5);

	King kW(ChessPiece::Color::WHITE);
	kW.putOnChessBoard(&chessBoard, 0, 3);

	King kB(ChessPiece::Color::BLACK);
	kB.putOnChessBoard(&chessBoard, 7, 3);

	Queen qW(ChessPiece::Color::WHITE);
	qW.putOnChessBoard(&chessBoard, 0, 4);

	Queen qB(ChessPiece::Color::BLACK);
	qB.putOnChessBoard(&chessBoard, 7, 4);

	for(int c=0; c<ChessBoard::CHESS_BOARD_SIZE;c++) {
		Pawn pW(ChessPiece::Color::WHITE);
		Pawn pB(ChessPiece::Color::BLACK);
		pW.putOnChessBoard(&chessBoard, 1, c);
		pB.putOnChessBoard(&chessBoard, 6, c);
	}
	cout << "1" << endl << chessBoard.toString() << endl;
	cout << "2" << endl << chessBoard.toString() << endl;

	cout << "3" << endl << chessBoard.toString() << endl;
}
