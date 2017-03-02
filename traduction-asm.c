#include <stdio.h>
#include "traduction-asm.h"
#include "table-symboles.h"

int indice_tempo_max = 0 ;
int instr[TAILLE_MAX_PROG][4] ;

/*************** Fonctions privées ***************/

//return le numéro de la variable temporaire
int reserver_temporaire()
{
	int i ;
	int trouve = 0 ;	
}

/*************** Fonctions publiques ***************/

void expr_nb (int nb)
{
	printf("AFC \n") ;
}
