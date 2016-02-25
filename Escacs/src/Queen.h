/*
 * Queen.h
 *
 *  Created on: 2 febr. 2016
 *      Author: Jordi Marco
 */

#ifndef QUEEN_H_
#define QUEEN_H_

#include "ChessPiece.h"

class Queen: public ChessPiece {
public:
	Queen(Color color);
	virtual ~Queen();
	virtual bool canMoveTo(int row, int column) const;
	virtual std::string toString() const;
};

#endif /* QUEEN_H_ */
