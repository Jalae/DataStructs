/******************************************************************************
*Author:		Kehnin Dyer
*File name:		FreeCell_Class.h
*Date Created:	2012/05/10
*Modifed:		2012/05/11
******************************************************************************/
#pragma once

#include "Deck.h"
#include "Cells.h"
#include "Cascades.h"
#include "Foundations.h"

class FreeCell
{
Deck FC_Deck;
cells freecells;
Foundations Homerow;
Cascades PlayField;

public:
	FreeCell(){}

	void Play();
	void ProcessCommand();
	void StackMove(int num, char src, char des);
	void CardMove(char src, char des);
	void Draw(COORD pos);
	void Setup();
};
