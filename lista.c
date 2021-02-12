#include "lista.h"

typedef struct elemento{
	struct item dados;
	struct elemento *prox;
}Elem;

Lista* criaLista(){
	Lista* li = (Lista *) malloc(sizeof(Lista));
	
	if(li != NULL)
	*li = NULL;
	
	return li;
}

void liberaLista(Lista *li){
	if(li != NULL){
		Elem* no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		free (li);
	}	
}

int tamanhoLista(Lista *li){
	if(li == NULL)
		return 0;
	
	int cont = 0;
	Elem* no = *li;
	while(no != NULL){
		cont++;
		no = no->prox;
	}
	return cont;
}	

int insereInicio(Lista* li, struct item itm){
	if(li == NULL)
		return 0;
	Elem* no;
	no = (Elem*) malloc(sizeof(Elem));
	
	if(no == NULL)
		return 0;
	
	no->dados = itm;
	no->prox = (*li);
	*li = no;
	printf("palavra %s", no->dados.palavra);
	return 1;
}
