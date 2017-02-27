#ifndef TABLE_SYMBOLES_H
#define TABLE_SYMBOLES_H

#define TABLE_MAX_SIZE 1024

typedef	struct
{
	char id[16]; 
	int lvl;
}sSymbole_t;



void load_symbole(char* id);


void free_symbole(char* id);

#endif