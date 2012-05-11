/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Card.cpp
*Date Created:	2011/03/17
*Modifed:		2012/05/9
******************************************************************************/
#include "Card.h"
#include <iostream>
#include <Windows.h>
size_t Card::m_count(0);
char const * Card::VertCardBlank[] = 
{"\xC9\xCD\xCD\xCD\xBB","\xBA   \xBA","\xBA   \xBA","\xBA   \xBA",
										"\xc8\xCD\xCD\xCD\xBC",0};

wchar_t const * Card::m_suitname[]={L"clubs", L"diamonds", L"hearts", L"spades",
									L" "};

wchar_t const * Card::m_rankname[]={ L"ace", L"two", L"three", L"four", L"five",
	L"six",L"seven", L"eight", L"nine", L"ten", L"jack", L"queen", L"king",L" "};

wchar_t const * Card::m_shortsuit[]={L"\x05", L"\x04",L"\x03",L"\x06" , L" "};

wchar_t const * Card::m_shortrank[]={L"A",L"2",L"3",L"4",L"5",L"6",L"7",L"8",
										L"9",L"T",L"J",L"Q",L"K",L" "};

void Card::Draw(COORD pos)
{
	COORD temp;
	WORD color;
	HANDLE stout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i(0);
	{
		CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo = { 0 };
		
		GetConsoleScreenBufferInfo(stout, &ScreenBufferInfo );
		temp.X = ScreenBufferInfo.dwCursorPosition.X;
		temp.Y = ScreenBufferInfo.dwCursorPosition.Y;
		color = ScreenBufferInfo.wAttributes;
	}
	SetConsoleCursorPosition(stout, pos);
	

	SetConsoleTextAttribute(stout,BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_BLUE|
		( ((m_suit==Card::diamonds)||(m_suit==Card::hearts)) ? (FOREGROUND_INTENSITY|FOREGROUND_RED):(0) )
		);

	while (VertCardBlank[i] != nullptr)
	{
	//	std::wcout << L"{here}"; 
		std::wcout << VertCardBlank[i++];
		SetConsoleCursorPosition(stout, point(pos.X,pos.Y+i));
	}

	SetConsoleCursorPosition(stout, point(pos.X+1, pos.Y+1));
	std::wcout << m_shortrank[m_rank] << L" " << m_shortsuit[m_suit];
	SetConsoleCursorPosition(stout, point(pos.X+1, pos.Y+3));
	std::wcout << m_shortsuit[m_suit] << L" " << m_shortrank[m_rank];

	SetConsoleCursorPosition(stout, temp);
	SetConsoleTextAttribute(stout, color);
}

Card::Card(Suit s, Rank r):m_suit(s),m_rank(r)
{
	m_count++;
}

void Card::DisplayCard() const
{
	wchar_t buff[18] = {0};
	wcscat(buff, m_rankname[m_rank]);
	wcscat(buff, L" of ");
	wcscat(buff, m_suitname[m_suit]);
	//i have to build the string this way, or the cout.width wont work.
	//which makes it display all cards equal width.
	std::wcout.width(17);
	std::wcout.setf(std::ios::left);
	std::wcout  << buff;
}

///returns the Rank of the Card
Card::Rank Card::GetRank() const
{
	return m_rank;
}

///returns the Suit of the Card
Card::Suit Card::GetSuit() const
{
	return m_suit;
}

void swap(Card * & l, Card * & r)
{
	Card * t = l;
	l = r;
	r = t;
}
