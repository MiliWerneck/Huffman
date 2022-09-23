#ifndef UTIL_HPP
#define UTIL_HPP

#include <sstream>
#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Util {

public:
	Util();
	~Util();

	void tokenizar(string text, map <string, float> *frequencia, vector<string> *str);
};

Util::Util() {}
Util::~Util() {}

void Util::tokenizar(string text, map <string, float> *frequencia, vector<string> *str) {
	char del = ' ';
	stringstream sstream(text);
	string token;
	map <string, float> ::iterator itr;

	while (getline(sstream, token, del)) {
		itr = frequencia->find(token);
		if (itr != frequencia->end()) {
			itr->second++;
		} else {
			frequencia->insert({ token, 1 });
		}
		str->push_back(token);
	}
}

#endif