#include "hash.h"

struct hash {
	int qtd, tamanho;
	struct item **itens;
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
	printf("%d", tam +1);
	return (tam + 1);
}

Hash* criaHash(){
	Hash* ha = (Hash*) malloc(sizeof(Hash));
	if(ha != NULL){
		int i;
		ha->tamanho = tamanhoTexto();
		ha->itens = (struct item**) malloc (tamanhoTexto() * sizeof(struct item*));
		if(ha->itens == NULL){
			free(ha);
			return NULL;
		}
		ha->qtd = 0;
		for (i=0; i < ha->tamanho; i++)
		ha->itens[i] = NULL;
	}
	return ha;
}

void liberaHash(Hash* ha){
	if (ha != NULL){
		int i;
		for(i=0; i < ha->tamanho; i++){
			free(ha->itens[i]);
		}
	free(ha->itens);
	free(ha);
	}
}

int chaveMult(int chave, int tamanho){
	float A = 0.6184579804; //constante 0 < A < 1
	float val = chave * A;
	val = val - (int) val;
	return (int) (tamanho * val);
}

int chaveDiv(int chave, int tamanho){
	return (chave & 0x7FFFFFFF) % tamanho;
}

int duploHash(int H1, int chave, int i, int tamanho){
	int H2 = chaveDiv(chave, tamanho-1) + 1;
	return ((H1 + i*H2) & 0x7FFFFFFF) % tamanho;	
		
}

int valorString(char *str){
	int i, valor = 7;
	int tam = strlen(str);
	for(i=0; i < tam; i++)
		valor = 31 * valor + (int) str[i];
	return valor;
}

int insereHashEnderAberto(Hash* ha, struct item itm){
	if(ha == NULL || ha->qtd == ha->tamanho)
		return 0;
	
	int chave = valorString(itm.palavra);
	
	int i, pos, novaPos;
	pos = chaveMult(chave, ha->tamanho);
	
	if(ha->itens[pos] == NULL){
		struct item* novo;
		novo = (struct item*) malloc(sizeof(struct item));
		if(novo == NULL)
			return 0;
		*novo = itm;
		ha->itens[novaPos] = novo;
		ha->qtd++;
		return 1;	
	}
	
	for(i=0; i < ha->tamanho; i++){
		novaPos = duploHash(pos, chave, i, ha->tamanho);
		if(ha->itens[novaPos] == NULL){
			struct item* novo;
			novo = (struct item*) malloc(sizeof(struct item));
			if(novo == NULL)
				return 0;
			*novo = itm;
			ha->itens[novaPos] = novo;
			ha->qtd++;
			return 1;
		}
	}
	return 0;
}


