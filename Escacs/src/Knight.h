/*
 * Knight.h
 *
 *  Created on: 28 gen. 2016
 *      Author: Jordi Marco
 */

#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "ChessPiece.h"

class Knight: public ChessPiece {
public:
	Knight(Color color);
	virtual ~Knight();
	virtual bool canMoveTo(int row, int column) const;
	virtual std::string toString() const;
};

#endif /* KNIGHT_H_ */
