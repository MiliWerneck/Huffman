#include "huffman.hpp"
#include "tree.hpp"

void contaFreq();
void operHuffman(vector <Tree *> *f_init, vector <Tree *> *f_reduz, Tree *raiz);

int main() {
	//int reg[] = { 5,3,7,2,4,6 };
	// char reg[] = { 'A','B','C','D','E','F' };
	string reg[] = { "A","B","C","D", "E" ,"F" };
	float valor[] = { 0.08, 0.10, 0.12, 0.15, 0.20, 0.35 };

	vector <Tree *> f_init;
	vector <Tree *> f_reduz;

	Tree *raiz = CreateTree();
	// Tree *floresta_aux[6];
	Tree *aux1 = CreateTree();
	Tree *aux2 = CreateTree();
	Tree *raiz_final = CreateTree();
	Record r;

	for (int i = 0; i < 6; i++) {
		r.key = reg[i];
		r.value = valor[i];
		raiz = CreateTree();
		insertTree(&raiz, r);
		f_init.push_back(raiz);
	}

	insertTreeHuff(&f_init, &raiz_final);
	map<string, string> mapa;
	map<string, string> ::iterator it;
	posordem(raiz_final, &mapa, "", "");

	for (it = mapa.begin(); it != mapa.end(); ++it) {
		cout << it->first << endl;
		cout << it->second << endl;
	}

	return 0;
}

void contaFreq() {
	// string str = "A casa do rei eh azul";
	string str = "ABCAA";
	map <char, float> frequencia;
	map <char, float> ::iterator itr;
	char c;

	for (unsigned int i = 0; i < str.length(); i++) {
		c = str[i];
		itr = frequencia.find(c);
		if (itr != end(frequencia)) {
			itr->second++;
		} else {
			frequencia.insert({ c, 1 });
		}
	}

	int max = 0, min = 0;
	int cont = 0, quant = 0;
	int comprimento = 0;

	for (itr = frequencia.begin(); itr != frequencia.end();++itr) {
		quant += itr->second;
		if (cont == 0) {
			max = itr->second;
			min = itr->second;
			cont++;
		}
		max = (max < itr->second) ? itr->second : max;
		min = (itr->second < min) ? itr->second : min;
	}

	for (itr = frequencia.begin(); itr != frequencia.end();++itr) {
		itr->second = itr->second / quant;

	}

	for (itr = frequencia.begin(); itr != frequencia.end();++itr) {
		cout << itr->first << " " << itr->second << endl;
	}
}