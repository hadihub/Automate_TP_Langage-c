#ifndef TABLE_SYMBOLES_H
#define TABLE_SYMBOLES_H

#define TABLE_MAX_SIZE 1024

//pour l'instant cette structure n'accepte que les variables de type int.
typedef	struct
{
	char id[16] ; // le nom de la variable. Si ce champ commence par "\0", alors l'entrée est libre
	int init ; // booléen indiquant si oui ou non la variable a été initialisée
	int lvl ; // profondeur de la variable (en sortant d'un body, on oublie toutes les variables qui ont été déclarées dedans)
}sSymbole_t ; //TODO : Tob -> pourquoi ce nom ? Oo

// ajouter une variable à la table des symboles
// dans un premier temps, on ne va pas implémenter la profondeur, elle sera tjrs égale à -1
void load_variable_declaree(char* id) ;

//mettre à "true" le champ init d'une variable
void set_init(char* id) ;

//libérer une entrée de la table des symboles
//cette fonction sera à réécrire lorsque l'on implémentera la profondeur.
void free_symbole(char* id) ;

#endif //TABLE_SYMBOLES_H
