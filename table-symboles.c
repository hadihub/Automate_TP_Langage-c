#include <stdio.h>
#include <string.h>
#include "table-symboles.h"
//cf le .h pour d'avantage de commentaires
//test de contribution

static sSymbole_t symbole[TABLE_MAX_SIZE]; //ici, static = privé
int gLvl; // variable global qui retient le niveau de profondeur

/*************** Fonctions publiques ***************/

void init_table_symbole()
{
    int i ;
    
    gLvl = 0;
   
    for (i = 0; i < TABLE_MAX_SIZE ; i++)
    {
        symbole[i].id[0] = '\0';
    }
}

int load_variable_declaree(char* id)
{
    int i, index ;
    int trouve = 0 ;
       
    //tester si l'id est trop long
    if (strlen(id) >= ID_MAX_LENGTH)
    {
        printf("id trop long !\n") ;
        return -1 ;
    }

    //commencer par chercher le premier espace libre
    for (i = 0; (i < TABLE_MAX_SIZE && !trouve) ; i++)
    {
        if (symbole[i].id[0] == '\0') //si l'id est une chaîne vide, l'emplacement est libre
        {
            index = i ;
            trouve = 1 ;
        }
    }
    strcpy(symbole[index].id, id) ;
    symbole[index].lvl = gLvl ;

    return 0 ;
}

/* ajoute les variables temporaires en commençant par la fin du tableau
 * retourne 0 si tout s'est bien passé et un autre nombre sinon
 */
int load_variable_temporaire(int num)
{
    if (!strcmp(symbole[TABLE_MAX_SIZE - num].id, ""))
    {
        strncpy(symbole[TABLE_MAX_SIZE - num].id, "temporaire", ID_MAX_LENGTH) ;
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

//TODO : Pas supprimer par id, mais par profondeur
void free_symbole(int lvl)
{
    int i;    

    for (i = 0; (i < TABLE_MAX_SIZE) ; i++)
    {
        if (symbole[i].lvl == lvl)
        {
            symbole[i].id[0] = '\0';           
        }
    }
}

void affiche_table_symboles() 
{
    int i ;

    for (i=0 ; (i < TABLE_MAX_SIZE && symbole[i].id[0] != '\0') ; i++)
    {
        printf("#%d | lvl: %d | %s\n", i, gLvl, symbole[i].id) ;
    }
}









