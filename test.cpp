#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream inFile("tm.def");
	string line;
	vector<string> defFileLines;


	if(inFile.is_open())
	{
		while(getline(inFile,line))
			defFileLines.push_back(line);


		for(unsigned int i = 0; i < defFileLines.size(); ++i)
			cout << defFileLines[i] << endl;

		inFile.close();
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	return 0;
}