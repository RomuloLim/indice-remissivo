#include "lista.h"
int main(int argc, char *argv[]) {
	
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
	printf("%d", tam + 1);

	return 0;
}
