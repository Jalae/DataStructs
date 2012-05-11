/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Deck.cpp
*Date Created:	2011/3/15
*Modifed:		2012/05/8
******************************************************************************/
#include <iostream>
#include "Deck.h"

Deck::Deck():iterator(0)
{
	mahcards.setLength(53);
	size_t index(0);
	for(Card::Suit i(Card::clubs); i <= Card::spades ; i++)
	{
		for(Card::Rank j(Card::ace); j <= Card::king; j++)
		{
			mahcards[index] = new Card(i,j);
			index++;
		}
	}
	mahcards[52]=new Card(Card::Suit::BLANK_s, Card::BLANK_r);
}

Deck::~Deck()
{
	for(int i(0); i < mahcards.getLength() ; i++)
	{
		delete mahcards[i];
		mahcards[i] = nullptr;
	}
	iterator = 0;
}

void Deck::Shuffle()
{
	iterator = 0;
	size_t size(52);

	for(size_t i(0); i < size ; i++)
	{
		swap(mahcards[i], mahcards[r.GetRand(size)]);
	}
}

Card * Deck::Deal()
{
	if(mahcards[iterator]->GetRank() != Card::Rank::BLANK_r)
	{
		return mahcards[iterator++];
	}//we will not inc iterator if it is a nullptr (so we stay at null)
	return mahcards[iterator];
}
