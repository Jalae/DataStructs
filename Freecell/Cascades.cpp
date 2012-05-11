/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Cascades.cpp
*Date Created:	2012/05/10
*Modifed:		2012/05/11
******************************************************************************/
#include "Cascades.h"

void Cascades::AddCard(int stack, Card * c)
{
	Cascade[stack].Push(c);
}

bool Cascades::CheckPlacement(int stack, Card * c)
{
	if(!c)//bad person you.
		return false;

	//it's empty, anything goes.
	if(Cascade[stack].isEmpty())
		return true;
	Card * t = Cascade[stack].Peek();
	//check rank
	if(t->GetRank() != c->GetRank()+1)
		return false;
	//check suit
	switch(t->GetSuit())
	{
		case Card::Suit::clubs:
		case Card::Suit::spades:
			if(c->GetSuit()==Card::Suit::diamonds || c->GetSuit()==Card::Suit::hearts)
				return true;
			return false;
		case Card::Suit::diamonds:
		case Card::Suit::hearts:
			if(c->GetSuit()==Card::Suit::clubs || c->GetSuit()==Card::Suit::spades)
				return true;
		default:
			return false;
	}
}

void Cascades::AddStack(int stack, Stack_list<Card *> c)
{
	while(!c.isEmpty())
		Cascade[stack].Push(c.Pop());
}

Card * Cascades::MoveCard(int stack)
{
	return Cascade[stack].Pop();
}

bool Cascades::MoveStack(int stack, int number, Stack_list<Card *> & c)
{
	//sanity check
	if(!c.isEmpty())
		return false;
	//cant be moving more cards than there are, ya know?
	if (Cascade[stack].Size() < number)
		return false;
	for(int i(0); i < number; i++)
	{//makesure the indicated stack is a stack.
		Card * t = Cascade[stack].Pop();
		if(CheckPlacement(stack, t))
			c.Push(t);
		else
		{
			c.Push(t);
			break;
		}
	}
	return true;
}

void Cascades::Draw(COORD pos)
{
	for(int i(0); i < NUM_CASCADES; i++)
	{
		int k(0);
		writeAt(point(pos.X+7*i+2,pos.Y), (wchar_t)(L'A'+i));
		for(abs_LinkedList<Card *>::bkwIterator j(Cascade[i]) ; !j.End() ; j.Next(), k++)
		{
			j.current()->Draw(point(pos.X+7*i,pos.Y+2*k + 1));
		}
	}
}

int Cascades::NumCascadesEmpty()
{
	int i(0);
	for(int j(0); j < NUM_CASCADES; j++)
	{
		if(Cascade[j].isEmpty())
			i++;
	}
	return i;
}