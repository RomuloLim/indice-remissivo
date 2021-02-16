#include "lista.h"

typedef struct elemento{
	struct item dados;
	struct elemento *prox;
}Elem;

int tamanhoLinha(){
	FILE *file;
	file = fopen ("chaves.txt", "r");
	
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
	
	return (tam + 1);
}

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
//	printf("%d", tam +1);
	return (tam + 1);
}

Lista* criaLista(){
	Lista* li = (Lista *) malloc(sizeof(Lista));
	
	if(li != NULL){
	Elem* no;
	no = (Elem*) malloc(sizeof(Elem));
	
	*li = NULL; //passa o no para a lista principal
	}
	
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
	printf("palavra %s inserida \n", no->dados.palavra);
	return 1;
}

int preencheChaves(Lista* li){
	struct item itm;
	FILE *file;
	file = fopen ("chaves.txt", "r");
	char linha[50];
	
	if(file == NULL)
		return 0;
	
	while(fgets(linha, sizeof(linha), file) != NULL){
			strcpy(itm.palavra, linha);
			insereInicio(li, itm);
	}
	
	fclose(file);
	return 1;
}
