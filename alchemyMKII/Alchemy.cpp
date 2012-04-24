/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Alchemy.cpp
*Date Created:	2012/04/12
*Modifed:		
******************************************************************************/

#include "Alchemy.h"
#include <iostream>

#include <random>

Alchemy::Alchemy(unsigned int SEED):board(8,9), health(MAX_HEALTH)
{
	srand(SEED);
}

void Alchemy::DrawBoard()
{
	char col = 'a';
	std::cout<<"\t\t\t ";
	//print out the letters for the amount of rows we have;
	for(size_t i(0); i < board.getColumn(); i++)
	{
		std::cout<< " "<< (char)(col+i);
	}
	std::cout << "\n";
	for(size_t i(0); i < board.getRow(); i++)
	{
		std::cout <<"\t\t\t"<< i+1;
		for(size_t j(0); j < board.getColumn(); j++)
		{
			std::cout << " ";
			board[i][j].Draw();
		}
		std::cout << "\n";
	}
}

size_t Alchemy::NewColor(size_t MAX)
{
	return 1 + (rand() % MAX);
}

size_t Alchemy::NewShape(size_t MAX)
{
	return 1 + (rand() % MAX);
}

void Alchemy::DrawStatus()
{
	std::cout<<"\n\t\tYour Health is now: " << health
		<< "To Discard the shape Enter 'XX'. \n To place a piece type the  " << SOMTHING ELSE; 
}

bool Alchemy::BoardFilled()
{
}

void Alchemy::start()
{

	
	do
	{
		DrawBoard();
		Cell temp(NewShape(difficulty), NewColor(difficulty) );
		DrawStatus();

	}while(!BoardFilled());


}

