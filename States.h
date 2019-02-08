/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class stores the states that the turing machine can be in at any given time
*/

#ifndef _STATES_
#define _STATES_

#include "vector"

using namespace std;

class States
{
	private:
		//The method load will load the states into the attribute name.
		vector<string> name;

	public:
		States();
		~States();
		void load(string states);
		bool is_element(string value);

};

#endif /* _STATES_ */