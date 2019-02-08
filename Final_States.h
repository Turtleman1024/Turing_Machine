/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class stores the final states in which the turing machine cannot leave.
*			   Input string is accepted and the turing machine operating will be set to false
*/

#ifndef _FINAL_STATES_
#define _FINAL_STATES_

#include "vector"

using namespace std;

class Final_States
{
	private:
		//The attribute names will store all the final states names.
		vector<string> name;

	public:
		Final_States();
		~Final_States();
		void load(string final_states);
		bool is_element(string value);
};

#endif /* _FINAL_STATES_ */