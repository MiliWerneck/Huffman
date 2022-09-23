#ifndef READ_HPP
#define READ_HPP

#include "util.hpp"
#include <fstream>


class Read {
private:
public:
	Read();
	~Read();
	void readFile(map <string, float> *frequencia, vector<string> *str);
	void saveFile(map <string, string> conversao, vector<string> *str);
};

Read::Read() {}
Read::~Read() {}

void Read::readFile(map <string, float> *frequencia, vector<string> *str) {

	ifstream myfile("src/files/huff.txt");
	string line;

	Util u;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			u.tokenizar(line, frequencia, str);
		}
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}

void Read::saveFile(map <string, string> conversao, vector<string> *str) {

	map<string, string> ::iterator it;
	ofstream out("src/files/saida.txt");

	if (out.is_open()) {
		for (auto sai : *str) {
			it = conversao.find(sai);
			if (it != conversao.end()) {
				out << it->second;
			}
		}
		out.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}

#endif