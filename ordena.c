#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void ordenar(Lista *l) {
	Elem *aux = *l, *t;
    
	if(*l == NULL || (*l)->prox == NULL) return; 
	
	FILE *file;
	file = fopen("IndiceRemissivoFinal.txt", "a");
    
    int i, j, w, k = 0, contador, tam;
    
    tam = tamanhoLista(l);
    
    Elem* v[tam];
    Elem* temp;
    
    while(aux != NULL) {
    	v[k] = aux;
    	
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
	
	for(int i = 0; i < tam; i++) {
		printf("%s - ", v[i]->dados.palavra);
		fprintf(file, "%s - ", v[i]->dados.palavra);
		
		w = 0;
		
		while (v[i]->dados.linha[w] != 0){
			printf("%d ", v[i]->dados.linha[w]);
			fprintf(file, "%d ", v[i]->dados.linha[w]);
			
			w++;
		}
		
		printf("\n");
		fprintf(file, "\n");
	}
	
	fclose(file);
}

