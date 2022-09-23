#ifndef READ_HPP
#define READ_HPP

#include "huffman.hpp"
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

/**
 * @brief realiza a leitura de um arquivo e faz a sua impressao
 *
 * @param file nome do arquivo a ser aberto
 *
 */
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
	// string line;
	// Util u;
	// int contLinha = 0;
	// char *pont;
	if (out.is_open()) {
		for (auto sai : *str) {
			// pont = (char *)malloc(sizeof(char) * 20);
			// strcpy(pont, sai.c_str());
			it = conversao.find(sai);
			// cout << sai << endl;;
			if (it != conversao.end()) {
				// cout << "teste" << endl;
				out << it->second;
				// out << " ";
			}
			// cout << sai << endl;
		}
		// while (getline(myfile, line)) {
		// 	u.tokenizar(line, frequencia, str);
		// }
		out.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}

#endif