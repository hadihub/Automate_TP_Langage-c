%{
#include <stdio.h>
#include "table-symboles.h"
void yyerror (char *s);
%}

%union {int nb; char *str; /*apparemment, c'est obligatoire... (pas testé sans)*/}

%token tMain
%token tIf
%token tElse
%token tWhile
%token tAo
%token tAf
%token tPo
%token tPf
%token tVir
%token tPvir
%token tEgal
%token tDivise
%token tMoin
%token tPlus
%token tFois
%token tReturn
%token tInt
%token tEt
%token tOu
%token tDoubleEgal
%token tConst
%token tPrintf
%token tEntier
%token tId
%start Start
%left  tMoin tPlus
%left  tFois tDivise

%%

Start		: Prog

Prog		: Fonctions	{printf("Prog detected\n");}

Fonctions	: %empty
		| Fonction Fonctions

Fonction	: tInt tId tPo Args tPf Body	{printf("Fonction detected\n");}

Args		: %empty
		| tInt tId ListArgs

ListArgs	: %empty	 
		| tVir tInt tId ListArgs

Body		: tAo Instructions tAf 	{printf("Body detected\n");}

Instructions	: %empty
		| Instruction Instructions  	{printf("Instr detected\n");}

Instruction	: Dec
		| If
		| While
		| Affect 	{printf("Affect detected\n");}
		| Invoc

Invoc		: tId tPo Params tPf tPvir	{printf("Trouvé invocation\n");}

Params		: %empty
		| Param
		| Param tVir ListParams

ListParams 	: Param
		| Param tVir ListParams

Param		: ExprArith {printf("Trouvé paramètre\n");}

ExprArith 	: ExprArith tPlus  ExprArith  {printf("Trouvé expression arithmétique plus\n");}
		| ExprArith tMoin  ExprArith {printf("Trouvé expression arithmétique moins\n");}
		| ExprArith tFois  ExprArith
		| ExprArith tDivise  ExprArith
		| ExprArith tOu ExprArith
		| ExprArith tEt  ExprArith
		| ExprArith tDoubleEgal  ExprArith
		| tId
		| tEntier

If		: tIf tPo ExprArith tPf Body {printf("Trouvé if\n");}
		| tIf tPo ExprArith tPf Body tElse Body

While		: tWhile tPo ExprArith tPf Body {printf("Trouvé while\n");}

Affect		: tId tEgal ExprArith tPvir  {printf("Trouvé affectation\n");}

Dec		: tInt Dec1 tPvir {printf("Trouvé declaration type 1\n");}
		| tInt DecN tPvir {printf("Trouvé declaration type 2\n");}

DecN		: Dec1 {printf("trouvé DecN\n");}
		| Dec1 tVir DecN

Dec1		: tId
		| tId tEgal ExprArith

%%

int main(void) {return yyparse();}

void yyerror(char *s) {printf("Erreur : %s", s);}
