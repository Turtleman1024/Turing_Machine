/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class is responsable for loading the transitions and selecting the correct
*			   transition for the next transition
*/

#ifndef _TRANSITION_FUNCTION_
#define _TRANSITION_FUNCTION_

#include <vector>
#include <string>

#include "Direction.h"
#include "Transition.h"

using namespace std;

class Transition_Function
{
	private:
		//This attribute will store the transitions
		vector<Transition> transitions;

	public:
		Transition_Function();
		~Transition_Function();
		void load(string trans);
		void find_transition(string source_state, char read_character, string& destination_state,
						 	 char& write_character, Direction& move_direction) const;

};

#endif /* _TRANSITION_FUNCTION_ */