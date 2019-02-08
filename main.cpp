/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: The method main is the top-level entry point for the application. 
*			   It is in control of starting all the other classes in the application.
* 	Description: The method main will
*				 1. Open the definition file and store the contents in the class
*					FileParser.
*				 2. Open the input string file and store the contents in a vector<string> 
*				 3. This method main will hold the commands that will control the
*					Turing Machine.
*	Running Program: Included in the package is a MakeFile
*				 1. Simply type make to compile and link the program in to the executable
*					tm.
*				 2. To run the program after running the make command simply type
*					./tm [filename] (without extention).
*				 3. The MakeFile also includes two test cases valid and invalid.
*				 4. To run test cases simple type make valid or make invalid to run test
*				 	cases.
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Commands.h"
#include "FileParser.h"
#include "Turing_Machine.h"
#include "Visible.h"
#include "color.h"

using namespace std;

int main(int argc, char const *argv[])
{
	string select 		  = ""; 	 //used to store the user input from the Command: prompt
	string buffer		  = "";		 //used to store the single word retrieved from the file for possible error checking
	int maxTransitions 	  = 1;		 //used to store the max transition to perform for the Turing machine
	int maxCells 		  = 32;		 //used to store the max cells to truncate in the instantaneous description	
	int Exit 			  = 0;
	char selection 		  = '\0';	 //used to store user defined selection for the command to run
	string current_used_input = "";  //used to store the input string that is currently running on the Turing_Machine
	const int Success(0);			 //used to exit the program successfully
	const int Failure(-1);			 //used to exit the program if a failure happens

	if(argc != 2)
	{
		cout << "Please enter two parameters" << endl << "Command_Line_Prompt: tm definition_filename" << endl;

		return Failure;
	}
	else
	{
		FileParser *Parser = new FileParser;		
		string def = argv[1];			  //Store file name without extention
		string definition = def + ".def"; //Storing the definition file with extention
		
		
		ifstream defFile(definition.c_str()); //Opening the definition file	
		string oneWord = "";

		if(defFile.is_open())
		{
			while(defFile.good())
			{
				while(getline(defFile, buffer))
				{
					string temp1 = buffer;
					/*
						Find the description in this section to fix view command not keeping
						original format of description of the turing machine.
					*/
					stringstream sso(temp1);
					while(sso >> oneWord)
					{
						Parser = Parser->parseDefinitionFile(Parser, oneWord);
					}	
					
				}	
			}

			defFile.close();
		}
		else
		{
			cout << "Invalid File: Unable to open file" << endl;
		}

		//Check if the Definition file is valid in detail
		Parser->validateFile();


		//If Definition file has errors exit application
		if (Parser->getDefinitionGood() == false)
		{

			cerr << endl << "Invalid Definition File: Please check definition file format.\n" << endl;
			delete Parser;
			return Failure;			
		}


		//////////////////////////////////////////////////////////////////////////
		// 							Start of Interface						   //
		////////////////////////////////////////////////////////////////////////
		cout << "\nTuring Machine Loaded Successfully!" << endl;
		string inputFile = def + ".str";  //Storing the tape input file
		fstream input_string_file(inputFile.c_str());
		string userInput; //used to store user input
		vector<string> input_strings; //used to store input_strings
		Turing_Machine Turing_Machine(Parser);

		//Store input_string_file into input_strings vector
		if(input_string_file.is_open())
		{
			while(input_string_file.good())
			{
				while(input_string_file >> buffer)
				{
					string temp1 = buffer;
					if(temp1.find("\\") != string::npos)
					{
						//cout << "Found Lamda!" << endl;
						input_strings.push_back("");
					}
					else
					{
						input_strings.push_back(temp1);
					}
				}				

			}
		}
		input_string_file.close();
		
		ofstream string_file(inputFile.c_str());


		while(1)
		{	
			do{
				cout << endl << "Command: ";
				getline(cin, select);
				if(select.size() > 1)
				{
					cout << "Invalid Command" << endl << "Enter " << FGRN("H") << " for help" << endl;
				}

			  }while(select.size() > 1);

			selection = select[0];

			switch(selection)
			{
				case 'd': //Delete Command
				case 'D':

						delete_command(input_strings);
						break;


				case 'x': //Exit Command
				case 'X':						
						
						Exit = exit_command(string_file, input_strings);
						
						if(Exit == Success)
						{
							delete Parser;
							return Success;
							break;
						}
						else if(Exit == Failure)
						{
							delete Parser;
							return Failure;
							break;
						}

				case 'h': //Help Command
				case 'H':

						help_command();
						break;

				case 'i': //Insert Command
				case 'I':

						insert_command(input_strings, Parser);
						break;

				case 'l': //List Command
				case 'L':

						list_command(input_strings);
						break;

				case 'q': //Quit Command
				case 'Q':

						quit_command(Turing_Machine);
						break;

				case 'r': //Run Command
				case 'R':

						run_command(Turing_Machine, current_used_input, input_strings, maxTransitions, maxCells);
						break;

				case 'e': //Set Command
				case 'E':
						
						set_command(maxTransitions);
						break;

				case 'w': //Show Command
				case 'W':

						show_command(Turing_Machine, current_used_input, maxTransitions, maxCells, def);
						break;

				case 't': //Truncate Command
				case 'T':

						truncate_command(maxCells);
						break;

				case 'v': //View Command
				case 'V':
						Parser->displayDefinition();
						break;

				default:
					cout << "Invalid Command" << endl << "Enter " << FGRN("H") << " for help" << endl; 
			}

		}
		//////////////////////////////////////////////////////////////////////////
	}

	return Success;
}
