/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class holds the characters of the input string alphabet
*/

#ifndef _INPUT_ALPHABET_
#define _INPUT_ALPHABET_

#include <vector>

using namespace std;

class Input_Alphabet
{
	private:
		//The attribute alphabet will be used to store the input alphabet.
		vector<char> alphabet;
		
	public:
		Input_Alphabet();
		~Input_Alphabet();
		void load(string alph);
		bool is_element(char value);
};

#endif /* _INPUT_ALPHABET_ */