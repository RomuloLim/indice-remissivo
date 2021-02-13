#include "hash.h"

struct hash {
	int qtd, tamanho;
	struct itm **itens;
};

int tamanhoTexto(){
	FILE *file;
	file = fopen ("texto.txt", "r");
	
	if(file == NULL)
		return 0;
	
	char letra = '\n';
	char palavra;
	int tam = 0;
	
     while(fread (&palavra, sizeof(char), 1, file)) {
            if(palavra == letra) {
                tam++;
            }
        } 
        
	fclose(file);
        
	fclose(file);
	printf("%d", tam +1);
	return (tam + 1);
}

Hash* criaHash(){
	Hash* ha = (Hash*) malloc(sizeof(Hash));
	if(ha != NULL){
		int i;
		ha->tamanho = tamanhoTexto();
	}
}
