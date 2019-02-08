#ifndef _COMMANDS_H_
#define _COMMANDS_H_

#include <string>
#include <vector>
#include "FileParser.h"
#include "Turing_Machine.h"

using namespace std;


void help_command();

void delete_command(vector<string>& input_strings);

void insert_command(vector<string>& input_strings, FileParser *Parser);

void list_command(vector<string>& input_strings);

int exit_command(ofstream& string_file, vector<string>& input_strings);

void quit_command(Turing_Machine& Turing_Machine);

void set_command(int& max_transitions);

void truncate_command(int& maxCells);

void show_command(Turing_Machine Turing_Machine, string current_used_input, int maxTransitions, int maxCells, string def);

void run_command(Turing_Machine& Turing_Machine, string& current_used_input, vector<string>& input_strings, int& maxTransitions, int& maxCells);

#endif /* _COMMANDS_H_ */