#include <stdio.h>
#include <string.h>
#include "traduction-asm.h"
#include "table-symboles.h"

static int nb_temp = 0 ; //combien de variables temporaires sont en cours d'utilisation (pointe vers le prochain emplacement libre)
static int ligne_actuelle = 0 ; //prochaine ligne de remplissage du tableau d'instruction
char instr[TAILLE_MAX_PROG][4][16] ; //attention, on ne teste pas encore si on dépasse la taille
//int memoire[TABLE_MAX_SIZE] ; ne sert à rien 

/*************** Fonctions privées ***************/

//routine à exécuter chaque fois que l'on veut utiliser une nouvelle variable temporaire
//return le numéro de la variable temporaire qu'on vient de réserver
int reserver_temporaire()
{
	int retour_memoriser ;

	//mémoriser la variable temporaire ne sert qu'a s'assurer qu'il n'y aura pas de "conflits" entre variables temporaires et déclarées (si il y en a trop)
	retour_memoriser = memoriser_temporaire(nb_temp) ;
	if (retour_memoriser == 0) {
		nb_temp ++ ;
		return (nb_temp - 1) ; //retourner la valeur de nb_temp avant l'incrémentation
	} else {
		printf ("Erreur de compilation : dépassement du nombre maximal de variables (ou oubli de libération d'une variable :S). Erreur n°%d\n", retour_memoriser) ;
		return -1 ;
	}
}

//retourne l'emplacement de la variable temporaire que l'on vient de mémoriser
// Il faudra donc prêter attention de finir toutes les opérations sur cette variable temporaire avant d'en réserver une nouvelle (puisqu'elle écrasera celle-ci)
int liberer_temporaire() {
	nb_temp -- ;
	fin_memorisation_temporaire(nb_temp) ;
	return (nb_temp) ;
}

/*************** Fonctions publiques ***************/

void valeur_directe (int nb)
{
	int temp ;

	strcpy(instr[ligne_actuelle][0], "AFC") ;
	strcpy(instr[ligne_actuelle][1], "R0") ; //registre 0
	sprintf(instr[ligne_actuelle][2], "%d", nb) ;
	ligne_actuelle ++ ;

	strcpy(instr[ligne_actuelle][0], "STORE") ;
	temp = reserver_temporaire() ;
	sprintf(instr[ligne_actuelle][1], "@%d", TABLE_MAX_SIZE - temp - 1) ; //adresse temporaire actuelle
	strcpy(instr[ligne_actuelle][2], "R0") ; //registre 0
	ligne_actuelle ++ ;	

}


void variable_declaree (char* id)
{
	int temp ;
	int adresse_variable ;

	adresse_variable = get_adresse(id) ;
	if (adresse_variable == -1) {
		printf("Erreur de compilation : variable \"%s\" non déclarée", id) ;
		return ;
	}
	
	strcpy(instr[ligne_actuelle][0], "LOAD") ;
	strcpy(instr[ligne_actuelle][1], "R0") ; //registre 0
	sprintf(instr[ligne_actuelle][2], "@%d", adresse_variable) ;
	ligne_actuelle ++ ;

	strcpy(instr[ligne_actuelle][0], "STORE") ;
	temp = reserver_temporaire() ;
	sprintf(instr[ligne_actuelle][1], "@%d", TABLE_MAX_SIZE - temp - 1) ; //adresse temporaire actuelle
	strcpy(instr[ligne_actuelle][2], "R0") ; //registre 0
	ligne_actuelle ++ ;	
}


void addition() {
	int temp ;

	temp = liberer_temporaire() ;	
	strcpy(instr[ligne_actuelle][0], "LOAD") ;
	strcpy(instr[ligne_actuelle][1], "R0") ;
	sprintf(instr[ligne_actuelle][2], "@%d", TABLE_MAX_SIZE - temp - 1) ;
	ligne_actuelle ++ ;
	
	temp = liberer_temporaire() ;
	strcpy(instr[ligne_actuelle][0], "LOAD") ;
	strcpy(instr[ligne_actuelle][1], "R1") ;
	sprintf(instr[ligne_actuelle][2], "@%d", TABLE_MAX_SIZE - temp - 1) ;
	ligne_actuelle ++ ;

	strcpy(instr[ligne_actuelle][0], "ADD") ;
	sprintf(instr[ligne_actuelle][1], "R0") ;
	strcpy(instr[ligne_actuelle][2], "R0") ;
	strcpy(instr[ligne_actuelle][3], "R1") ;
	ligne_actuelle ++ ;	

	strcpy(instr[ligne_actuelle][0], "STORE") ;
	temp = reserver_temporaire() ;
	sprintf(instr[ligne_actuelle][1], "@%d", TABLE_MAX_SIZE - temp - 1) ; //adresse temporaire actuelle
	strcpy(instr[ligne_actuelle][2], "R0") ; //registre 0
	ligne_actuelle ++ ;	
	
}


void affectation(char* id) {
	int temp ;
	int adresse_variable ;

	adresse_variable = get_adresse(id) ;
	if (adresse_variable == -1) {
		printf("Erreur de compilation : variable \"%s\" non déclarée", id) ;
		return ;
	}

	temp = liberer_temporaire() ;	
	strcpy(instr[ligne_actuelle][0], "LOAD") ;
	strcpy(instr[ligne_actuelle][1], "R0") ;
	sprintf(instr[ligne_actuelle][2], "@%d", TABLE_MAX_SIZE - temp - 1) ;
	ligne_actuelle ++ ;

	strcpy(instr[ligne_actuelle][0], "STORE") ;
	sprintf(instr[ligne_actuelle][1], "@%d", adresse_variable) ; //adresse temporaire actuelle
	strcpy(instr[ligne_actuelle][2], "R0") ; //registre 0
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
