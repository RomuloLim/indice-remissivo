#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

void ordenar(Lista *l) {
	Elem *aux = *l, *t, *lista;
	lista = aux;
    
	if(*l == NULL || (*l)->prox == NULL) return; 
	
	FILE *file;
	file = fopen("chavesOrdenadas.txt", "a");
    
    int i, j, w = 0, k = 0, contador, tam;
    
    tam = tamanhoLista(l);
    
    Elem* v[tam];
    Elem* temp;
    
    while(aux != NULL) {
    	v[k] = aux;
    	
    	printf("%s\n", aux->dados.palavra);
    	
    	k++;
    	aux = aux->prox;
	}

	for(i = 0 ; i < tam; i++) {
	    for(j = i+1 ; j < tam; j++) {
	        contador = strcmp(v[i]->dados.palavra, v[j]->dados.palavra);
	
	        if(contador > 0) {
	           	temp = v[i];
	            v[i] = v[j];
	            v[j] = temp;
	        }
	    }
	}
	
	for(w = 0 ; w < tam; w++) {
		lista = v[w];
		
		//printf("%s\n", lista->dados.palavra);
		fprintf(file, "%s\n", lista->dados.palavra);
		
		lista = lista->prox;
	}
	
	fclose(file);
}
