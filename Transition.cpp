/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This file stores the methods to the class Transition.
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>


#include "Direction.h"
#include "Transition.h"

using namespace std;


//The method Transition is the constructor for the Transition class taking the parameters of the
//source_state, read_character, destination_state, write_character, and move_direction.
Transition::Transition(string source_state, char read_character, string destination_state,
			char write_character, Direction move_direction):
			source(source_state), read(read_character), destination(destination_state),
			write(write_character), move(move_direction)
{

}

Transition::~Transition()
{

}

//The method source_state is used to get the current value stored in the source attribute.
string Transition::source_state() const
{
	return source;
}

//The method read_character is used to get the current value stored in the read attribute.
char Transition::read_character() const
{
	return read;
}

//The method destination_state is used to get the current value stored in the destination attribute.
string Transition::destination_state() const
{
	return destination;
}

//The method write_character is used to get the current value stored in the write attribute.
char Transition::write_character() const
{
	return write;
}

//The method move_direction is used to get the current value stored in the move attribute.
Direction Transition::move_direction() const
{
	return move;
}