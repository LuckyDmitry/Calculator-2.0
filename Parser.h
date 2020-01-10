#pragma once
#include "define.h"
#include "Lexemar.h"

class Parser
{
public:

	string get_reverse_polish_entry(const string&);
	vector<Lexema> get_lexema(const string&);

private:

	int is_check_priority(char);
	bool is_check_operator(char);

};

