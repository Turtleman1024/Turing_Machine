/*
*	Author: Kenneth Murry
*	CptS 322 
*	Objective: This class perform validation of the Turing machine by parsing of the definition file
*/


#ifndef _DEFINITION_PARSER_
#define _DEFINITION_PARSER_

#include <vector>

using namespace std;

class FileParser
{
	private: 

		string description;
		string states;
		string inputAlphabet;
		string tapeAlphabet;
		string transition;
		string initialState;
		string blankCharacter;
		string finalState;
		bool descriptionFound;
		bool statesFound;
		bool inputAlphabetFound;
		bool tapeAlphabetFound;
		bool transitionFound;
		bool initialStateFound;
		bool blankCharacterFound;
		bool finalStateFound;
		bool definitionGood;

	public:

		
		FileParser();
		~FileParser();
		void displayDefinition() const;
		FileParser* parseDefinitionFile(FileParser *Parser, string currentWord);
		void validateFile();
		bool validate(string newInputString) const;
		void checkReservedChar(string alphabet, string type);
		bool duplicateString(vector<string> list, string newinputString) const;


		void setDescription(string description);
		string getDescription() const;

		void setInputAlphabet(string inputAlphabet);
		string getInputAlphabet() const;

		void setTapeAlphabet(string tapeAlphabet);
		string getTapeAlphabet() const;

		void setTransition(string transition);
		string getTransition() const;

		void setBlankCharacter(string blankCharacter);
		string getBlankCharacter() const;

		void setFinalState(string finalState);
		string getFinalState() const;

		string getStates() const;
		void setStates(string states);

		string getInitialState() const;
		void setInitialState(string initialState);

		bool getDescriptionFound() const;
		void setDescriptionFound(bool descriptionFound);

		bool getStatesFound() const;
		void setStatesFound(bool statesFound);

		bool getInputAlphabetFound() const;
		void setInputAlphabetFound(bool inputAlphabetFound);

		bool getTapeAlphabetFound() const;
		void setTapeAlphabetFound(bool tapeAlphabetFound);

		bool getTransitionFound() const;
		void setTransitionFound(bool transitionFound);

		bool getInitialStateFound() const;
		void setInitialStateFound(bool initialStateFound);

		bool getBlankCharacterFound() const;
		void setBlankCharacterFound(bool blankCharacterFound);

		bool getFinalStateFound() const;
		void setFinalStateFound(bool finalStateFound);
		
		bool getDefinitionGood() const;
		void setDefinitionGood(bool definitionGood);


		
		/* Test Functions
		FileParser* parseDescription(FileParser *Parser, string currentLine);
		FileParser* parseStates(FileParser *Parser, string currentWord);
		FileParser* parseInputAlphabet(FileParser *Parser, string currentWord);
		FileParser* parseTapeAlphabet(FileParser *Parser, string currentWord);
		FileParser* parseTransitions(FileParser *Parser, string currentWord);
		FileParser* parseInitialState(FileParser *Parser, string currentWord);
		FileParser* parseBlankCharacterFound(FileParser *Parser, string currentWord);
		FileParser* parseFinalState(FileParser *Parser, string currentWord);
		*/


};



#endif  /*_DEFINITION_PARSER_*/