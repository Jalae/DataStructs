/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Cells.cpp
*Date Created:	2012/05/10
*Modifed:		2012/05/11
******************************************************************************/
#include "cells.h"
#include "cons.h"

cells::cells(cells const & rhs)
{}

cells cells::operator=(cells const & rhs)
{return *this;}

cells::cells()
{
	freecells.setLength(NUM_CELLS);
	for(int i(0);i < NUM_CELLS; i++)
	{
		freecells[i] = nullptr;
	}
	Blank = new Card(Card::Suit::BLANK_s,Card::Rank::BLANK_r);
}

cells::~cells()
{
	for(int i(0);i < NUM_CELLS; i++)
	{
		freecells[i] = nullptr;
	}
	delete Blank;
}

void cells::Draw(COORD pos)
{
	for(size_t i(0); i < NUM_CELLS; i++)
	{
		writeAt(point(pos.X+2+(7*i),pos.Y), i+1);
		if(freecells[i])
			freecells[i]->Draw(point(pos.X+(7*i),pos.Y+1));
		else
			Blank->Draw(point(pos.X+(7*i),pos.Y+1));
	}
}

int cells::GetCellsFilled()
{
	int i(0);
	for(int j(0);j<NUM_CELLS;j++)
		if (freecells[j])
			i++;
	return i;
}

bool cells::MoveIn(Card * c)
{
	int num(GetCellsFilled());
	if( num == 4)
		return false;
	else
	{
		for(int i(0); i < NUM_CELLS; i++)
			if(!freecells[i])
			{ //fill the first vacancy
				freecells[i] = c;
				break;
			}
		return true;
	}
}

Card * cells::MoveOut(size_t i)
{
	Card * temp = freecells[i];
	freecells[i] = nullptr;
	return temp;
}