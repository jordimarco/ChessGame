/*
 * Rook.h
 *
 *  Created on: 2 febr. 2016
 *      Author: Jordi Marco
 */

#ifndef ROOK_H_
#define ROOK_H_

#include "ChessPiece.h"

class Rook: public ChessPiece {
public:
	Rook(Color color);
	virtual ~Rook();
	virtual bool canMoveTo(int row, int column) const;
	virtual std::string toString() const;
private:
	bool isOnStartingRank() const;
};

#endif /* ROOK_H_ */
