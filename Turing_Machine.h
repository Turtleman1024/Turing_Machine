/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class represents a design of a Turing machine
*/

#ifndef _TURING_MACHINE_
#define _TURING_MACHINE_

#include <string>

#include "Tape.h"
#include "Input_Alphabet.h"
#include "Tape_Alphabet.h"
#include "Transition_Function.h"
#include "States.h"
#include "Final_States.h"
#include "FileParser.h"

using namespace std;

class Turing_Machine
{
	private:
		Tape tape;
		Input_Alphabet input_alphabet;
		Tape_Alphabet tape_alphabet;
		Transition_Function transition_function;
		States states;
		Final_States final_states;

		//The attribute initial_state will store the initial state loaded from the FileParser class.
		string initial_state;

		//The attribute current_states will store the current state of the Turning machine.
		string current_state;

		//The attribute original_input_string will store the original input string that was initially put on the Turing machine tape.
		string original_input_string;

		//The attribute number_of_transiction will store the number of transitions that the Turing machine has run.
		int number_of_transictions;

		//The attribute used will store if the Turing machine has been used.
		bool used;

		//The attribute operating will store if the Turing machine is currently operating on an input string.
		bool operating;

		//The attribute accepted will store if the Turing machine accepted the input string.
		bool accepted;

		//The attribute rejected will store if the Turing machine rejected the input string.
		bool rejected;


	public:
		Turing_Machine(FileParser *Parser);
		~Turing_Machine();
		void view_instantanous_description(int max_number_of_cells) const;
		void initialize(string input_string);
		void perform_transitions(int maximum_number_of_transitions);
		void terminate_operation();
		string input_string();
		int total_number_of_transitions();
		//bool is_valid_input_string(string value);
		bool is_used() const;
		bool is_operating() const;
		bool is_accepted() const;
		bool is_rejected() const;
};


#endif  /*_TURING_MACHINE_*/