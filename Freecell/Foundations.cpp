/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Foundations.cpp
*Date Created:	2012/05/10
*Modifed:		2012/05/11
******************************************************************************/
#include "cons.h"
#include "Foundations.h"

Foundations::Foundations()
{
	Blank = new Card(Card::Suit::BLANK_s, Card::Rank::BLANK_r);
}
Foundations::~Foundations()
{
	for(int i(0); i < NUM_FOUNDATIONS; i++)
		while(!foundation[i].isEmpty())
			foundation[i].Pop();
	delete Blank;
	Blank = nullptr;
}

void Foundations::AddCard(Card* c) 
{//figures out which foundation to put it in, based on suit
	foundation[c->GetSuit()].Push(c);
}

bool Foundations::CheckPlacement(Card* c)
{
	//first check for the empty case
	if(foundation[c->GetSuit()].isEmpty() && (c->GetRank() == Card::Rank::ace))
		return true;
	//there is a card there, so now check if the rank is one less than ours
	if(foundation[c->GetSuit()].Peek()->GetRank()+1 == c->GetRank())
		return true;
	//neither is the case.
	return false;
}

bool Foundations::FoundationsFull()
{
	bool test = true;
	for(int i(0);test && i <  NUM_FOUNDATIONS; i++)
	{
		if(!foundation[i].isEmpty())
			test = foundation[i].Peek()->GetRank() == Card::Rank::king;
		else
			test = false;
	}
	return test;
}

void Foundations::Draw(COORD pos)
{
	for(size_t i(0); i < NUM_FOUNDATIONS; i++)
	{
		writeAt(point(pos.X+2+(7*i),pos.Y), i+6);
		if(!foundation[i].isEmpty())
			foundation[i].Peek()->Draw(point(pos.X+(7*i),pos.Y+1));
		else
			Blank->Draw(point(pos.X+(7*i),pos.Y+1));
	}
}