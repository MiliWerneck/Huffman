#ifndef RUFFMAN_HPP
#define RUFMANN_HPP

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct double_endl_impl {} endl2;

std::ostream &operator<<(std::ostream &out, double_endl_impl) {
	return out << "\n\n" << std::flush;
}

// typedef struct dimen dimen;
// struct dimen {
// 	int l1;
// 	int l2;
// 	int c1;
// 	int c2;
// };

class Util {
private:
	map<string, vector<vector<int>>> mapa2;
	map<string, vector<vector<int>>> ::iterator itr;
public:
	Util();
	~Util();

	void tokenizar(string text, int **matriz, int linha);
	void imprimeMatriz(int **matriz, int linha, int coluna);
};

Util::Util() {}
Util::~Util() {}

void Util::tokenizar(string text, int **matriz, int linha) {
	char del = ',';
	int coluna = 0;
	stringstream sstream(text);
	string token;

	while (getline(sstream, token, del)) {
		matriz[linha][coluna++] = stoi(token);
	}
}


void Util::imprimeMatriz(int **matriz, int linha, int coluna) {
	for (int i = 0; i < linha; i++) {
		for (int j = 0;j < coluna; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}



#endif