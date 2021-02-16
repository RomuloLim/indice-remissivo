#include <stdio.h>
#include <string.h>

void Ordena(char palavra[10][100]) {
	int i, j, r;
	char aux[80];
	
	for(i = 0; i <= 9; i++) {
		for(j = i+1; j <= 9; j++) {
			r = strcmp(palavra[i], palavra[j]);
			
			if(r > 0) {
				strcpy(aux, palavra[i]);
				strcpy(palavra[i], palavra[j]);
				strcpy(palavra[j], aux);
			}
		}
	}
}

