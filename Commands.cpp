#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "FileParser.h"
#include "Turing_Machine.h"
#include "Visible.h"
#include "color.h"

using namespace std;

void help_command()
{
	cout << endl << "\t   (" << FGRN("D")<< ")elete\tDelete input string from list" << endl;
	cout << "\t  E(" << FGRN("x") << ")it\tExit application" << endl;
	cout << "\t   (" << FGRN("H")  << ")elp\tHelp user" << endl;
	cout << "\t   (" << FGRN("I")  << ")nsert\tInsert input string into list" << endl;
	cout << "\t   (" << FGRN("L")  << ")ist\tList input strings" << endl;
	cout << "\t   (" << FGRN("Q")  << ")uit\tQuit operation of Turing machine on input string" << endl;
	cout << "\t   (" << FGRN("R") << ")un\tRun Turing machine on input string" << endl;
	cout << "\t  S(" << FGRN("e") << ")t\t\tSet maximum number of transitions to perform" << endl;
	cout << "\tSho(" << FGRN("w") << ")\t\tShow status of application" << endl;
	cout << "\t   (" << FGRN("T") << ")runcate\tTruncate instantaneous descriptions" << endl;
	cout << "\t   (" << FGRN("V") << ")iew\tView Turing machine" << endl;	
}

void delete_command(vector<string>& input_strings)
{
	bool isValid = true;
	string userInput;

	cout << endl << "Input String Number: ";
	getline(cin, userInput);

	if(userInput.empty())
	{
		cout << "Invalid Entry: Must be a number." << endl;
		return;
	}

	for(unsigned int i = 0; i < userInput.size(); i++)
	{
		if(userInput[i] > '9' || userInput[0] <= '0')
		{
			cout << "Invalid Entry: Must be a positive number." << endl;
			isValid = false;
			break;
		}
	}

	if(isValid == false)
	{
		isValid = true;
		return;
	}

	//Check if the user defined line number is larger than input string size
	if(atoi(userInput.c_str()) > input_strings.size())
	{
		cout << "Non-existent line number." << endl;
		return;
	}
	else
	{
		cout << "Input String "<< input_strings.at(atoi(userInput.c_str()) - 1) << " Deleted!" << endl;
		input_strings.erase(input_strings.begin() + atoi(userInput.c_str()) - 1);
							
	}	
}

void insert_command(vector<string>& input_strings, FileParser *Parser)
{
	bool isValid = true;
	string newInputString;

	cout << endl << "Input String: ";

	getline(cin, newInputString);

	if(newInputString == "")
	{
		cout << "Error: Invalid input." << endl;
		return;
	}

	for(unsigned int i = 0; i < newInputString.size(); i++)
	{
		if(newInputString[i] == 92)
		{
			break;
		}
		else if(newInputString[i] < 97 || newInputString[i] > 122)
		{
			cout << "Invalid Entry: Must be string of characters." << endl;
			isValid = false;
			break;
		}
	}

	if(isValid == false)
	{
		isValid = true;
		return;
	}

	//Check if user entered lamda
	if(newInputString == "\\")
	{
		newInputString = "";
		bool temp = Parser->duplicateString(input_strings, newInputString);
							
		if(temp == true)
		{
			input_strings.push_back(newInputString);
			cout << "String \\ Inserted into List!" << endl;
		}
	}
	else
	{
		//Check for valid user input string
		bool temp1 = Parser->validate(newInputString);
		bool temp2 = Parser->duplicateString(input_strings, newInputString);
							
		if(temp1 == true && temp2 == true)
		{
			input_strings.push_back(newInputString);
			cout << "String " << newInputString << " inserted into List!" << endl;
		}					
	}	
}

void list_command(vector<string>& input_strings)
{
	cout << endl;
	if(input_strings.size() == 0)
	{
		cout << "Input string file is empty!" << endl;
		return;
	}

	for(unsigned int index = 0; index < input_strings.size(); index++)
		cout << (index + 1) << ". " << visible(input_strings[index]) << endl;
	
}

int exit_command(ofstream& string_file, vector<string>& input_strings)
{
	if(string_file.is_open())
	{
		for(unsigned int index = 0; index < input_strings.size(); index++)
			string_file << visible(input_strings[index])  << "\n";

		cout << endl << "Successfully Wrote Input String File!" << endl << endl;
		string_file.close();
		return 0;											
	}
	else
	{
		cout << endl << "Error: Failed To Create File!" << endl << endl;
		string_file.close();
		return -1;						
	}	
}

void quit_command(Turing_Machine& Turing_Machine)
{
	if(!Turing_Machine.is_operating())
	{
		cout << "Turing Machine is currently not running on an input string!" << endl;
		return;
	}

	if(Turing_Machine.is_operating())
	{
		Turing_Machine.terminate_operation();
		cout << "Input string " << visible(Turing_Machine.input_string()) << " not " << FGRN("accepted") << " or " << FRED("rejected") << " in " 
			 << Turing_Machine.total_number_of_transitions() << " transitions." << endl;			
	}	
}

void set_command(int& max_transitions)
{
	bool isValid = true;
	string userInput;
	int temp = 0;

	cout << endl << "Maximum Number of Transitions[" << max_transitions << "]: ";
	getline(cin, userInput);

	if(userInput.empty())
	{
		cout << "Invalid Entry: Must be a number." << endl;
		return;
	}

	for(unsigned int i = 0; i < userInput.size(); i++)
	{
		if((userInput[i] > '9')|| (userInput[i] < '0'))
		{
			cout << "Invalid Entry: Must be a positive number." << endl;
			isValid = false;
			return;
		}
	}

	if(isValid == false)
	{
		isValid = true;
		return;
	}

	temp = 0;

	try{
		temp = atoi(userInput.c_str());
		} catch(out_of_range& oor)
		  {
			cout << "Error: Transition is to large." << endl;
			return;

		  }
	
	if(temp <= 0)
	{
		cout << "Error: Must be a positive number" << endl;
		return;
	}
	else
	{
		max_transitions = temp;

		cout << "Maximum Transitions Changed to " << max_transitions << "!" << endl;
		return;							
	}
}

void show_command(Turing_Machine Turing_Machine, string current_used_input, int maxTransitions, int maxCells, string def)
{
	cout << endl << " Course: CptS 323" << endl;
	cout << " Semester: Spring" << endl;
	cout << " Year: 2017" << endl;
	cout << " Instructor: Neil B. Corigan" << endl;
	cout << " Author: Kenneth M Murry" << endl;
	cout << " Version: 2.0" << endl;
	cout << " Maximum Transitions: " << maxTransitions << endl;
	cout << " Maximum Cells: " << maxCells << endl;
	cout << " Name of Turing machine: " << def << endl;

	//If the Turing Maching is not used 
	if(!Turing_Machine.is_used())
	{
		cout << " Status: Turing machine has not been ran on an input string." << endl;
		cout << " Transitions: " << Turing_Machine.total_number_of_transitions() << endl;
		//If not used then the string should be blank
		cout << " Input String: " /*<< visible(current_used_input) */<< endl;
		return;							
	}

	//If the Turing Machine is operating
	if(Turing_Machine.is_operating())
	{
		cout << " Status: Turing machine is currently runnning on an input string." << endl;
		cout << " Transitions: " << Turing_Machine.total_number_of_transitions() << endl;
		cout << " Input String: " << visible(current_used_input) << endl;
		return;							 
	}

	//If the Turing Machine is not operating
	if(!Turing_Machine.is_operating())
	{
		//If the Turing Machine has accepted a input string
		if(Turing_Machine.is_accepted())
		{
			cout << " Status: The input string " << visible(current_used_input) << " was " << FGRN("accepted") << "." << endl;
			cout << " Transitions: " << Turing_Machine.total_number_of_transitions() << endl;
			cout << " Input String: " << visible(current_used_input) << endl;
			return;								
		}
		else if(Turing_Machine.is_rejected()) //If the Turing Machine has rejected a input string
		{
			cout << " Status: The input string " << visible(current_used_input) << " was " << FRED("rejected") << "." << endl;
			cout << " Transitions: " << Turing_Machine.total_number_of_transitions() << endl;
			cout << " Input String: " << visible(current_used_input) << endl;
			return;								
		}
		else //If the Turing Machine was operating
		{
			cout << " Status: The input string " << visible(current_used_input) << " was not " << FGRN("accepted") << " or " << FRED("rejected") << "." << endl;
			cout << " Transitions: " << Turing_Machine.total_number_of_transitions() << endl;
			cout << " Input String: " << visible(current_used_input) << endl;
			return;
		}

	}	
}

void truncate_command(int& maxCells)
{
	bool isValid = true;
	string userInput;
	int temp = 0;

	cout << endl << "Maximum Number of Cells[" << maxCells << "]: ";
	getline(cin, userInput);

	if(userInput.empty())
	{
		cout << "Invalid Entry: Must be a number." << endl;
		return;
	}

	for(unsigned int i = 0; i < userInput.size(); i++)
	{
		if(userInput[i] > '9' || userInput[i] < '0')
		{
			cout << "Invalid Entry: Must be a positive number." << endl;
			isValid = false;
			return;
		}
	}

	if(isValid == false)
	{
		isValid = true;
		return;
	}

	temp = 0;

	try{
		temp = atoi(userInput.c_str());
		} catch(out_of_range& oor)
		  {
			cout << "Error: Maximum number of cells is to large." << endl;
			return;
		  }

	if(temp <= 0)
	{
		cout << "Error: Must be a positive number." << endl;
		return;
	}
	else
	{
		maxCells = temp;

		cout << "Maximum Cells Changed to " << maxCells << "!" << endl;
		return;							
	}	
}

void run_command(Turing_Machine& Turing_Machine, string& current_used_input, vector<string>& input_strings, int& maxTransitions, int& maxCells)
{
	//Check if the Turing machine is operating before prompting user for input string
	if(Turing_Machine.is_operating())
	{
		//cout <<endl;
		//Turing_Machine.view_instantanous_description(maxCells);
		Turing_Machine.perform_transitions(maxTransitions);
		cout << endl;
		Turing_Machine.view_instantanous_description(maxCells);
							
		//Check if the input string was accepted
		if(Turing_Machine.is_accepted())
			cout << endl << visible(Turing_Machine.input_string()) << " was " << FGRN("accepted") << " in " << Turing_Machine.total_number_of_transitions() << " transitions." << endl;

		//Check if the input string was rejected
		if(Turing_Machine.is_rejected())
			cout << endl << visible(Turing_Machine.input_string()) << " was " << FRED("rejected") << " in " << Turing_Machine.total_number_of_transitions() << " transitions." << endl;

			return;							
	}


	//If Turing machine is not operating prompt for user for an input string number
	bool isValid = true;
	string userInput;
	int temp = 0;

	cout << endl << "Input String number: ";
	getline(cin, userInput);

	if(userInput.empty())
	{
		cout << "Invalid Entry: Must be a number." << endl;
		return;
	}

	for(unsigned int i = 0; i < userInput.size(); i++)
	{
		if((userInput[i] > '9') || (userInput[i] < '0'))
		{
			cout << "Error: Must be a positive number." << endl;
			isValid = false;
			return;
		}
	}

	if(isValid == false)
	{
		isValid = true;
		return;
	}

	temp = 0;

	try{
		temp = atoi(userInput.c_str());
	   } catch(out_of_range& oor){
			cout << "Error: Number entered is to large." << endl;
			return;

		}

		if(temp <= 0)
		{
			cout << "Error: Must be a positive number." << endl;
			return;
		}
		else if((atoi(userInput.c_str())) > (input_strings.size()))
		{
			cout << "Non-existent line number." << endl;
			return;
		}
		else
		{
			current_used_input = input_strings[atoi(userInput.c_str()) - 1];
		}

		/*Just added not in implementation source code document
		if(current_used_input == "")
		{
			string temp = Parser->getBlankCharacter();
			temp.erase(temp.begin());
			current_used_input = temp;
		//End of just added*/

		Turing_Machine.initialize(current_used_input);
		cout << endl;
		Turing_Machine.view_instantanous_description(maxCells);
		Turing_Machine.perform_transitions(maxTransitions);
		cout << endl;
		Turing_Machine.view_instantanous_description(maxCells);

		//Check if the input string was accepted
		if(Turing_Machine.is_accepted())
			cout << "\nThe input string " << visible(Turing_Machine.input_string()) << " was " << FGRN("accepted") << " in " << Turing_Machine.total_number_of_transitions() << " transitions." << endl;

		//Check if the input string was rejected
		if(Turing_Machine.is_rejected())
			cout << "\nThe input string " << visible(Turing_Machine.input_string()) << " was " << FRED("rejected") << " in " << Turing_Machine.total_number_of_transitions() << " transitions." << endl;
		return;	
}