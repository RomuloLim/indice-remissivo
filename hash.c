#include "hash.h"

Hash* criaHash() {
	Hash* ha = (Hash*) malloc(sizeof(Hash));
	
	if(ha != NULL) {
		int i, tam;
		
		tam = tamanhoLinha();
		
		ha->tamanho = tam;
		ha->itens = (struct item**) malloc (tam * sizeof(struct item*));
		
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

void liberaHash(Hash* ha) {
	if (ha != NULL) {
		int i;
		
		for(i=0; i < ha->tamanho; i++)
			free(ha->itens[i]);
		
		free(ha->itens);
		free(ha);
	}
}

int chaveMult(int chave, int tamanho) {
	float A = 0.6184579804; //constante 0 < A < 1
	float val = chave * A;
	
	val = val - (int) val;
	
	return (int) (tamanho * val);
}

int chaveDiv(int chave, int tamanho) {
	return (chave & 0x7FFFFFFF) % tamanho;
}

int duploHash(int H1, int chave, int i, int tamanho) {
	int H2 = chaveDiv(chave, tamanho-1) + 1;
	return ((H1 + i*H2) & 0x7FFFFFFF) % tamanho;	
		
}

int valorString(char *str) {
	int i, valor = 7;
	int tam = strlen(str);
	for(i=0; i < tam; i++)
		valor = 31 * valor + (int) str[i];
	return valor;
}

int insereHashEnderAberto(Hash* ha, Lista* li) {
	if(ha == NULL || ha->qtd == ha->tamanho) {
			printf("\n\n erro");
			return 0;
	}
	
	Elem* aux = *li;
	int i, pos, novaPos;
	int j = 0;
	
	while(aux != NULL) {
		//printf("\n\n palavra: %s", aux->dados.palavra);
		int chave = valorString(aux->dados.palavra);
		pos = chaveMult(chave, ha->tamanho); 
		
		if(ha->itens[pos] == NULL) {
			struct item* novo; 
			
			novo = (struct item*) malloc(sizeof(struct item));
			
			*novo = aux->dados;
			ha->itens[pos] = novo;
			ha->qtd++;
			//printf("\n\n aux1: %s", aux->dados.palavra);
			} else {
				for(i=0; i < ha->tamanho+500; i++){
				//printf("entrei no for");
				novaPos = duploHash(pos, chave, i, ha->tamanho);
				//printf(" posicao %d ", novaPos);
			
				if(ha->itens[novaPos] == NULL){
					struct item* novo;
					novo = (struct item*) malloc(sizeof(struct item));
				
					*novo = aux->dados;
					ha->itens[novaPos] = novo;
					ha->qtd++;
					//printf("\n\n aux2: %s", aux->dados.palavra);
					break;
				}
			}
		}
	
		aux = aux->prox;
	}
	
	return 1;
}

int buscaHashEnderAberto(Hash* ha, char *palavra, struct item* itm) {
	if(ha == NULL)
		return 0;
	
	int i, pos, newPos;
	int chave = valorString(palavra);
	pos = chaveMult(chave, ha->tamanho);
	
	if(ha->itens[pos]->palavra == palavra) {
		*itm = *(ha->itens[pos]);
		return 1;
	}
	
	for(i = 0; i < ha->tamanho; i++) {
		newPos = duploHash(pos, chave, i, ha->tamanho);
		
		if(ha->itens[newPos] == NULL);
			return 0;
		
		if(ha->itens[newPos]->palavra == palavra) {
			*itm = *(ha->itens[newPos]);
			
			return 1;
		}
	}
}
int indiceRemissivo(Hash* ha, Lista* li, struct item* itm) {
	Elem *aux = *li;
	
	char str[100];
    int i,j,contador;
    
    FILE *fp;
    fp = fopen("texto.txt","r");
    
    if (!fp)
   	  exit(1);
   		
	for(i = 0; i < ha->tamanho; i++) {
		contador = 0;
   		j = 0;
   		
		buscaHashEnderAberto(ha, aux->dados.palavra, itm);
		
    	while (fgets(str, sizeof(str), fp) != NULL) {
    		contador++;
          	if (strstr(str, aux->dados.palavra) != NULL){
             	//printf("\n palavra: %s na linha: %d\n", aux->dados.palavra, contador);
             	aux->dados.linha[j] = contador;
            	j++;
            }
        }
   		aux = aux->prox;
   		rewind(fp);
   		
   		if(aux == NULL)
   			break;
    }
    
	fclose(fp);
    return 1;
}
