#include <stdio>
#include "table_symbole.h"


sSymbole_t new_symbole_table(int size)
{
	sSymbole_t new_table[size];	
	
	for (i < TABLE_MAX_SIZE)
		if new_table.id[i] = "";

	return new_table;        
}

void load_symbole(sSymbole_t symbole[TABLE_MAX_SIZE], char id[16])
{
	symbole.id[gIndex] = id;
	symbole.lvl = gLvl;
	gIndex++;
}

void free_symbole(sSymbole_t symbole[TABLE_MAX_SIZE], char id[16])
{
	for (i < TABLE_MAX_SIZE)
		if symbole.id[i] = id
			symbole.id[i] = "";	
}