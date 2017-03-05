%{
#include <stdio.h>
#include "table-symboles.h"
void yyerror (char *s);
int gLvl = 0; // variable global qui retient le niveau de profondeur
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

Prog		: Fonctions {printf("Prog detected\n"); affiche_table_symboles();}

Fonctions	: %empty
            | Fonction Fonctions

Fonction	: tInt tId tPo Args tPf Body 
Args		: %empty
            | tInt tId ListArgs

ListArgs	: %empty	 
            | tVir tInt tId ListArgs

Body		: tAo {gLvl++;} Instructions tAf {gLvl--; affiche_table_symboles(); free_symbole(gLvl+1);}

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

ExprArith 	: ExprArith tPlus ExprArith 
            | ExprArith tMoin ExprArith 
            | ExprArith tFois ExprArith
            | ExprArith tDivise ExprArith
            | ExprArith tOu ExprArith
            | ExprArith tEt ExprArith
            | ExprArith tDoubleEgal ExprArith
            | tId
            | tEntier

If		    : tIf tPo ExprArith tPf Body 
            | tIf tPo ExprArith tPf Body tElse Body

While		: tWhile tPo ExprArith tPf Body 

Affect		: tId tEgal ExprArith tPvir 

Dec	        : tInt Dec1 tPvir 
            | tInt DecN tPvir 

DecN		: Dec1 
            | Dec1 tVir DecN

Dec1		: tId {load_variable_declaree($1);}
            | tId tEgal ExprArith {load_variable_declaree($1);}

%%

int main(void) 
{
	init_table_symbole() ;
	return yyparse();
}

void yyerror(char *s) {printf("Erreur : %s", s);}
