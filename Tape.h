/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class hold the representation of the Turing machine tape
*/

#ifndef _TAPE_
#define _TAPE_
#include "Direction.h"
#include <string>

using namespace std;

class Tape
{
	private:
		//The attribute cells is a dynamically growing character string containing the Turing machine tape. 
		string cells;

		//The index of the current cell on the Turing machine tape is stored in the attribute current_cell.
		int current_cell;

		//The blank character used to initialize and extend the Turing machine tape is contained in the attribute blank_character.
		char blank_character;

	public:
		Tape();
		~Tape();
		void load(string blank_char);
		void update(char write_character, Direction move_direction);
		string left(int maximum_number_of_cells) const;
		string right(int maximum_number_of_cells) const;
		char current_character() const;
		bool is_first_cell() const;
		void initialize(string input_string);

};

#endif /* _TAPE_ */