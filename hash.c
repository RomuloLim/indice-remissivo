#include "hash.h"

struct hash {
	int qtd, tamanho;
	struct item **itens;
};

typedef struct elemento{
	struct item dados;
	struct elemento *prox;
}Elem;

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

int insereHashEnderAberto(Hash* ha, Lista* li){
	if(ha == NULL || ha->qtd == ha->tamanho){
			printf("\n\n erro");
			return 0;
	}
	
	Elem* aux = *li;
	int i, pos, novaPos;
	int j = 0;
	
	while(tamanhoLista(li) > j){
		int chave = valorString(aux->dados.palavra);
		pos = chaveMult(chave, ha->tamanho);
	
		if(ha->itens[pos] == NULL){
			struct item* novo;
			novo = (struct item*) malloc(sizeof(struct item));
			*novo = aux->dados;
			ha->itens[pos] = novo;
			ha->qtd++;
			
			printf("\n\n aux: %s", aux->dados.palavra);
			escreveTabelaNoArquivo(aux->dados.palavra);
			aux = aux->prox;
		} else{	
			for(i=0; i < ha->tamanho; i++){
				novaPos = duploHash(pos, chave, i, ha->tamanho);
				if(ha->itens[novaPos] == NULL){
					struct item* novo;
					novo = (struct item*) malloc(sizeof(struct item));
					
					*novo = aux->dados;
					ha->itens[novaPos] = novo;
					ha->qtd++;
					printf("\n\n aux: %s", aux->dados.palavra);
					escreveTabelaNoArquivo(aux->dados.palavra);
					aux = aux->prox;
					i = ha->tamanho;
				}
			}
		}
		
		j++;
	}
	
	return 1;
}

int escreveTabelaNoArquivo(char palavra[50]) {
	FILE *file;
	file = fopen("arquivoNaoOrdenado.txt", "a");
	
	fprintf(file, "%s", palavra);
	
	fclose(file);
	
	return 1;
}


