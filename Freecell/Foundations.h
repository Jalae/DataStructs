/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Foundations.h
*Date Created:	2012/05/10
*Modifed:		2012/05/11
******************************************************************************/
#pragma once

#include "../Stack_list/Stack_list.h"
#include "Card.h"

int const NUM_FOUNDATIONS(4);
class Foundations
{
	Stack_list<Card *> foundation[NUM_FOUNDATIONS];
	Card * Blank;
public:
	Foundations();
	~Foundations();

	void AddCard(Card* c);
	bool CheckPlacement(Card* c);
	bool FoundationsFull();
	void Draw(COORD pos);
};
