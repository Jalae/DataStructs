/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Alchemy.cpp
*Date Created:	2012/04/12
*Modifed:		
******************************************************************************/

#include "Alchemy.h"
#include <iostream>

#include <random>

Alchemy::Alchemy(unsigned int SEED):board(8,9), health(MAX_HEALTH), difficulty(STARTING_DIFFICULTY)
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

void Alchemy::DrawStatus(Cell & temp)
{
	std::cout<<"\n\t\tYour Health is now: " << health
		<<"\n\t\tThe shape is :";
	temp.Draw();
	std::cout << "\nTo Discard the shape Enter 'XX'. \nTo Exit at anytime type 'Exit'\n To place a piece type the coordinate(ie 'A3')\n>"; 
}

bool Alchemy::BoardFilled()
{
	bool filled = true;
	for(int i(0); i < board.getColumn() && filled; i++)
		for(int j(0); j < board.getRow() && filled; j++)
			filled = board[i][j].Touched();
	return filled;
}

bool Alchemy::GetInput(size_t & r, size_t & c)
{
	char in[5];
	std::cin >> in;
	std::cin.ignore();
	//check my error
	if(k_strcmp(in, "Exit"))
		return true;
	if(((in[0]|0x60)=='x') && ((in[0]|0x60)=='x'))
	{
		c = r = 99;
		return false;
	}
	c = (in[0]|0x60) - 'a';
	r = in[1] - '1';
	return false;

}

bool Alchemy::Place(int r, int c, Cell & t)
{
	if(r==99 || c==99)
	{
		health --;
		return true;
	}
	if(r<0 || r >= board.getRow())
		return false;
	if(c<0 || c >= board.getColumn())
		return false;

	if(Placeable(r, c, t))
	{
		board[r][c] = t;
		board[r][c].Touch();
		health = (health<MAX_HEALTH)?health+1:MAX_HEALTH;
		CheckClear(r,c);
		return true;
	}
	return false;
}
void Alchemy::CheckClear(int r, int c)
{
	bool cleared = true;

	for(int i(0); i < board.getColumn() && cleared;i++)
	{
		cleared = board[r][i].Touched();
	}
	if (cleared)
	{
		health = MAX_HEALTH;
		for(int i(0); i < board.getColumn() && cleared;i++)
		{
			board[r][i].SetShape(0,0);
		}
	}
	cleared = true;
	
	for(int i(0); i < board.getRow() && cleared;i++)
	{
		cleared = board[i][c].Touched();
	}
	if (cleared)
	{
		health = MAX_HEALTH;
		for(int i(0); i < board.getRow() && cleared;i++)
		{
			board[i][c].SetShape(0,0);
		}
	}

}

bool Alchemy::Placeable(int r, int c, Cell & t)
{
	int touched(0);
	//check left, if left exists
	if(c>0)
	{
		if(!board[r][c-1].Neighborable(t))
			return false;
		else
			touched += board[r][c-1].Touched();
	}
	//check up, if exists
	if(r>0)
	{
		if(!board[r-1][c].Neighborable(t))
			return false;
		else
			touched += board[r-1][c].Touched();
	}
	//check right, if right exists
	if(c<(board.getColumn()-1))
	{
		if(!board[r][c+1].Neighborable(t))
			return false;
		else
			touched += board[r][c+1].Touched();
	}
	//check down, if exists
	if(r<(board.getRow()-1))
	{
		if(!board[r+1][c].Neighborable(t))
			return false;
		else
			touched += board[r][c+1].Touched();
	}
	//we have to touch /something/
	if(!touched)
		return false;

	//we have passed the gauntlet
	return true;
}

void Alchemy::start()
{
	size_t r, c;
	while(1)
	{
		//place a wild somewhere on the board to start things
		board[rand()%board.getRow()][rand()%board.getColumn()].Touch().SetShape(1,1);
		do
		{
			Cell temp(NewShape(difficulty), NewColor(difficulty) );
			temp.Touch();//just so the color skew isn't too bad
			do
			{
				system("cls");
				DrawBoard();
				DrawStatus(temp);
				
				if (GetInput(r, c))
					return;
			}while(!Place(r, c, temp));
		}while(!BoardFilled() && health>0);
		difficulty++;
	}


}

