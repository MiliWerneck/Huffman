#ifndef TREE_HPP
#define TREE_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Record Record;
typedef struct Tree Tree;

struct Record {
	// string *key;
	char *key;
	float value;
	vector<int> v;
};

struct Tree {
	Record reg;
	Tree *esq, *dir;
};

Tree *CreateTree();
bool TVazia(Tree **t);
void insertTree(Tree **t, Record r);
void operHuffman(vector <Tree *> *f_init, vector <Tree *> *f_reduz, Tree *raiz);
void get_first_sec(vector <Tree *> f_init, Tree **first, Tree **second);
void insertTreeHuff(vector <Tree *> *f_init, Tree **raiz_final);

void reduzirFloresta(Tree **t, Record r, vector <Tree *> *f_init, Tree **t_menor, Tree **t_maior, Tree **raiz_final);
void decodeBinary(Tree *raiz_final);

void preordem(Tree *t);
void central(Tree *t);
void codifica(Tree *t, map<string, string> *mapa, string s, string aux);

#endif
