/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: Make the empty string printable
*/

#include <string>
#include "Visible.h"

using namespace std;

string visible(string value)
{
	const string lamda("\\");

	if(value.empty())
	{
		value = lamda;
	}
	return value;
}