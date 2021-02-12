#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
	char palavra[45];
	int linha[10];
};
typedef struct elemento* Lista;

Lista* criaLista();
void liberaLista(Lista* li);
int insereInicio(Lista* li, struct item itm);
int removeLista(Lista* li, char palavra[45]);
int tamanhoLista(Lista* li);
int listaVazia(Lista* li);
int buscaLista(Lista* li, char palavra[45], struct item* itm);

