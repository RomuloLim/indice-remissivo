#include "lista.h"

typedef struct elemento {
	struct item dados;
	struct elemento *prox;
} Elem;

int tamanhoLinha() {
	FILE *file;
	file = fopen ("chaves.txt", "r");
	
	if(file == NULL)
		return 0;
	
	char letra = '\n';
	char palavra;
	int i,div, tam = 0;
	
    while(fread (&palavra, sizeof(char), 1, file)) {
        if(palavra == letra) {
            tam++;
        }
    }
	 	
	fclose(file);
	
	tam = tam + 1; 
	//sempre retornar um número primo	
	while (div != 2) {
		div = 0;
		
 		for (i = 1; i <= tam; i++) {
    		if (tam % i == 0) 
     		div++;
  		}
  		
  		if(div != 2)
  			tam++;
	}
	
	//printf("%d", tam);
	
	return (tam);
}

int tamanhoTexto() {
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
    //printf("%d", tam +1);
	return (tam + 1);
}

Lista* criaLista() {
	Lista* li = (Lista *) malloc(sizeof(Lista));
	int i;
	
	if(li != NULL) {
		Elem* no;
		no = (Elem*) malloc(sizeof(Elem));
	
		*li = NULL;
	}
	
	return li;
}

void liberaLista(Lista *li) {
	if(li != NULL) {
		Elem* no;
		
		while((*li) != NULL) {
			no = *li;
			*li = (*li)->prox;
			free(no);
		}
		
		free (li);
	}	
}

int tamanhoLista(Lista *li) {
	if(li == NULL)
		return 0;
	
	int cont = 0;
	Elem* no = *li;
	
	while(no != NULL) {
		cont++;
		no = no->prox;
	}
	
	return cont;
}	

int insereInicio(Lista* li, struct item itm) {
	int i;
	
	if(li == NULL)
		return 0;
		
	Elem* no;
	no = (Elem*) malloc(sizeof(Elem));
	
	if(no == NULL)
		return 0;

	no->dados = itm;
	no->prox = (*li);
	
	for(i = 0; i < MAX; i++) {
		no->dados.linha[i] = 0;
	}
	
	*li = no;
	//printf("palavra %s inserida \n", no->dados.palavra);
	return 1;
}

int preencheChaves(Lista* li) {
	struct item itm;
	FILE *file;
	file = fopen ("chaves.txt", "r");
	char linha[50];
	
	if(file == NULL)
		return 0;
	
	while(fgets(linha, sizeof(linha), file) != NULL) {
		strcpy(itm.palavra, linha);
		
		if(itm.palavra[strlen(itm.palavra)-1] == '\n') {
			itm.palavra[strlen(itm.palavra)-1] = '\0';
		}
		
		insereInicio(li, itm);
	}
	
	fclose(file);
	return 1;
}

int mostraIndice(Lista* li) {
	int i;
	
	Elem* aux = *li;
	
	while (aux != NULL) {
		printf("\n%s - ", aux->dados.palavra);
		
		i = 0;
		
		while (aux->dados.linha[i] != 0) {
			printf("%d ", aux->dados.linha[i]);
			
			i++;
		}
		
		printf("\n");
		aux = aux->prox;
	}
}

