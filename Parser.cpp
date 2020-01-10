#include "Parser.h"

string Parser::get_reverse_polish_entry(const string& input) {

	vector<char> stack_of_symbols;
	string output;
	for (size_t i = 0; i != input.length(); ++i) {
		if (isdigit(input[i])) {
			output += input[i];
			continue;
		}
		output += '_';

		if (input[i] == '-' && isdigit(input[i + 1]) && i == 0) {
			while (isdigit(input[i + 1])) {
				output += input[i + 1];
				i++;
			}
			output += '-';
		}
		if (input[i] == '-' && i != 0 && is_check_priority(input[i - 1]) == 2 && isdigit(input[i + 1])) {
			while (isdigit(input[i + 1])) {
				output += input[i + 1];
				i++;
			}
			output += '-';
			i++;

		}
		if (is_check_operator(input[i])) {


			if (stack_of_symbols.empty() || is_check_priority(stack_of_symbols.back()) < is_check_priority(input[i])) {
				stack_of_symbols.push_back(input[i]);
			}

			else {
				if (!stack_of_symbols.empty() && is_check_priority(stack_of_symbols.back()) >= (is_check_priority(input[i]))) {
					output += stack_of_symbols.back();
					stack_of_symbols.pop_back();
				}
				stack_of_symbols.push_back(input[i]);
			}
		}
	}
	while (!stack_of_symbols.empty()) {
		output += stack_of_symbols.back();
		stack_of_symbols.pop_back();
	}
	return output;

}

vector<Lexema> Parser::get_lexema(const string& input) {

	vector<Lexema> output;

	for (size_t i = 0; i != input.length(); ++i) {

		if (isdigit(input[i])) {
			string temp;
			while (isdigit(input[i])) {
				temp += input[i];
				i++;
			}
			i--;
			output.push_back(Lexema(type_lexema::digit,atof(temp.c_str())));

		}
		else if (is_check_operator(input[i])) {

			output.push_back(Lexema(type_lexema::statement,input[i]));

		}

	}
	return output;
}

int Parser::is_check_priority(char c) {

	switch (c) {
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}

}

bool Parser::is_check_operator(char c) {

	return c == '+' || c == '/' || c == '*' || c == '-';

}
