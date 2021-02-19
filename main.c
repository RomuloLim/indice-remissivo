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
	
	ordenar(lista);		
	
	return 0;
}

