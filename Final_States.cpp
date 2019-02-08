/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This file stores the methods for the class final states in which the turing machine cannot leave.
*			   Input string is accepted and the turing machine operating will be set to false 
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>

#include "Final_States.h"

using namespace std;

Final_States::Final_States()
{

}

Final_States::~Final_States()
{

}

//The method load will load the final states into the attribute name.
void Final_States::load(string final_states)
{
	string temp1 = final_states;
	string temp2;
	stringstream sso(temp1);
	while(sso >> temp2)
	{
		//cout << "Final States length: " << temp2 << ":" << temp2.length() << endl;
		name.push_back(temp2);
	}
	/*
	//debug display to screen to make sure final states where loaded into attribute name
	cout << "Final_States: ";
	for(unsigned int index = 0; index < name.size(); index++)
	{
		cout << name[index] << ":" << name[index].length() << " ";
	}
	cout << endl;*/
}

//The method is_element checks if the passed in value is contained within the attribute names.
bool Final_States::is_element(string value)
{
	for(unsigned int index = 0; index < name.size(); index++)
	{
		if(name[index] == value)
			return true;
	}
	return false;
}