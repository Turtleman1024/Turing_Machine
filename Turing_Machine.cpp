/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class represents a design of a Turing machine
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <exception>

#include "Turing_Machine.h"
#include "Tape.h"
#include "Input_Alphabet.h"
#include "Tape_Alphabet.h"
#include "Transition_Function.h"
#include "States.h"
#include "Final_States.h"
#include "FileParser.h"
#include "Direction.h"

using namespace std;

Turing_Machine::Turing_Machine(FileParser *Parser)
{
	initial_state = Parser->getInitialState();
	initial_state.erase(initial_state.begin());	//There is an extra space needed to delete it 
	current_state = Parser->getInitialState();
	current_state.erase(current_state.begin()); //There is an extra space needed to delete it
	number_of_transictions = 0;
	used = false;
	operating = false;
	accepted = false;
	rejected = false;

	tape.load(Parser->getBlankCharacter());
	input_alphabet.load(Parser->getInputAlphabet());
	tape_alphabet.load(Parser->getTapeAlphabet());
	transition_function.load(Parser->getTransition());
	states.load(Parser->getStates());
	final_states.load(Parser->getFinalState());


}

Turing_Machine::~Turing_Machine()
{

}

//The method view_instantanous_description will display the instantaneous description to the screen. 
void Turing_Machine::view_instantanous_description(int max_number_of_cells) const
{
	//cout << "Debug: " << current_state << ": " << current_state.length() << endl;;

	cout << number_of_transictions << ". " << tape.left(max_number_of_cells) 
		 << "[" << current_state << "]" << tape.right(max_number_of_cells) << endl;
}

//The method initialize will set the current input string to input_string if the operating attribute is set to false. 
void Turing_Machine::initialize(string input_string)
{
	used = true;
	operating = true;
	accepted = false;
	rejected = false;
	number_of_transictions = 0;

	current_state = initial_state;
	original_input_string = input_string;

	tape.initialize(input_string);

	if(final_states.is_element(initial_state))
	{
		//cout << endl << "The Input String " << original_input_string << " is accepted in " << number_of_transictions << " transitions" << endl;
		accepted = true;
		operating = false;
	}
}

//This method will continue to run the Turing machine until the amount of transition reaches the maximum_number_of_transitions
//unless the Turing machine accepts or rejects the input string before the maximum number of transition is met. 
void Turing_Machine::perform_transitions(int maximum_number_of_transitions)
{
	//First look through all the transitions
	for(int index = 0; index < maximum_number_of_transitions; index++)
	{
		//Check if the current state is a final state and accept the string
		if(final_states.is_element(current_state))
		{
			accepted = true;
			operating = false;
			return;
		}

		//Get the current cells character
		char current_tape_character = tape.current_character();
		//cout << "Current Tape Character: " << current_tape_character << endl;
		string destination_state = "";
		char write_character = ' ';
		Direction move_direction;

		//Find a matching transition if a transition cannot be found a crash will be thrown
		try
		{
			transition_function.find_transition(current_state, current_tape_character, destination_state, write_character, move_direction);
		} catch(exception& error)
		  {
		  	rejected = true;
		  	operating = false;
		  	return;
		  }

		try
		{
		  //cout << "Called Update" << endl;
		  tape.update(write_character, move_direction);
		} catch(exception& error)
		  {
		  	rejected = true;
		  	operating = false;
		  	return;
		  }
		
		//If the Turing machine did not crash change states
		current_state = destination_state;

		//Making a transition
		number_of_transictions++;

		//The Turing machine is now operating
		operating = true;		
	}

	//Check if the current state is a final state and accept the string
	if(final_states.is_element(current_state))
	{
		accepted = true;
		operating = false;
		return;
	}
}

//The method terminate_operation will stop the operation on the current 
//input string by setting the operating attribute to false. 
void Turing_Machine::terminate_operation()
{
	operating = false;
}

//The method input_string returns the current input string that the Turing machine is operating on.
string Turing_Machine::input_string()
{
	return original_input_string;
}

//The method total_number_of_transitions will return the number of transition 
//that have been performed on the current user selected input string.
int Turing_Machine::total_number_of_transitions()
{
	return number_of_transictions;
}

/*
bool Turing_Machine::is_valid_input_string(string value)
{
	return true;
}*/


//The method is_used will return a true or false if the Turing machine has been used
bool Turing_Machine::is_used() const
{
	return used;
}

//The method is_operating will return a true or false if the Turing machine is operating on a input string. 
bool Turing_Machine::is_operating() const
{
	return operating;
}

//The method is_accepted will return the value of accepted
bool Turing_Machine::is_accepted() const
{
	return accepted;
}


//The method is_rejected will return the value of rejected
bool Turing_Machine::is_rejected() const
{
	return rejected;
}