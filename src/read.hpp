#ifndef READ_HPP
#define READ_HPP

#include "huffman.hpp"

#include <fstream>

class Read {
private:
public:
	Read();
	~Read();
	void readFile(int **huff);
};

Read::Read() {}
Read::~Read() {}

/**
 * @brief realiza a leitura de um arquivo e faz a sua impressao
 *
 * @param file nome do arquivo a ser aberto
 *
 */
void Read::readFile(int **huff) {

	ifstream myfile("src/files/huff.txt");
	string line;

	Util u;

	int contLinha = 0;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			u.tokenizar(line, huff, contLinha++);
		}
		myfile.close();
	} else cout << "Nao foi possivel abrir o arquivo" << endl;
}

#endif