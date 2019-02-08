/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class holds the characters that can 
*			   be written to the tape cells in the Tape class.
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>

#include "Direction.h"
#include "Tape_Alphabet.h"

using namespace std;

Tape_Alphabet::Tape_Alphabet()
{

}

Tape_Alphabet::~Tape_Alphabet()
{

}

//The method load will load the tape alphabet into the attribute alphabet.
void Tape_Alphabet::load(string alph)
{
	string temp1 = alph;
	string temp2;
	stringstream sso(temp1);
	
	while(sso >> temp2)
	{
		alphabet.push_back(temp2[0]);
	}
	
	/*
	//debug display to screen to make sure Tape_Alphabet was loaded into attribute alphabet
	cout << "Tape_Alphabet: ";
	for(unsigned int index = 0; index < alphabet.size(); index++)
	{
		cout << alphabet[index] << " ";
	}
	cout << endl;*/
}

//The method is_element checks if the passed in value is contained within the attribute alphabet.
//This method might not be needed in my current design
bool Tape_Alphabet::is_element(char value)
{
	for(unsigned int index = 0; index < alphabet.size(); index++)
	{
		if(alphabet[index] == value)
		{
			return true;
		}
	}
	return false;
}