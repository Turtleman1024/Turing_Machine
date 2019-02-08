/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This file stores the methods for the class states that the turing machine can be in at any given time
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>

#include "States.h"

using namespace std;

States::States()
{

}

States::~States()
{

}

//The method load will load the states into the attribute name.
void States::load(string states)
{
	string temp1 = states;
	string temp2;
	stringstream sso(temp1);
	while(sso >> temp2)
	{
		//cout << "States length: " << temp2 << ":" << temp2.length() << endl;
		name.push_back(temp2);
	}

	/*
	//debug display to screen to make sure states where loaded into attribute name
	cout << "States: ";
	for(unsigned int index = 0; index < name.size(); index++)
	{
		cout << name[index] << ":" << name[index].length() << " ";
	}
	cout << endl;*/
}

//The method is_element checks if the passed in value is contained within the attribute names.
bool States::is_element(string value)
{
	for(unsigned int index = 0; index < name.size(); index++)
	{
		if(name[index] == value)
			return true;
	}
	return false;
}