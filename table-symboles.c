#include <stdio.h>
#include <string.h>
#include "table-symboles.h"

sSymbole_t symbole[TABLE_MAX_SIZE];
int gIndex = 0;
int gLvl = 0;


void load_symbole(char* id)
{
	strncpy(symbole[gIndex].id, id, 16);
	symbole[gIndex].lvl = gLvl;
	gIndex++;
}

void free_symbole(char* id)
{
	for (int i = 0; i < TABLE_MAX_SIZE; i++)
		if (!strcmp(symbole[i].id, id))
			symbole[i].id[0] = '\0';
}