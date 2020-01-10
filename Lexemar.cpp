#include "Lexemar.h"

Lexema::Lexema(type_lexema type,char val) {

	this->type = type_lexema::statement;
	this->set_statement(val);
}

Lexema::Lexema(type_lexema type ,double val) {

	this->type = type_lexema::digit;
	this->set_value(val);
}

void Lexema::set_statement(char symbol) {
	this->symbol = symbol;
}

double Lexema::get_value()
{
	return this->value;
}

char Lexema::get_statement()
{
	return this->symbol;
}

type_lexema Lexema::get_type()
{
	return this->type;
}

void Lexema::set_value(double value) {
	this->value = value;
}

Lexema::~Lexema()
{
}

ostream& operator<<(ostream& out, const Lexema& Lex)
{
	out <<"Type: "<<Lex.type <<" Symbol: " << Lex.symbol << " Value: " << Lex.value;
	return out;
}
