#pragma once
#include "define.h"

enum type_lexema
{
	digit , statement
};

class Lexema
{
public:
	Lexema(type_lexema,char );
	Lexema(type_lexema,double);
	Lexema() {}
	double get_value();
	char get_statement();
	type_lexema get_type();


	~Lexema();

private:
	type_lexema type;
	double value = NULL;
	char symbol = NULL;
	void set_value(double);
	void set_statement(char);
	friend ostream& operator<<(ostream& out, const Lexema& Lex);
};
