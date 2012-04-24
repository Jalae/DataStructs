/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Alchemy.h
*Date Created:	2012/04/12
*Modifed:		
******************************************************************************/
#include "../Array2D/Array2D.h"
#include "../Utils/k_string.h"
#include "Cell.h"
#include <time.h>

const size_t MAX_HEALTH(3);
const size_t STARTING_DIFFICULTY(5);

class Alchemy
{
	Array2D<Cell> board;
	size_t health;
	size_t difficulty;
	
	void DrawBoard();
	size_t NewColor(size_t MAX);
	size_t NewShape(size_t MAX);
	void DrawStatus(Cell & temp);
	bool BoardFilled();
	bool GetInput(size_t & r, size_t & c);
	bool Place(int r, int c, Cell & t);
	bool Placeable(int r, int c, Cell & t);
	void CheckClear(int r, int c);

public:
	//we can specify a specific seed or default to random
	Alchemy(unsigned int SEED = time(NULL));
	void start();
};
