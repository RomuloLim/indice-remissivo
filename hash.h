#include "lista.h"

//tamanho da tabela
#define TABLE_SIZE 19

typedef struct hash Hash;

Hash* criaHash();
void liberaHash(Hash* ha);
int valorString(char *str);
int insereHashEnderAberto(Hash* ha, struct item itm);
int buscaHashEnderAberto(Hash* ha, char palavra, struct item itm);

int valorString(char *str);
int chaveMult(int chave, int tamanho);
int chaveDiv(int chave, int tamanho);
int duploHash(int H1, int chave, int i, int tamanho);


int tamanhoTexto();

