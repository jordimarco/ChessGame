/*
 * Bishop.h
 *
 *  Created on: 2 febr. 2016
 *      Author: Jordi Marco
 */

#ifndef BISHOP_H_
#define BISHOP_H_

#include "ChessPiece.h"

class Bishop: public ChessPiece {
public:
	Bishop(Color color);
	virtual ~Bishop();
	virtual bool canMoveTo(int row, int column) const;
	virtual std::string toString() const;
};

#endif /* BISHOP_H_ */
