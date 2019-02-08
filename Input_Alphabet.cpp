/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class holds the characters of the input string alphabet
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>

#include "Direction.h"
#include "Input_Alphabet.h"

using namespace std;

Input_Alphabet::Input_Alphabet()
{

}

Input_Alphabet::~Input_Alphabet()
{

}

//The method load will load the input alphabet into the attribute alphabet.
void Input_Alphabet::load(string alph)
{
	string temp1 = alph;
	string temp2;
	stringstream sso(temp1);
	
	while(sso >> temp2)
	{
		alphabet.push_back(temp2[0]);
	}

	/*
	//debug display to screen to make sure Input_Alphabet was loaded into attribute alphabet
	cout << "Input_Alphabet: ";
	for(unsigned int index = 0; index < alphabet.size(); index++)
	{
		cout << alphabet[index] << " ";
	}
	cout << endl;*/
}

//The method is_element checks if the passed in value is contained within the attribute alphabet.
//This method might not be needed in my current design
bool Input_Alphabet::is_element(char value)
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