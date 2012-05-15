/******************************************************************************
*Author:		Kehnin Dyer
*File name:		FreeCell_Class.h
*Date Created:	2012/05/10
*Modifed:		2012/05/11
******************************************************************************/

#include "FreeCell_Class.h"
#include "cons.h"

void FreeCell::Play()
{
	Setup();
	while(!Homerow.FoundationsFull())
	//for(int i(0); i < 5; i++)
	{
		Draw(point(0,0));
		ProcessCommand();
	}
	system("cls");
	writeAt(point(24,10),"OMG! YOU WON! CONGRADULATIONS.");
}

void FreeCell::ProcessCommand()
{
	char in[4];//longest command is 3 values and null
	SetCursor(point(0,24));
	std::cout << ">         ";
	SetCursor(point(1,24));
	std::cin.getline(in,4);
	if(std::cin.fail())
	{//protection from bad input.
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	//we have ambiguous input if the first char is a number
	if(in[0]>='0' && in[0]<='9')
		if(in[2]!=0)//there is a 3rd char
		{
			StackMove(in[0]-48,in[1],in[2]);
			return;
		}
	CardMove(in[0],in[1]);
}

void FreeCell::StackMove(int num, char src, char des)
{
	int max = PlayField.NumCascadesEmpty();
	max = max * max;
	max = max + (NUM_CELLS - freecells.GetCellsFilled())+1;
	num = ((num<=max)?(num):(max));
	Stack_list<Card *> t;
	if(!(src>='a' && src<('a'+NUM_CASCADES)))
	{
		return;//if it isn't to 
	}
	if(!(des>='a' && des<('a'+NUM_CASCADES)))
	{	//and from a cascade it isn't valid.
		return;
	}
	src = src - 'a';
	des = des - 'a';
	if(!PlayField.MoveStack(src, num, t) || (!PlayField.CheckPlacement(des, t.Peek())))
	{//we failed to get any stack. or the move is invalid
		PlayField.AddStack(src, t); //put her back
		std::cout << "Invalid Move: Macro moves can only work if you could make the move otherwise.";
		std::cin.ignore();
		return;
	}
	PlayField.AddStack(des, t);
	return;
}

void FreeCell::CardMove(char src, char des)
{
	Card * temp;
	if(src>='a' && src<('a'+NUM_CASCADES))
	{//moving from a cascade
		src = src - 'a';
		temp = PlayField.MoveCard(src);
		if(des>='a' && des<('a'+NUM_CASCADES))
		{//to a cascade
			des = des - 'a';
			if(PlayField.CheckPlacement(des,temp))
			{
				PlayField.AddCard(des,temp);//if we can move there move it
				return;
			}
		}
		else if(des>='1' && (des<=('1'+NUM_CELLS)))
		{//to a cell
			if(freecells.MoveIn(temp))
				return;
		}
		else if(des<='9' && (des>=('9'-NUM_FOUNDATIONS)))
		{//to a foundation
			if(Homerow.CheckPlacement(temp))
			{
				Homerow.AddCard(temp);
				return;
			}
		}
		//either the des was invalid, or the move failed.
		PlayField.AddCard(src, temp);
	}
	else
	if(src>='1' && (src<=('1'+NUM_CELLS)))
	{//from a cell
		src = src - '1';
		temp = freecells.MoveOut(src);

		if(des>='a' && des<('a'+NUM_CASCADES))
		{//to a cascade
			des = des - 'a';
			if(PlayField.CheckPlacement(des,temp))
			{
				PlayField.AddCard(des,temp);//if we can move there move it
				return;
			}
		}
		else if(des>='1' && (des<=('1'+NUM_CELLS)))
		{//to a cell
			if(freecells.MoveIn(temp))
				return;
		}
		else if(des<='9' && (des>=('9'-NUM_FOUNDATIONS)))
		{//to a foundation
			if(Homerow.CheckPlacement(temp))
			{
				Homerow.AddCard(temp);
				return;
			}
		}
		freecells.MoveIn(temp);
	}//adding some helper tips on invalid inputs
	std::cout << "Invalid Move:";
	switch(rand()%6)//adding a comment to test new git config
	{
		case 0: std::cout << " You cannot Move from a Foundation.";
			break;
		case 1:  std::cout <<" You win by Collecting all cards in the Foundations.";
			break;
		case 2:	std::cout << " You can macro move by indicating the number of cards first (4ae)";
			break;
		case 3: std::cout << " Valid moves are from somewhere to elsewhere, ie. from a to 8 (a8)";
			break;
		case 4: std::cout << " When Moving to a Freecell all the numbers are treated the same.";
			break;
		case 5:	std::cout << " Cards can be stacked Alternating Colors in Decending order.";
		default:
			break;
	}

	std::cin.ignore();
	return;
}

void FreeCell::Draw(COORD pos)
{
	system("cls");
	freecells.Draw(point(pos.X+6, pos.Y+0));
	PlayField.Draw(point(pos.X+13, pos.Y+6));
	Homerow.Draw(point(pos.X+48, pos.Y+0));
}

void FreeCell::Setup()
{
	FC_Deck.Shuffle();
	Card * temp =FC_Deck.Deal();
	int i = 0;
	do
	{
		PlayField.AddCard(i, temp);
		i = (i+1)%NUM_CASCADES;
		temp = FC_Deck.Deal();
	}while(temp->GetRank() != Card::Rank::BLANK_r);
	//deal all cards into the PlayField
}