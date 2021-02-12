#include "lista.h"

//tamanho da tabela
#define TABLE_SIZE 19

typedef struct hash Hash;

Hash* criaHash(TABLE_SIZE);
void liberaHash(Hash* ha);
int valorString(char *str);
int insereHashEnderAberto(Hash* ha, struct item itm);
int buscaHashEnderAberto(Hash* ha, char palavra, struct item itm);

