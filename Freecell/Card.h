/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Card.h
*Date Created:	2012/05/03
*Modifed:		2012/05/10
******************************************************************************/
#pragma once
#include <Windows.h>

class Card
{
public:
	///@enum card::Suit is used for arbitration of suit information 
	static enum Suit{clubs, diamonds, hearts, spades, BLANK_s};
	///@see card::Suit
	static enum Rank{ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, BLANK_r};
	Card(Suit const s, Rank const r);
	void DisplayCard() const;
	Rank GetRank() const;
	Suit GetSuit() const;
	void Draw(COORD pos);

protected:
	Suit const m_suit;  ///<the suit of the card
	Rank const  m_rank; ///<the rank of the card

	static size_t m_count; ///<cards made
	static char const * VertCardBlank[];///<what a blank verticle card looks like
	static wchar_t const * m_suitname[];///<array containing all the names of all the suits
	static wchar_t const * m_rankname[];///<array containing all the names of all the ranks
	static wchar_t const * m_shortsuit[];///<array containing the single char suit symbol
	static wchar_t const * m_shortrank[];///<array containing the single char ranks
};

//maybe move this somewhere else?
class point
{
private:
	COORD pos;
public:
	point(COORD const i)
	{
		pos = i;
	}
	point(int x, int y)
	{
		pos.X = x;
		pos.Y = y;
	}
	operator COORD ()
	{
		return pos;
	}
};

void swap(Card * & l, Card * & r);

inline Card::Suit operator++(Card::Suit & rs, int )
{
	Card::Suit oldSuit = rs;
	rs = (Card::Suit)(rs + 1);
	return oldSuit;
}
inline Card::Rank operator++(Card::Rank & rs, int )
{
	Card::Rank oldRank = rs;
	rs = (Card::Rank)(rs + 1);
	return oldRank;
}
inline Card::Suit operator++(Card::Suit & rs)
{
	return rs = (Card::Suit)(rs + 1);
}
inline Card::Rank operator++(Card::Rank & rs)
{
	return rs = (Card::Rank)(rs + 1);
}
inline Card::Suit operator--(Card::Suit & rs, int )
{
	Card::Suit oldSuit = rs;
	rs = (Card::Suit)(rs - 1);
	return oldSuit;
}
inline Card::Rank operator--(Card::Rank & rs, int )
{
	Card::Rank oldRank = rs;
	rs = (Card::Rank)(rs - 1);
	return oldRank;
}
inline Card::Suit operator--(Card::Suit & rs)
{
	return rs = (Card::Suit)(rs - 1);
}
inline Card::Rank operator--(Card::Rank & rs)
{
	return rs = (Card::Rank)(rs - 1);
}