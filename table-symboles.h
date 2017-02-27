#ifndef TABLE-SYMBOLES_H
#define TABLE-SYMBOLES_H
#endif

#define TABLE_MAX_SIZE 1024

int gIndex = 0;
int gLvl = 0;

typedef	struct
{
	char id[16]; 
	int lvl;
}sSymbole_t;


sSymbole_t new_symbole_table(int size)

void load_symbole(sSymbole_t symbole[TABLE_MAX_SIZE], char id[16])


void free_symbole(sSymbole_t symbole[TABLE_MAX_SIZE], char id[16])

