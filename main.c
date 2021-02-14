#include "lista.h"
int main(int argc, char *argv[]) {
	int numeroDeChaves = tamanhoLinha();
	
	FILE *file;
	file = fopen("textos.txt", "r");
	
	if(file == NULL){
		printf("erro: arquivo de texto nao encontrado");
		return 0;
	}
	
	fclose(file);
	
	return 0;
}
