/*
 * Pawn.h
 *
 *  Created on: 28 gen. 2016
 *      Author: Jordi
 */

#ifndef PAWN_H_
#define PAWN_H_

#include "ChessPiece.h"

class Pawn : public ChessPiece {
public:
	Pawn(Color color);
	virtual ~Pawn();
	virtual bool canMoveTo(int row, int column) const;
	virtual std::string toString() const;
private:
	bool isOnStartingRank() const;
};

#endif /* PAWN_H_ */
