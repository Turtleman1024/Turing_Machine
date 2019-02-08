/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class holds the characters that can 
*			   be written to the tape cells in the Tape class
*/

#ifndef _TAPE_ALPHABET_
#define _TAPE_ALPHABET_

#include <vector>

using namespace std;

class Tape_Alphabet
{
	private:
		//The attribute alphabet will be used to store the tape alphabet characters.
		vector<char> alphabet;
		
	public:
		Tape_Alphabet();
		~Tape_Alphabet();
		void load(string alph);
		bool is_element(char value);
};

#endif /* _TAPE_ALPHABET_ */

