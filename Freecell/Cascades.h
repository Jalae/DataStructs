/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Cascades.h
*Date Created:	2012/05/10
*Modifed:		2012/05/11 
******************************************************************************/
#pragma once

#include "../Stack_list/Stack_list.h"
#include "Card.h"
#include "cons.h"
int const NUM_CASCADES(8);

class Cascades
{
private:
	Stack_list<Card *> Cascade [NUM_CASCADES];

public:
	Cascades()
	{}
	~Cascades()
	{}

	void AddCard(int stack, Card * c);
	bool CheckPlacement(int stack, Card * c);
	void AddStack(int stack, Stack_list<Card *> c);
	Card * MoveCard(int stack);
	bool MoveStack(int stack, int number, Stack_list<Card *> & c);
	void Draw(COORD pos);
	int NumCascadesEmpty();
	
};
