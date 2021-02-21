#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(int argc, char *argv[]) {
	Lista* lista;
	ArvBin* arvore;
	
	lista = criaLista();
	
	preencheChaves(lista);
	
	arvore = cria_ArvBin();
	
	insere_ArvBin(arvore, lista);
	
	return 0;
}
