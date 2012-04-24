/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Cell.h
*Date Created:	2012/04/12
*Modifed:		2012/04/23
******************************************************************************/
#pragma once

#include <iostream>
#include <windows.h>

/******************************************************************************
*Class:		Alchemy
*
*Purpose:	Holds manages and runs all the features of the Alchemy game.
			No reason exists to use anything other than the given 2 functions.
*
*Functions:
	Cell(size_t shape = 0, size_t color = 0)
		default Cell constructor. shape and color may be specified,
		otherwise an empty cell will be created
	Cell(Cell & c);
		Deep copys the contents of c into this
	~Cell()
		lets everything go out of scope.
	Cell & operator=(Cell & c)
		Deep copies the values from c into this
	Cell & Touch()
		Sets the touch flag in the cell.
	bool Touched() const
		returns the touch flag in the cell
	void Reset()
		resets the cell to a squeaky clean status
	void SetShape(size_t shape, size_t color);
		sets the new shape and color of the cell
	void Draw() const
		handles all the logic and windows calls neccicary to display the cells
		to the screen. resets everything back to the way it found it.
	bool Neighborable(Cell const & C)
		figures out if this and C can be next to eachother according to the logic
		of Alchemy.
******************************************************************************/
class Cell
{
	bool m_touched;
	size_t m_shape;
	size_t m_color;
public:
	Cell(size_t shape = 0, size_t color = 0);
	Cell(Cell & c);
	~Cell();
	Cell & operator=(Cell & c);

	Cell & Touch();
	bool Touched() const;
	//puts cell back in the starting state
	void Reset();
	void SetShape(size_t shape, size_t color);
	void Draw() const;
	bool Neighborable(Cell const & C);
};
