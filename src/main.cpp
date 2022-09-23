#include "read.hpp"
#include "tree.hpp"

void contaFreq(map <string, float> *frequencia, vector<string> *str);
void operHuffman(vector <Tree *> *f_init, vector <Tree *> *f_reduz, Tree *raiz);

int main() {
	map <string, float> frequencia;
	map <string, float> ::iterator itr;

	vector<string> str;
	contaFreq(&frequencia, &str);

	vector <Tree *> f_init;
	vector <Tree *> f_reduz;

	Tree *raiz = CreateTree();
	Tree *raiz_final = CreateTree();
	Record r;

	for (itr = frequencia.begin(); itr != frequencia.end();++itr) {
		r.key = (char *)malloc(sizeof(char) * 20);
		strcpy(r.key, itr->first.c_str());
		r.value = itr->second;
		raiz = CreateTree();
		insertTree(&raiz, r);
		f_init.push_back(raiz);
	}

	insertTreeHuff(&f_init, &raiz_final);
	map<string, string> mapa;

	codifica(raiz_final, &mapa, "", "");
	map<string, string>::iterator it;
	for (it = mapa.begin(); it != mapa.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
	Read rt;

	rt.saveFile(mapa, &str);

	decodeBinary(raiz_final);

	return 0;
}

void contaFreq(map <string, float> *frequencia, vector<string> *str) {
	int quant = 0;

	map <string, float> ::iterator itr;

	Read r;
	r.readFile(frequencia, str);

	for (itr = frequencia->begin(); itr != frequencia->end();++itr)
		quant += itr->second;

	for (itr = frequencia->begin(); itr != frequencia->end();++itr)
		itr->second = itr->second / quant;

	// for (itr = frequencia->begin(); itr != frequencia->end();++itr)
	// 	cout << itr->first << " " << itr->second << endl;

}