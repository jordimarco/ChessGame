/*
 * ChessPiece.h
 *
 *  Created on: 25 gen. 2016
 *      Author: Jordi Marco
 */

#ifndef CHESSPIECE_H_
#define CHESSPIECE_H_

#include<string>

class ChessBoard;

class ChessPiece {
public:
	enum class Color{WHITE=0,BLACK=1};
protected:
	Color color;
	ChessBoard* chessBoard;
	int row, column;

public:
	ChessPiece(Color color);
	virtual ~ChessPiece();
	void putOnChessBoard(ChessBoard* chessBoard, int row, int column);
	void removeFromChessBoard();
	bool moveTo(int row, int column);
	virtual bool canMoveTo(int row, int column) const;
	const Color& getColor() const;
	virtual std::string toString() const;
};

#endif /* CHESSPIECE_H_ */
