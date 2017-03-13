%{
#include <stdio.h>
#include "table-symboles.h"
void yyerror (char *s);
int gLvl = 0; // variable globale qui retient le niveau de profondeur
%}

%union {int nb; char str[ID_MAX_LENGTH]; /*déclaration des types à associer aux tokens*/}

%token	tMain
%token  tIf
%token  tElse
%token  tWhile
%token  tAo
%token  tAf
%token  tPo
%token  tPf
%token  tVir
%token  tPvir
%token  tEgal
%token  tDivise
%token  tMoin
%token  tPlus
%token  tFois
%token  tReturn
%token  tInt
%token  tEt
%token  tOu
%token  tDoubleEgal
%token  tConst
%token  tPrintf
%token  <nb> tEntier
%token  <str> tId
%start  Start
%left   tMoin tPlus
%left   tFois tDivise

%%

Start		: Prog

Prog		: Fonctions {printf("Prog detected\n"); /*affiche_table_symboles(); affiche_code_binaire() ;*/ export_to_file() ;}

Fonctions	: %empty
            | Fonction Fonctions

Fonction	: tInt tId tPo Args tPf Body 
Args		: %empty
            | tInt tId ListArgs	{/*memoriser_id($2);*/}

ListArgs	: %empty	 
            | tVir tInt tId ListArgs	{/*memoriser_id($3);*/}

Body		: tAo {gLvl++;} Instructions tAf {gLvl--; /*affiche_table_symboles();*/ free_symbole(gLvl+1);}

Instructions	: %empty
                | Instruction Instructions 

Instruction	    : Dec
                | If
                | While
                | Affect 
                | Invoc

Invoc		: tId tPo Params tPf tPvir	

Params		: %empty
            | Param
            | Param tVir ListParams

ListParams 	: Param
            | Param tVir ListParams

Param		: ExprArith 

ExprArith 	: ExprArith tPlus ExprArith	{addition() ;}
            | ExprArith tMoin ExprArith	{soustraction() ;}
            | ExprArith tFois ExprArith	{printf("Opération pas encore gérée\n") ;}
            | ExprArith tDivise ExprArith	{printf("Opération pas encore gérée\n") ;}
            | ExprArith tOu ExprArith	{printf("Opération pas encore gérée\n") ;}
            | ExprArith tEt ExprArith	{printf("Opération pas encore gérée\n") ;}
            | ExprArith tDoubleEgal ExprArith	{printf("Opération pas encore gérée\n") ;}
            | tId	{variable_declaree($1) ;}
            | tEntier {valeur_directe($1) ;}
						| tPo ExprArith tPf

If		    : tIf tPo ExprArith tPf Body 
            | tIf tPo ExprArith tPf Body tElse Body

While		: tWhile tPo ExprArith tPf Body 

Affect		: tId tEgal ExprArith tPvir	{affectation($1) ;}

Dec	        : tInt Dec1 tPvir 
            | tInt DecN tPvir 

DecN		: Dec1 
            | Dec1 tVir DecN

Dec1		: tId {memoriser_id($1) ;}
            | tId {memoriser_id($1); /*pas sûr si c'est au bon endroit... :/*/} tEgal ExprArith {affectation($1) ;}

%%

int main(void) 
{
	init_table_symbole() ;
	return yyparse();
}

void yyerror(char *s) {printf("Erreur : %s", s);}
