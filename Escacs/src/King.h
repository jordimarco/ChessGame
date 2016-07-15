/*
 * King.h
 *
 *  Created on: 28 gen. 2016
 *      Author: Jordi Marco
 */

#ifndef KING_H_
#define KING_H_

#include "ChessPiece.h"

class King : public ChessPiece {
	bool tryToMove(int row, int column) const;
public:
	King(Color color);
	virtual ~King();
	virtual bool canMoveTo(int row, int column) const;
	virtual std::string toString() const;
	bool isAlive() const;
	bool isInCheck() const;
};

#endif /* KING_H_ */
