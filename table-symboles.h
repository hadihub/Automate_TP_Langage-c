#ifndef TABLE_SYMBOLES_H
#define TABLE_SYMBOLES_H

#define TABLE_MAX_SIZE 512
#define ID_MAX_LENGTH 16

//pour l'instant cette structure n'accepte que les variables de type int.
typedef	struct
{
	char id[ID_MAX_LENGTH] ; // le nom de la variable. Si ce champ commence par "\0", alors l'entrée est libre
	int init ; // booléen indiquant si oui ou non la variable a été initialisée
	int lvl ; // profondeur de la variable (en sortant d'un body, on oublie toutes les variables qui ont été déclarées dedans)
}sSymbole_t; //TODO : Tob -> pourquoi ce nom ? Oo

void init_table_symbole();

int get_adresse(char* id) ;

// ajouter une variable à la table des symboles
// dans un premier temps, on ne va pas implémenter la profondeur, elle sera tjrs égale à -1
int memoriser_id(char* id);

int memoriser_temporaire(int num) ;

//mettre à "true" le champ init d'une variable
void set_init(char* id);

//libérer une entrée de la table des symboles
//cette fonction sera à réécrire lorsque l'on implémentera la profondeur.
void free_symbole(int lvl);

void affiche_table_symboles() ;

#endif //TABLE_SYMBOLES_H
