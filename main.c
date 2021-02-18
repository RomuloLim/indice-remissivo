#include "hash.h"

int main(int argc, char *argv[]) {
	Lista* lista;
	Hash* tabela;
	struct item* itm;
	
	lista = criaLista();
	
	preencheChaves(lista);
	
	tabela = criaHash();
	
	insereHashEnderAberto(tabela, lista);

	indiceRemissivo(tabela, lista, itm);
	
	printf("====================");
	mostraIndice(lista);
	return 0;
}


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int main() {
//    char nome[20], str[100];
//    int contador = 0;
//    FILE *fp;
//    fp = fopen("texto.txt","r");
//    if (!fp)
//       exit(1);
//    printf("string para pesquisa: ");
//    fgets(nome,sizeof(nome),stdin);
//    nome[strlen(nome)-1]=nome[strlen(nome)];
//    while (fgets(str,sizeof(str),fp)!=NULL){
//    	contador++;
//          if (strstr(str,nome)!=NULL)
//             printf("linha: %d\n", contador);
//         }    
//    fclose(fp);
//    return 0;
//}

