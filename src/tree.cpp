#include "tree.hpp"

Tree *CreateTree() {
	return NULL;
}

bool TVazia(Tree **t) {
	return *t == NULL;
}

void insertTree(Tree **t, Record r) {

	if (TVazia(t)) {
		*t = (Tree *)malloc(sizeof(Tree));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg.key = (char *)malloc(sizeof(char) * 20);
		strcpy((*t)->reg.key, r.key);
		(*t)->reg.value = r.value;
	}
}

void decodeBinary(Tree *raiz_final) {
	ifstream myfile("src/files/saida.txt");
	char c;
	Tree *aux;

	aux = CreateTree();

	if (myfile.is_open()) {
		aux = raiz_final;

		while (myfile.get(c)) {
			if (!(aux == NULL)) {
				aux = (c == '0') ? aux->esq : aux->dir;
				if (!(strcmp(aux->reg.key, "#") == 0)) {
					cout << aux->reg.key << " ";
					aux = raiz_final;
				}
			}
		}
		cout << endl;
		myfile.close();
	} else
		cout << "Não foi possível abrir arquivo" << endl;

}

void insertTreeHuff(vector <Tree *> *f_init, Tree **raiz_final) {
	if (f_init->size() == 1) {
		for (auto v : *f_init) {
			*raiz_final = v;
		}
		return;
	}

	Tree *t_menor = CreateTree();
	Tree *t_maior = CreateTree();
	Tree *t = CreateTree();

	vector <Tree *> f_reduz;

	get_first_sec(*f_init, &t_menor, &t_maior);

	if (TVazia(&t)) {
		t = (Tree *)malloc(sizeof(Tree));
		t->esq = t_maior;
		t->dir = t_menor;
		(t)->reg.key = (char *)malloc(sizeof(char) * 20);
		strcpy((t)->reg.key, "#");
		t->reg.value = (t_menor->reg.value + t_maior->reg.value);
	}
	operHuffman(f_init, &f_reduz, t);
	insertTreeHuff(&f_reduz, raiz_final);
}

void get_first_sec(vector <Tree *> f_init, Tree **first, Tree **second) {
	bool controle = false;

	for (auto v : f_init) {
		if (controle) {
			*second = v;
			controle = false;
			return;
		} else {
			*first = v;
			controle = true;
		}
	}
}

void operHuffman(vector <Tree *> *f_init, vector <Tree *> *f_reduz, Tree *raiz) {
	int cont = 1;
	bool aux = true;
	f_reduz->clear();

	for (auto v : *f_init) {
		if (cont++ > 2) {
			if (v->reg.value > raiz->reg.value && aux) {
				f_reduz->push_back(raiz);
				aux = false;
			}
			f_reduz->push_back(v);
		}
	}
	if (aux == true) {
		f_reduz->push_back(raiz);
	}

}

void codifica(Tree *t, map<string, string> *mapa, string s, string aux) {
	if (!(t == NULL)) {
		aux.append(s);
		codifica(t->esq, mapa, "0", aux);
		codifica(t->dir, mapa, "1", aux);
		if (strcmp(t->reg.key, "#") != 0) {
			string str;
			str.assign(t->reg.key);
			mapa->insert({ str, aux });
		}
	}
}
