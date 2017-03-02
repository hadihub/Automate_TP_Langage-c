#include <stdio.h>
#include <string.h>
#include "table-symboles.h"
//cf le .h pour d'avantage de commentaires
//test de contribution

sSymbole_t symbole[TABLE_MAX_SIZE];

/*************** Fonctions publiques ***************/

void load_variable_declaree(char* id)
{
	int i, gIndex ;
	int trouve = 0 ;

	//commencer par chercher le premier espace libre
	for (i = 0; (i < TABLE_MAX_SIZE && !trouve) ; i++)
	{
		if (!strcmp(symbole[i].id, "")) //si l'id est une chaîne vide, l'emplacement est libre
		{
			gIndex = i ;
			trouve = 1 ;
		}
	}
	strncpy(symbole[gIndex].id, id, 16) ;
	symbole[gIndex].lvl = -1 ;
}

/* ajoute les variables temporaires en commençant par la fin du tableau
 * retourne 0 si tout s'est bien passé et un autre nombre sinon
 */
int load_variable_temporaire(int num)
{
	if (!strcmp(symbole[TABLE_MAX_SIZE - num].id, ""))
	{
		strncpy(symbole[TABLE_MAX_SIZE - num].id, "temporaire", 16) ;
		return 0 ;
	}
	else
	{
		return -1 ;
	}
	// on s'en fout des autres champs, on ne s'en servira pas :P
	//note : si temporaire n°x est utilisé, alors tous les temporaire[0,x] le sont aussi (car le compilateur se sert d'une pile). On ne peut donc pas se retrouver dans la situation où temp0 et 2 sont pris mais pas temp1
}

void set_init(char* id)
{
	int i ;
	int trouve = 0 ;

	for (i = 0; (i < TABLE_MAX_SIZE && !trouve) ; i++)
	{
		if (!strcmp(symbole[i].id, id))
		{
			symbole[i].init = 1 ;
			trouve = 1 ; // trouver la variable nous fait sortir de la boucle. NB : cette méthode n'est pas valable avec la notion de profondeur
		}
	}
	
}

void free_symbole(char* id)
{
	int i ;
	int trouve = 0 ;

	for (i = 0; (i < TABLE_MAX_SIZE && !trouve) ; i++)
	{
		if (!strcmp(symbole[i].id, id))
		{
			symbole[i].id[0] = '\0';
			trouve = 1 ; //NB : cette méthode n'est pas valable avec la notion de profondeur
		}
	}
}
