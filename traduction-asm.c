#include <stdio.h>
#include "traduction-asm.h"
#include "table-symboles.h"

static int nb_temp = 0 ; //combien de variables temporaires sont en cours d'utilisation
static int ligne_actuelle = 0 ; //prochaine ligne de remplissage du tableau d'instruction
char instr[TAILLE_MAX_PROG][4][16] ; //attention, on ne teste pas encore si on dépasse la taille
//int memoire[TABLE_MAX_SIZE] ; ne sert à rien 

/*************** Fonctions privées ***************/

//return le numéro de la variable temporaire
int reserver_temporaire()
{
	int i ;
	// int memoriser_temporaire(int num) ;
	memoriser_temporaire(nb_temp) ;
	return nb_temp ;
}

/*************** Fonctions publiques ***************/

void expr_nb (int nb)
{
	int temp ;

	strcpy(instr[ligne_actuelle][0], "AFC") ;
	strcpy(instr[ligne_actuelle][1], "R0") ; //registre 0
	sprintf(instr[ligne_actuelle][2], "%d", nb) ;
	ligne_actuelle ++ ;

	strcpy(instr[ligne_actuelle][0], "STORE") ;
	temp = reserver_temporaire() ;
	sprintf(instr[ligne_actuelle][1], "%d", temp) ; //adresse temporaire 0
	strcpy(instr[ligne_actuelle][2], "temp0") ; //registre 0
	ligne_actuelle ++ ;	

}

void affiche_code_binaire()
{
	int i ;

	for (i=0 ; i < ligne_actuelle ; i++)
	{
		printf("%s %s %s %s \n", instr[i][0], instr[i][1], instr[i][2], instr[i][3]) ;
	}
}
