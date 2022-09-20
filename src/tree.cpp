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
		(*t)->reg = r;
	}
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

void preordem(Tree *t) {
	if (!(t == NULL)) {
		// printf("%d ", t->reg.key);
		preordem(t->esq);
		preordem(t->dir);
	}
}

void central(Tree *t) {
	if (!(t == NULL)) {
		central(t->esq);
		if (t->reg.key.empty())
			cout << "#";
		cout << t->reg.key << "-" << t->reg.value << " ";
		central(t->dir);
	}
}

void posordem(Tree *t, map<string, string> *mapa, string s, string aux) {
	if (!(t == NULL)) {
		aux.append(s);
		posordem(t->esq, mapa, "0", aux);
		posordem(t->dir, mapa, "1", aux);
		if (!t->reg.key.empty())
			mapa->insert({ t->reg.key, aux });
	}
}
