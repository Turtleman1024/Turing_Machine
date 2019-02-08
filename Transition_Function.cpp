/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This file stores the methods for the class Transition-Functions that are responsable for loading the transitions and selecting the correct
*			   transition for the next transition.
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>

#include "Direction.h"
#include "Transition.h"
#include "Transition_Function.h"
#include "Crash.h"

using namespace std;

Transition_Function::Transition_Function()
{

}

Transition_Function::~Transition_Function()
{

}

//This method will load the transition in the the attribute transitions
void Transition_Function::load(string trans)
{
	string temp_transitions = trans;
	string source = "";
	string read   = "";
	string destination = "";
	string write = "";
	string move = "";
	int counter = 0;

	string temp1 = temp_transitions;
	string temp2;
	stringstream sso(temp1);

	//cout << "Original: " << trans << endl;
	//cout << endl << "Transition: " << endl;
	while(sso >> temp2)
	{
		if(counter == 0)
		{
			source = temp2;
			//cout << " " << source << ":" << source.length();
			counter++;
		}
		else if(counter == 1)
		{
			read = temp2;
			//cout << " " << read << ":" << read.length();
			counter++;
		}
		else if(counter == 2)
		{
			destination = temp2;
			//cout << " " << destination << ":" << destination.length();
			counter++;
		}
		else if(counter == 3)
		{
			write = temp2;
			//cout << " " << write << ":" << write.length();
			counter++;
		}
		else if(counter = 4)
		{
			move = temp2;
			//cout << " " << move << ":" << move.length() << endl;
			Transition new_transition(source, read[0], destination, write[0], move);
			transitions.push_back(new_transition);
			counter = 0;
		}
	}
	//cout << endl;
}

//The method find_transition will search all of the class transition until it finds a matching source and read character, 
//or if it has searched all of the Transitions and was unable to find a transition a crash is thrown. 
void Transition_Function::find_transition(string source_state, char read_character, string& destination_state,
										  char& write_character, Direction& move_direction) const
{
	for(unsigned int index = 0; index < transitions.size(); index++)
	{
		if(transitions[index].source_state() == source_state && transitions[index].read_character() == read_character)
		{
			destination_state = transitions[index].destination_state();
			write_character = transitions[index].write_character();
			move_direction = transitions[index].move_direction();
			return;
		}
	}

	//If no transition was found need to crash the turing_machine
	throw crash("The Turing Machine has crashed!");
}
