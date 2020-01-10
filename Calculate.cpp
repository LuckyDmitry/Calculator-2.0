#include "Calculate.h"

double Calculate::get_result(vector<Lexema>& lex){

	vector<Lexema> digits;

	for (auto i = 0; i !=lex.size(); ++i){
		if (lex[i].get_type() == type_lexema::statement) {
			double d = digits.back().get_value(); digits.pop_back();
			double m = digits.back().get_value(); digits.pop_back();

			switch (lex[i].get_statement()){
			case '+': digits.push_back(Lexema(type_lexema::digit,d+m)); break;
			case '-': digits.push_back(Lexema(type_lexema::digit, m -d )); break;
			case '*': digits.push_back(Lexema(type_lexema::digit, d * m)); break;
			case '/':
				if (m == 0) {
					cout << "devide by zero";
					exit(0);
				}
				digits.push_back(Lexema(type_lexema::digit,  m / d)); break;
			}
			}else {
			digits.push_back(Lexema(type_lexema::digit, lex[i].get_value()));
		}
		}
	return digits.back().get_value();
	}

