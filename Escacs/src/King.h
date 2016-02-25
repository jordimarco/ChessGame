/*
 * King.h
 *
 *  Created on: 28 gen. 2016
 *      Author: Jordi
 */

#ifndef KING_H_
#define KING_H_

#include "ChessPiece.h"

class King : public ChessPiece {
public:
	King(Color color);
	virtual ~King();
	virtual bool canMoveTo(int row, int column) const;
	virtual std::string toString() const;
};

#endif /* KING_H_ */
