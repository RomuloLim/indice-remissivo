#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

struct NO {
    struct elemento *info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin() {
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));

    if(raiz != NULL)
        *raiz = NULL;

	printf("\nArvore criada!\n");
    return raiz;
}

void libera_NO(struct NO* no) {
    if(no == NULL) return;

    libera_NO(no->esq);
    libera_NO(no->dir);

    free(no);

    no = NULL;
}

void libera_ArvBin(ArvBin* raiz) {
    if(raiz == NULL) return;

    libera_NO(*raiz);
    free(raiz);
}

int insere_ArvBin(ArvBin *raiz, Lista* li) {
    if(raiz == NULL) return 0;

    struct NO* novo;
    Elem* aux = *li;

    novo = (struct NO*) malloc(sizeof(struct NO));

    if(novo == NULL) return 0;

    novo->info->dados = aux->dados;
    novo->dir = NULL;
    novo->esq = NULL;
    
    while(aux != NULL){
    	// Está dando erro aqui. Ele entra no while e não sai mais!
    	if(*raiz == NULL) {
    		*raiz = novo;
    		
    		printf("Palavra: %s, inserida na arvore!\n", aux->dados.palavra);
		} else {
	        struct NO* atual = *raiz;
	        struct NO* ant = NULL;
	
	        while(atual != NULL) {
	            ant = atual;
	
	            if(strcmp(aux->dados.palavra, atual->info->dados.palavra) == 0) {
	                free(novo);
	                return 0;
	            }
	
	            if(strcmp(aux->dados.palavra, atual->info->dados.palavra) > 0)
	                atual = atual->dir;
	            else
	                atual = atual->esq;
	                
	            printf("Palavra dentro do while: %s, inserida na arvore!\n", aux->dados.palavra);
	        }
	
	        if(strcmp(aux->dados.palavra, ant->info->dados.palavra) > 0)
	            ant->dir = novo;
	        else
	            ant->esq = novo;
    	}
		
		aux = aux->prox;
	}
    
    /*int tam, i;
	tam = sizeof(li)/sizeof(li[0]);
    
    for(i = 0; i < tam; i++) {
    	printf("teste\n");
	}
	
	printf("%d", tam);*/

    /*if(*raiz == NULL) {
    	*raiz = novo;
	} else {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;

        while(atual != NULL) {
            ant = atual;

            if(strcmp(aux->dados.palavra, atual->info->dados.palavra) == 0) {
                free(novo);
                return 0;
            }

            if(strcmp(aux->dados.palavra, atual->info->dados.palavra) > 0)
                atual = atual->dir;
            else
                atual = atual->esq;
        }

        if(strcmp(aux->dados.palavra, ant->info->dados.palavra) > 0)
            ant->dir = novo;
        else
            ant->esq = novo;
    }*/

	printf("Palavra: %s, inserida na arvore!\n", aux->dados.palavra); 
    return 1;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;

    if(atual->esq == NULL) {
        no2 = atual->dir;

        free(atual);

        return no2;
    }

    no1 = atual;
    no2 = atual->esq;

    while(no2->dir != NULL) {
        no1 = no2;
        no2 = no2->dir;
    }

    if (no1 != atual) {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }

    no2->dir = atual->dir;

    free(atual);

    return no2;
}

int remove_ArvBin(ArvBin *raiz, Lista* li) {
    if(raiz == NULL) return 0;

    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    Elem* aux = *li;

    while(atual != NULL) {
        if(strcmp(aux->dados.palavra, atual->info->dados.palavra) == 0)
            *raiz = remove_atual(atual);
        else {
            if(ant->dir == atual)
                ant->dir = remove_atual(atual);
            else
                ant->esq = remove_atual(atual);
        }

        return 1;
    }

    ant = atual;

    if(strcmp(aux->dados.palavra, atual->info->dados.palavra) > 0)
        atual = atual->dir;
    else
        atual = atual->esq;
}

int consulta_ArvBin(ArvBin *raiz, Lista* li) {
    if(raiz == NULL) return 0;

    struct NO* atual = *raiz;
    Elem* aux = *li;

    while(atual != NULL) {
        if(strcmp(aux->dados.palavra, atual->info->dados.palavra) == 0) {
            return 1;
        }

        if(strcmp(aux->dados.palavra, atual->info->dados.palavra) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }

    return 0;
}

int estaVazia_ArvBin(ArvBin* raiz) {
    if(raiz == NULL) return 1;
    if(*raiz == NULL) return 1;

    return 0;
}

int altura_ArvBin(ArvBin *raiz) {
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;

    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));

    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

int totalNO_ArvBin(ArvBin *raiz) {
    if(raiz == NULL) return 0;
    if(*raiz == NULL) return 0;

    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));

    return (alt_esq + alt_dir + 1);
}

void preOrdem_ArvBin(ArvBin *raiz) {
    if(raiz == NULL) return;

    if(*raiz != NULL) {
        printf("%d\n", (*raiz)->info);

        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz) {
    if(raiz == NULL) return;

    if(*raiz != NULL) {
        emOrdem_ArvBin(&((*raiz)->esq));

        printf("%d\n", (*raiz)->info);

        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz) {
    if(raiz == NULL) return;

    if(*raiz != NULL) {
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));

        printf("%d\n", (*raiz)->info);
    }

}

