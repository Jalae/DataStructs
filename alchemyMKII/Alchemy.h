/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Alchemy.h
*Date Created:	2012/04/12
*Modifed:		2012/04/12
******************************************************************************/
#include "../Array2D/Array2D.h"
#include "../Utils/k_string.h"
#include "Cell.h"
#include <time.h>

const size_t MAX_HEALTH(3);
const size_t STARTING_DIFFICULTY(5);
const int MAX_DIFFICULTY(15);


/******************************************************************************
*Class:		Alchemy
*
*Purpose:	Holds manages and runs all the features of the Alchemy game.
			No reason exists to use anything other than the given 2 functions.
*
*Functions:
	Alchemy(unsigned int SEED = time(NULL))
		Sets up the game. A specific SEED may be given to play a specific game,
		otherwise a random one will be used.
	~Alchemy()
		The default constructor... doesn't need to do anything but let members
		go out of scope.
	void start()
		starts the game. Returns when the user quits.
******************************************************************************/
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
	//no touchy...
	Alchemy & operator=(Alchemy & a);
	Alchemy(Alchemy const &);
	
public:
	//we can specify a specific seed or default to random
	Alchemy(unsigned int SEED = time(NULL));
	Alchemy::~Alchemy();
	void start();
};
