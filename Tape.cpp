/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class hold the representation of the Turing machine tape
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>

#include "Direction.h"
#include "Tape.h"
#include "Crash.h"

using namespace std;

Tape::Tape():
	  cells(" "), current_cell(0), blank_character(' ')
{

}

Tape::~Tape()
{

}

//The method load loads the blank character passed into the attribute Tape class attribute blank_character.
void Tape::load(string blank_char)
{
	//cout << "Blank Character: " << blank_char << endl;
	blank_character = blank_char[1];
}

//The method update first determines if the update of the Turing machine tape is possible. 
//The method throws a crash if a left move is specified from the first cell. 
//If a right move is specified from the last cell, a blank character is appended to the tape. 
void Tape::update(char write_character, Direction move_direction)
{
	string temp = move_direction;

	for(int i = 0; i < temp.size(); i++)
	{
		temp[i] = toupper(temp[i]);
	}

	move_direction = temp;

	//Check if we are at the first cell and trying to move left
	if((current_cell == 0) && (move_direction == "L"))
	{
		//Crash the Turing Machine
		//return;
		throw crash("Left move from first cell");
	}

	//Check if we are at the last cell and trying to move right and if so append a blank_character 
	if((current_cell == cells.length() - 1) && (move_direction == "R"))
	{

		cells += blank_character;
		//Debug
		//cout << "Cells: " << cells << endl;
	}

	cells[current_cell] = write_character;

	if(move_direction == "L")
		--current_cell;
	else
		++current_cell;
}

//The method left returns a character string up to the maximum number of cells from the Turing machine tape 
//to the left of the current cell, excluding that cell. 
string Tape::left(int maximum_number_of_cells) const
{
	int first_cell = max(0, current_cell - maximum_number_of_cells);

	string left_side = cells.substr(first_cell, current_cell - first_cell);

	//Check to see if we need to truncate the string
	if(left_side.length() < current_cell)
	{
		left_side.insert(0, "<");
	}

	//cout << "Left_Side: " << left_side << endl;
	return left_side;
}

//The method right returns a character string up to the maximum number of cells from the Turing machine tape
//to the right of the current cell, excluding that cell. 
string Tape::right(int maximum_number_of_cells) const
{
	int last_cell = cells.length() - 1;

	while((last_cell >= current_cell) && (cells[last_cell] == blank_character))
	{
		--last_cell;
	}

	int end_cell = min(last_cell, current_cell + maximum_number_of_cells -1);

	string right_side = cells.substr(current_cell, end_cell - current_cell + 1);


	//Check to see if we need to truncate the string
	if(right_side.length() < last_cell - current_cell + 1)
	{
		right_side.append(">");
	}

	//cout << "Right_Side: " << right_side << endl;
	return right_side;
}

//The method current_character returns the character contained in the current cell on the Turing machine tape.
char Tape::current_character() const
{
	return cells[current_cell];
}

//The method is_first_cell returns a value of true if the current cell on the Turing machine tape is the first cell,
//indicated by the index 0. Otherwise, it returns a value of false.
bool Tape::is_first_cell() const
{
	return (current_cell == 0);
}

//The method initialize sets the Turing machine tape to the input string followed by a blank character, 
//replacing the previous contents of the tape. The current cell is set to the first cell on the tape, indicated by the index 0.
void Tape::initialize(string input_string)
{
	cells = input_string + blank_character;
	//cout << "Tape: " << cells << endl;
	current_cell = 0;
}
