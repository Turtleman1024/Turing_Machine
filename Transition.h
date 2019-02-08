/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class is to hold a single turing machine transition.
*/


#ifndef _TRANSITION_
#define _TRANSITION_

#include <string>
#include <cstring>
#include "Direction.h"

using namespace std;

class Transition
{
	private:
		//The attribute source contains the name of the current state that the Turing machine must be in to use the transition.
		string source;

		//The attribute read contains the current character that must be in the cell of the tape.
		char read;

		//The attribute destination contains the name of the state in which to transition too.
		string destination;

		//The attribute write contains the character that will be written to the current tape cell before moving to the next tape cell.
		char write;

		//The attribute move contains the direction that the tape head will move after the write character has been written.
		Direction move;

	public:
		Transition(string source_state, char read_character, string destination_state,
					char write_character, Direction move_direction);
		~Transition();
		string source_state() const;
		char read_character() const;
		string destination_state() const;
		char write_character() const;
		Direction move_direction() const;
};

#endif /* _TRANSITION_ */