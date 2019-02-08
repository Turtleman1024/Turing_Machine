/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class perform validation of the Turing machine by parsing of the definition file
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
//#include <fstream>
#include <sstream>
#include "FileParser.h"
#include "color.h"

using namespace std;

FileParser::FileParser():
			description(""), states(""), inputAlphabet(""),
			tapeAlphabet(""), transition(""), initialState(""),
			blankCharacter(""), finalState(""), descriptionFound(false),
			statesFound(false),	inputAlphabetFound(false), tapeAlphabetFound(false),
			transitionFound(false),	initialStateFound(false), blankCharacterFound(false),
			finalStateFound(false),	definitionGood(true)
			{				
			} 


FileParser::~FileParser()
{

}

//This function will Parse the Defintion File and store the current word in to the 
//correct category.
FileParser* FileParser::parseDefinitionFile(FileParser *Parser, string currentWord)
{
	string wordToParse = currentWord;
	string temp;

	temp = wordToParse;

	if(getDescriptionFound() == false)
	{
		//Looking for STATES: tag to know that the 
		//definition of the TM has been found
		for(int i = 0; i < temp.size(); i++)
			temp[i] = toupper(temp[i]);

		if(temp == "INPUT_ALPHABET:")
		{
			cerr << "Invalid File Format: Description Not Found!" << endl;
			setDefinitionGood(false);
			setDescriptionFound(true);
			return Parser;
		}
		else if(temp == "STATES:")
		{
			setDescriptionFound(true);
			return Parser;
		}
		else
		{
			  string temp2 = getDescription()  + wordToParse + " ";
			  setDescription(temp2);
		}
	}
	else if(getStatesFound() == false)
	{
		//Looking for INPUT_ALPHABET: tag to know that the 
		//STATES: of the TM has been found		
		for(int i = 0; i < temp.size(); i++)
			temp[i] = toupper(temp[i]);

		if(temp == "TAPE_ALPHABET:")
		{
			cerr << "Invalid File Format: States Not Found!" << endl;
			setDefinitionGood(false);
			setStatesFound(true);
			return Parser;

		}
		else if(temp == "INPUT_ALPHABET:")
		{
			setStatesFound(true);
			return Parser;
		}
		else
		{
			  string temp2 = getStates() + " " + wordToParse;
			  setStates(temp2);
		}
	}
	else if(getInputAlphabetFound() == false)
	{
		//Looking for TAPE_ALPHABET: tag to know that the 
		//INPUT_ALPHABET: of the TM has been found		
		for(int i = 0; i < temp.size(); i++)
			temp[i] = toupper(temp[i]);

		if(temp == "TRANSITION_FUNCTION:")
		{
			cerr << "Invalid File Format: Input_Alphabet not found!" << endl;
			setDefinitionGood(false);
			setInputAlphabetFound(true);
			return Parser;
		}
		else if(temp == "TAPE_ALPHABET:")
		{
			setInputAlphabetFound(true);
			return Parser;
		}
		else
		{
			  string temp2 = getInputAlphabet() + " " + wordToParse;
			  setInputAlphabet(temp2);
		}
	}
	else if(getTapeAlphabetFound() == false)
	{
		//Looking for TRANSITION_FUNCTION: tag to know that the 
		//TAPE_ALPHABET: of the TM has been found		
		for(int i = 0; i < temp.size(); i++)
			temp[i] = toupper(temp[i]);

		if(temp == "INITIAL_STATE:")
		{
			cerr << "Invalid File Format: Tape_Alphabet not found!" << endl;
			setDefinitionGood(false);
			setTapeAlphabetFound(true);
			return Parser;
		}
		else if(temp == "TRANSITION_FUNCTION:")
		{
			setTapeAlphabetFound(true);
			return Parser;
		}
		else
		{
			  string temp2 = getTapeAlphabet() + " " + wordToParse;
			  setTapeAlphabet(temp2);
		}
	}
	else if(getTransitionFound() == false)
	{
		//Looking for INITIAL_STATE: tag to know that the 
		//TRANSITION_FUNCTION: of the TM has been found		
		for(int i = 0; i < temp.size(); i++)
			temp[i] = toupper(temp[i]);

		if(temp == "BLANK_CHARACTER:")
		{
			cerr << "Invalid File Format: Transitions not found!" << endl;
			setDefinitionGood(false);
			setTransitionFound(true);
			return Parser;
		}
		else if(temp == "INITIAL_STATE:")
		{
			setTransitionFound(true);
			return Parser;
		}
		else
		{
			  string temp2 = getTransition() + " " + wordToParse;
			  setTransition(temp2);
		}
	}
	else if(getInitialStateFound() == false)
	{
		//Looking for BLANK_CHARACTER: tag to know that the 
		//INITIAL_STATE: of the TM has been found			
		for(int i = 0; i < temp.size(); i++)
			temp[i] = toupper(temp[i]);

		if(temp == "FINAL_STATES:")
		{
			cerr << "Invalid File Format: Initial_State not found!" << endl;
			cerr << "Invalid File Format: Blank_Character not found!" << endl;
			cerr << "Invalid File Format: Final_States not found!" << endl;
			setDefinitionGood(false);
			setInitialStateFound(true);
			return Parser;
		}
		else if(temp == "BLANK_CHARACTER:")
		{
			setInitialStateFound(true);
			return Parser;
		}
		else
		{
			  string temp2 = getInitialState() + " " + wordToParse;
			  setInitialState(temp2);
		}
	}
	else if(Parser->getBlankCharacterFound() == false)
	{
		//Looking for FINAL_STATES: tag to know that the 
		//BLANK_CHARACTER: of the TM has been found		
		for(int i = 0; i < temp.size(); i++)
			temp[i] = toupper(temp[i]);

		if(temp == "FINAL_STATES")
		{	//Come back to this
			cerr << "Invalid File Format: Blank_Character not found!" << endl;
			cerr << "Invalid File Format: Final_States not found!" << endl; 
			setDefinitionGood(false);
			setBlankCharacterFound(true);
			return Parser;
		}
		else if(temp == "FINAL_STATES:")
		{
			Parser->setBlankCharacterFound(true);
			return Parser;
		}
		else
		{
			  string temp2 = getBlankCharacter() + " " + wordToParse;
			  setBlankCharacter(temp2);
		}
	}
	else if(Parser->getFinalStateFound() == false)
	{
		//Looking for FINAL_STATES: tag to know that the 
		//FINAL_STATES: of the TM has been found		
		for(int i = 0; i < temp.size(); i++)
			temp[i] = toupper(temp[i]);

		if(temp == "FINAL_STATES:")
		{
			Parser->setFinalStateFound(true);
			return Parser;
		}
		else
		{
			  string temp2 = getFinalState() + " " + wordToParse;
			  setFinalState(temp2);
		}
	}

	return Parser;
}

//This function will check to make sure reserved characters are not in alphabet
void FileParser::checkReservedChar(string alphabet, string type)
{
	/*Check for reserved character \ */
	if(alphabet.find("\\") == string::npos)
	{
		if(getDefinitionGood() != true)
			setDefinitionGood(false);
		else
			setDefinitionGood(true);
	}
	else
	{
		cout << "\nError " << FRED(":") << " Reserved Character \n" << FRED("Reason:") << " Reserved Character \\ found in " << type << "!" << endl;
		//cout << "\t   (" << FRED("Reason:") << ")iew\tView Turing machine" << endl;

		setDefinitionGood(false);
	}
	//Check for reserved character [
	if(alphabet.find("[") == string::npos)
	{
		if(getDefinitionGood() != true)
			setDefinitionGood(false);
		else
			setDefinitionGood(true);
	}
	else
	{
		cout << "\nError " << FRED(":") << " Reserved Character \n" << FRED("Reason:") << " Reserved Character [ found in " << type << "!" << endl;
		setDefinitionGood(false);
	}

	//Check for reserved character ]
	if(alphabet.find("]") == string::npos)
	{
		if(getDefinitionGood() != true)
			setDefinitionGood(false);
		else
			setDefinitionGood(true);
	}
	else
	{
		cout << "\nError " << FRED(":") << " Reserved Character \n" << FRED("Reason:") << " Reserved Character ] found in " << type << "!" << endl;
		setDefinitionGood(false);
	}

	//Check for reserved character <
	if(alphabet.find("<") == string::npos)
	{
		if(getDefinitionGood() != true)
			setDefinitionGood(false);
		else
			setDefinitionGood(true);
	}
	else
	{
		cout << "\nError " << FRED(":") << " Reserved Character \n" << FRED("Reason:") << " Reserved Character < found in " << type << "!" << endl;
		setDefinitionGood(false);
	}

	//Check for reserved character >
	if(alphabet.find(">") == string::npos)
	{
		if(getDefinitionGood() != true)
			setDefinitionGood(false);
		else
			setDefinitionGood(true);
	}
	else
	{
		cout << "\nError " << FRED(":") << " Reserved Character \n" << FRED("Reason:") << " Reserved Character > found in " << type << "!" << endl;
		setDefinitionGood(false);
	}

	//Check for non printable characters
	if((alphabet[0] >= '!') || (alphabet[0] <= '~'))
	{
		if(getDefinitionGood() != true)
			setDefinitionGood(false);
		else
			setDefinitionGood(true);
	}
	else
	{
		cout << "\nError " << FRED(":") << " Non Printable \n" << FRED("Reason:") << " Non Printable Character found in " << type << "!" << endl;
		setDefinitionGood(false);
	}


}

//This function will validate the new user input string
bool FileParser::validate(string newInputString) const
{
	string tempString = newInputString;
	string temp_Tape_Alphabet = getTapeAlphabet();

	for(int index = 0; index < newInputString.length(); index++)
	{
		if(temp_Tape_Alphabet.find(newInputString[index]) == string::npos)
		{
			cout << "Erroneous String!" << endl;
			return false;
		}
		else
			continue;
	}
	return true;
}

//This function will check if the users new input string is a duplicate string 
bool FileParser::duplicateString(vector<string> list, string newInputString) const
{
	
	for(unsigned int index = 0; index < list.size(); index++)
	{
		//Debug 
		//cout << list[index].length() << endl <<'"' << list[index] << '"' << endl;
		if(list[index] == newInputString)
		{
			cout << "Duplicate input string!" << endl;
			return false;
		}
	}

	return true;
}

//This function will validate the File by making sure each category corresponds to the appropriate
//sub-category 
void FileParser::validateFile()
{
	string states = getStates();
	string input_alphabet = getInputAlphabet();
	string tape_alphabet = getTapeAlphabet();
	string transition = getTransition();
	string initial_state = getInitialState();
	string blank_symbol = getBlankCharacter();
	string final_state = getFinalState();

	//Check if input_alphabet has a reserve character
	checkReservedChar(input_alphabet, "alphabet");
	//Check if tape_alphabet has a reserve character
	checkReservedChar(tape_alphabet, "alphabet");
	//Check if blank_symbol is a reserve character
	//checkReservedChar(blank_symbol, "blank_character");

	//Check if initial_state is in finite set of states and there is only one initial state
	int error = 0;
	string temp1 = initial_state;
	string temp2;
	stringstream sso(temp1);	
	while(sso >> temp2)
	{
		error++;
		if(error > 1)
		{
			cout << "\nError " << FRED(":") << " In Initial_State \n" << FRED("Reason:") << " There can only be one initial state." << endl;
			setDefinitionGood(false);	
		}	
		if(states.find(temp2) != string::npos)
		{
			if(getDefinitionGood() != true)
				setDefinitionGood(false);
			else
				setDefinitionGood(true);
		}
		else
		{
			cout << "\nError " << FRED(":") << " In Initial_State \n" << FRED("Reason:") << " " << temp2 << " is not in the finite set of states." << endl;
			setDefinitionGood(false);
		}
	}


	//Check if final_state is in finite set of states
	temp1 = "";
	temp1 = final_state;
	temp2 = "";
	sso.str("");
	sso.clear();
	sso << temp1;
	while(sso >> temp2)
	{
		if(states.find(temp2) != string::npos)
		{
			if(getDefinitionGood() != true)
				setDefinitionGood(false);
			else
				setDefinitionGood(true);
		}
		else
		{
			cout << "\nError " << FRED(":") << " In Final_State \n" << FRED("Reason:") << " " << temp2 << " is not in the finite set of states." << endl;
			setDefinitionGood(false);
		}	
	}

	//Check if blank_symbol is in tape_alphabet
	if(tape_alphabet.find(blank_symbol) != string::npos)
	{
		if(getDefinitionGood() != true)
			setDefinitionGood(false);
		else
			setDefinitionGood(true);
	}
	else
	{
		//Check if blank_symbol is a reserve character
		checkReservedChar(blank_symbol, "blank_character");
		cout << "\nError " << FRED(":") << " In Blank_Character \n" << FRED("Reason:") << blank_symbol << " is not in the finite tape alphabet." << endl;
		setDefinitionGood(false);
	}

	//Check if blank_symbol is not in input_alphabet
	if(input_alphabet.find(blank_symbol) == string::npos)
	{
		if(getDefinitionGood() != true)
			setDefinitionGood(false);
		else
			setDefinitionGood(true);
	}
	else
	{
		//Check if blank_symbol is a reserve character
		checkReservedChar(blank_symbol, "blank_character");
		cout << "\nError " << FRED(":") << " In Input_Alphabet \n" << FRED("Reason:") << " Blank_Character" <<blank_symbol << " is in the finite input alphabet." << endl;
		setDefinitionGood(false);
	}

	//Check if every character in input alphabet is in tape alphabet
	temp1 = "";
	temp1 = input_alphabet;
	temp2 = "";
	sso.str("");
	sso.clear();
	sso << temp1;
	while(sso >> temp2)
	{
		if(tape_alphabet.find(temp2) != string::npos)
		{
			if(getDefinitionGood() != true)
				setDefinitionGood(false);
			else
				setDefinitionGood(true);
		}
		else
		{
			cout << "\nError " << FRED(":") << " In Input_Alphabet \n" << FRED("Reason:") << " " << temp2 << " is not in the finite tape alphabet." << endl;
			setDefinitionGood(false);
		}		
	}

	//////////////////////
	//Check transitions//
	////////////////////
	temp1 = "";
	temp1 = getTransition();
	temp2 = "";
	sso.str("");
	sso.clear();
	sso << temp1;
	int counter = 0;
	int total_transitions = 1;

	while(sso >> temp2)
	{

		if(counter == 0)
		{
			//cout << "Checking valid state"  << counter << endl;
			if(states.find(temp2) != string::npos)
			{
				if(getDefinitionGood() != true)
				{
					setDefinitionGood(false);
					counter++;
				}
				else
				{
					setDefinitionGood(true);
					counter++;
				}
			}
			else
			{
				cout << "\nError " << FRED(":") << " In Transition " << total_transitions <<  ": \n" << FRED("Reason:") << " " << temp2 << " is not a valid source state." << endl;
				setDefinitionGood(false);
				counter++;
			}
		}
		else if(counter == 1)
		{
			checkReservedChar(temp2, "transition");
			//cout << "Checking for valid read characer" << counter << endl;
			if(tape_alphabet.find(temp2) != string::npos)
			{
				if(getDefinitionGood() != true)
				{
					setDefinitionGood(false);
					counter++;
				}
				else
				{
					setDefinitionGood(true);
					counter++;
				}
			}
			else
			{
				cout << "\nError " << FRED(":") << " In Transition " << total_transitions <<  ": \n" << FRED("Reason:") << " " << temp2 << " is not a valid read character." << endl;
				setDefinitionGood(false);
				counter++;
			}
		}
		else if(counter == 2)
		{
			//cout << "Checking valid destination state" << counter << endl;
			if(states.find(temp2) != string::npos)
			{
				if(getDefinitionGood() != true)
				{
					setDefinitionGood(false);
					counter++;
				}
				else
				{
					setDefinitionGood(true);
					counter++;
				}
			}
			else
			{
				cout << "\nError " << FRED(":") << " In Transition " << total_transitions <<  ": \n" << FRED("Reason:") << " " << temp2 << " is not a valid destination state." << endl;
				setDefinitionGood(false);
				counter++;
			}
		}
		else if(counter == 3)
		{
			checkReservedChar(temp2, "transition");
			//cout << "Checking for valid write character" << counter << endl;
			if(tape_alphabet.find(temp2) != string::npos)
			{
				if(getDefinitionGood() != true)
				{
					setDefinitionGood(false);
					counter++;
				}
				else
				{
					setDefinitionGood(true);
					counter++;
				}
			}
			else
			{
				cout << "\nError " << FRED(":") << " In Transition " << total_transitions <<  ": \n" << FRED("Reason:") << " " << temp2 << " is not a valid write character." << endl;
				setDefinitionGood(false);
				counter++;
			}			
		}
		else if(counter == 4)
		{
			checkReservedChar(temp2, "transition");
			//cout << "Check for valid direction" << counter << endl;
			if(temp2 == "r" || temp2 == "R" || temp2 == "l" || temp2 == "L")
			{
				if(getDefinitionGood() != true)
				{
					setDefinitionGood(false);
					counter = 0;
					total_transitions++;
				}
				else
				{
					setDefinitionGood(true);
					counter = 0;
					total_transitions++;
				}
			}
			else
			{
				cout << "\nError " << FRED(":") << " In Transition " << total_transitions <<  ": \n" << FRED("Reason:") << " " << temp2 << " is not a valid move direction." << endl;
				setDefinitionGood(false);
				counter = 0;
				total_transitions++;
			}			
		}

	}
}

void FileParser::displayDefinition() const
{
	//Print Description
	cout << endl << getDescription() << endl << endl;

	//Print States
	string temp1 = getStates();
	string temp2;
	stringstream sso(temp1);

	cout << "Q = {";

	while(sso >> temp2)
		cout << temp2 << ", ";

	cout << "\b\b}" << endl << endl;

	//Print Input_Alphabet
	temp1 = "";
	temp1 = getInputAlphabet();
	temp2 = "";
	sso.str("");
	sso.clear();
	sso << temp1;

	cout << "\u03A3 = {";

	while(sso >> temp2)
		cout << temp2 << ", ";
	
	cout << "\b\b}" << endl << endl;

	//Print Tape_Alphabets
	temp1 = "";
	temp1 = getTapeAlphabet();
	temp2 = "";
	sso.str("");
	sso.clear();
	sso << temp1;

	cout << "\u0393 = {";

	while(sso >> temp2)
		cout << temp2 << ", ";

	cout << "\b\b}" << endl << endl;

	//Print Transitions
	temp1 = "";
	temp1 = getTransition();
	temp2 = "";
	sso.str("");
	sso.clear();
	sso << temp1;
	int printNewLine = 0;
	int printSeparater = 0;

	cout << "\u03B4(";
	while(sso >> temp2)
	{
		cout << temp2 << ", ";
		printNewLine++;
		printSeparater++;
		if(printSeparater == 2)
			cout << "\b\b) = (";

		if(printNewLine % 5 == 0)
		{
			printSeparater = 0;
			cout << "\b\b)" << endl << "\u03B4(";
		}
	}
	cout << "\b\b\b\b    " << endl;

	//Print Initial State
	temp1 = "";
	temp1 = getInitialState();
	temp2 = "";
	sso.str("");
	sso.clear();
	sso << temp1;

	cout << "q! = ";

	while(sso >> temp2)
		cout << temp2;

	cout << endl << endl;

	//Print Blank Character
	temp1 = "";
	temp1 = getBlankCharacter();
	temp2 = "";
	sso.str("");
	sso.clear();
	sso << temp1;

	cout << "B = ";

	while(sso >> temp2)
		cout << temp2;

	cout << endl << endl;

	//Print Final States
	temp1 = "";
	temp1 = getFinalState();
	temp2 = "";
	sso.str("");
	sso.clear();
	sso << temp1;

	cout << "F = {";

	while(sso >> temp2)
		cout << temp2 << ", ";

	cout << "\b\b}" << endl << endl;
}



///////Start of Getters and Setters/////////////
string FileParser::getInitialState() const
{
	return initialState;
}

void FileParser::setInitialState(string initialState) 
{
	this->initialState = initialState;
}

string FileParser::getStates() const
{
	return states;
}

void FileParser::setStates(string states) 
{
	this->states = states;
}

void FileParser::setDescription(string description)
{
	this->description = description;
}

string FileParser::getDescription() const
{
	return description;
}

void FileParser::setInputAlphabet(string inputAlphabet)
{
	this->inputAlphabet = inputAlphabet;
}

string FileParser::getInputAlphabet() const
{
	return inputAlphabet;
}

void FileParser::setTapeAlphabet(string tapeAlphabet)
{
	this->tapeAlphabet = tapeAlphabet;
}

string FileParser::getTapeAlphabet() const
{
	return tapeAlphabet;
}

void FileParser::setTransition(string transition)
{
	this->transition = transition;
}

string FileParser::getTransition() const
{
	return transition;
}

void FileParser::setBlankCharacter(string blankCharacter)
{
	this->blankCharacter = blankCharacter;
}

string FileParser::getBlankCharacter() const
{
	return blankCharacter;
}

void FileParser::setFinalState(string finalState)
{
	this->finalState = finalState;
}

string FileParser::getFinalState() const
{
	return finalState;
}

bool FileParser::getDescriptionFound() const
{
	return descriptionFound;
}

void FileParser::setDescriptionFound(bool descriptionFound) 
{
	this->descriptionFound = descriptionFound;
}

bool FileParser::getStatesFound() const
{
	return statesFound;
}

void FileParser::setStatesFound(bool statesFound) 
{
	this->statesFound = statesFound;
}

bool FileParser::getInputAlphabetFound() const
{
	return inputAlphabetFound;
}

void FileParser::setInputAlphabetFound(bool inputAlphabetFound) 
{
	this->inputAlphabetFound = inputAlphabetFound;
}

bool FileParser::getTapeAlphabetFound() const
{
	return tapeAlphabetFound;
}

void FileParser::setTapeAlphabetFound(bool tapeAlphabetFound) 
{
	this->tapeAlphabetFound = tapeAlphabetFound;
}

bool FileParser::getTransitionFound() const
{
	return transitionFound;
}

void FileParser::setTransitionFound(bool transitionFound) 
{
	this->transitionFound = transitionFound;
}

bool FileParser::getInitialStateFound() const
{
	return initialStateFound;
}

void FileParser::setInitialStateFound(bool initialStateFound) 
{
	this->initialStateFound = initialStateFound;
}

bool FileParser::getBlankCharacterFound() const
{
	return blankCharacterFound;
}

void FileParser::setBlankCharacterFound(bool blankCharacterFound) 
{
	this->blankCharacterFound = blankCharacterFound;
}

bool FileParser::getFinalStateFound() const
{
	return finalStateFound;
}

void FileParser::setFinalStateFound(bool finalStateFound) 
{
	this->finalStateFound = finalStateFound;
}

bool FileParser::getDefinitionGood() const
{
	return definitionGood;
}

void FileParser::setDefinitionGood(bool definitionGood) 
{
	this->definitionGood = definitionGood;
}

///////End of Getters and Setters/////////////

/* Test Functions 
FileParser* FileParser::parseDescription(FileParser *Parser, string currentWord)
{
	string wordToParse = currentWord;
	string temp;

	temp = wordToParse;

	if(Parser->descriptionFound == false)
	{
		
		for(int i = 0; i < temp.size(); i++)
		{
			temp[i] = toupper(temp[i]);
		}

		if(temp == "STATES:")
		{
			Parser->descriptionFound = true;
			return Parser;
		}
		else
		{
			  string temp2 = getDescription() + " " + wordToParse;
			  setDescription(temp2);
		}
	}

	return Parser;
}

FileParser* FileParser::parseStates(FileParser *Parser, string currentWord)
{
	string wordToParse = currentWord;
	string temp;

	temp = wordToParse;

	if(Parser->statesFound == false)
	{
		
		for(int i = 0; i < temp.size(); i++)
		{
			temp[i] = toupper(temp[i]);
		}

		if(temp == "INPUT_ALPHABET:")
		{
			Parser->statesFound = true;
			return Parser;
		}
		else
		{
			  string temp2 = getStates() + " " + wordToParse;
			  setStates(temp2);
		}
	}
	return Parser;
}

FileParser* FileParser::parseInputAlphabet(FileParser *Parser, string currentWord)
{
	string wordToParse = currentWord;
	string temp;

	temp = wordToParse;

	if(Parser->inputAlphabetFound == false)
	{
		
		for(int i = 0; i < temp.size(); i++)
		{
			temp[i] = toupper(temp[i]);
		}

		if(temp == "TAPE_ALPHABET:")
		{
			Parser->inputAlphabetFound = true;
			return Parser;
		}
		else
		{
			  string temp2 = getInputAlphabet() + " " + wordToParse;
			  setInputAlphabet(temp2);
		}
	}
	return Parser;
}

FileParser* FileParser::parseTapeAlphabet(FileParser *Parser, string currentWord)
{
	string wordToParse = currentWord;
	string temp;

	temp = wordToParse;

	if(Parser->tapeAlphabetFound == false)
	{
		
		for(int i = 0; i < temp.size(); i++)
		{
			temp[i] = toupper(temp[i]);
		}

		if(temp == "TRANSITION_FUNCTION:")
		{
			Parser->tapeAlphabetFound = true;
			return Parser;
		}
		else
		{
			  string temp2 = getTapeAlphabet() + " " + wordToParse;
			  setTapeAlphabet(temp2);
		}
	}
	return Parser;
}

FileParser* FileParser::parseTransitions(FileParser *Parser, string currentWord)
{
	string wordToParse = currentWord;
	string temp;

	temp = wordToParse;

	if(Parser->transitionFound == false)
	{
		
		for(int i = 0; i < temp.size(); i++)
		{
			temp[i] = toupper(temp[i]);
		}

		if(temp == "INITIAL_STATE:")
		{
			Parser->transitionFound = true;
			return Parser;
		}
		else
		{
			  string temp2 = getTransition() + " " + wordToParse;
			  setTransition(temp2);
		}
	}
	return Parser;
}

FileParser* FileParser::parseInitialState(FileParser *Parser, string currentWord)
{
	string wordToParse = currentWord;
	string temp;

	temp = wordToParse;

	if(Parser->initialStateFound == false)
	{
		
		for(int i = 0; i < temp.size(); i++)
		{
			temp[i] = toupper(temp[i]);
		}

		if(temp == "BLANK_CHARACTER:")
		{
			Parser->initialStateFound = true;
			return Parser;
		}
		else
		{
			  string temp2 = getInitialState() + " " + wordToParse;
			  setInitialState(temp2);
		}
	}
	return Parser;
}

FileParser* FileParser::parseBlankCharacterFound(FileParser *Parser, string currentWord)
{
	string wordToParse = currentWord;
	string temp;

	temp = wordToParse;

	if(Parser->blankCharacterFound == false)
	{
		
		for(int i = 0; i < temp.size(); i++)
		{
			temp[i] = toupper(temp[i]);
		}

		if(temp == "FINAL_STATES:")
		{
			Parser->blankCharacterFound = true;
			return Parser;
		}
		else
		{
			  string temp2 = getBlankCharacter() + " " + wordToParse;
			  setBlankCharacter(temp2);
		}
	}
	return Parser;
}

FileParser* FileParser::parseFinalState(FileParser *Parser, string currentWord)
{
	string wordToParse = currentWord;
	string temp;

	temp = wordToParse;

	if(Parser->finalStateFound == false)
	{
		
		for(int i = 0; i < temp.size(); i++)
		{
			temp[i] = toupper(temp[i]);
		}

		if(temp == "FINAL_STATES:")
		{
			Parser->finalStateFound = true;
			return Parser;
		}
		else
		{
			  string temp2 = getFinalState() + " " + wordToParse;
			  setFinalState(temp2);
		}
	}
	return Parser;
}
*/

