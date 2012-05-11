/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Deck.h
*Date Created:	2012/05/10
*Modifed:		2012/05/11
******************************************************************************/
#include "Card.h"
#include "../ArrayClass/Array.h"

#include <cstdlib>//<needed for Random
#include <ctime>//<also needed for Random
#include <iostream>

class Deck
{
protected:
	Array<Card *> mahcards;/**<53? yes. 53*/
	size_t iterator;/**< internal variable for knowing what card i am at.*/

	class Random 
	{
		public:
		Random()
		{srand(static_cast<unsigned>(time(0)));}
		unsigned GetRand(int i) const 
		{return (rand()%i);}
		void Reseed() const
		{srand(static_cast<unsigned>(time(0)));}
	} r;
public:

	Deck();
	~Deck();
	void Shuffle();
	Card * Deal();
	void Draw(COORD pos)
	{
		mahcards[52]->Draw(pos);
	}
};

