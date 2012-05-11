/******************************************************************************
*Author:		Kehnin Dyer
*File name:		cells.h
*Date Created:	2012/05/10
*Modifed:		2012/05/011
******************************************************************************/
#pragma once
#include "../ArrayClass/Array.h"
#include "Card.h"

int const NUM_CELLS(4);
class cells
{
private:
	Array<Card *> freecells;
	Card * Blank;
	cells(cells const & rhs);
	cells operator=(cells const & rhs);
public:
	cells();
	~cells();

	void Draw(COORD pos);
	int GetCellsFilled();
	bool MoveIn(Card * c);
	Card * MoveOut(size_t i);

};
