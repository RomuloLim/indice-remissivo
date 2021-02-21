#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct item{
	char palavra[50];
	int linha[MAX];
};

typedef struct elemento {
	struct item dados;
	struct elemento *prox;
} Elem;

typedef struct elemento* Lista;

Lista* criaLista();
void liberaLista(Lista* li);
int insereInicio(Lista* li, struct item itm);
int removeLista(Lista* li, char palavra);
int tamanhoLista(Lista* li);
int listaVazia(Lista* li);
int buscaLista(Lista* li, char palavra, struct item* itm);
int mostraIndice(Lista* li);

int tamanhoLinha();
int tamanhoTexto();
