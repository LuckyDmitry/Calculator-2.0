#include "Parser.h"
#include "Lexemar.h"
#include "define.h"
#include "Calculate.h"


int main() {
	string initial_string = "2*2+2*2";
	string convert_string;
	Parser parser;
	convert_string = parser.get_reverse_polish_entry(initial_string);
	cout << convert_string << endl;
	vector<Lexema> one;
	one = parser.get_lexema(convert_string);	//out string converted as Lexema
	for (auto& i : one) {
		cout << i << endl;
	}
	Calculate b;
	double result = b.get_result(one);
	cout << endl << endl << result;
}