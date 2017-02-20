%{
#include <stdio.h>
void yyerror (char *s) ;
%}

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
%token tNombre
%token tId

%start start

%%

start		: Prosudog

Prog		: Fonctions

Fonctions	: %empty
		| Fonction Fonctions

Fonction	: tInt tId tPo Args tPf Body

Args		: %empty
		| tInt tId ListArgs

ListArgs	: %empty	 
		| tVir tInt tId ListArgs

Body		: tAo Instructions tAf

Instructions	: %empty
		| Instructions Instructions
		| Dec
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

ExprArith 	: ExprArith tPlus  ExprArith
		| ExprArith tMoin  ExprArith
		| ExprArith tFois  ExprArith
		| ExprArith tDivise  ExprArith
		| ExprArith tOu ExprArith
		| ExprArith tEt  ExprArith
		| ExprArith tDoubleEgal  ExprArith

If		: tIf tPo ExprArith tPf Body
		| tIf tPo ExprArith tPf Body tElse Body

While		: tWhile tPo ExprArith tPf Body

Affect		: tId tEgal ExprArith tPvir

Dec		: tInt Dec DecN tPvir

Dec1		: tId
		| tId tEgal ExprArith

DecN		: Dec1
		| Dec1 tVir DecN

%%

void main(void) {yyparse();}

void yyerror(char *s) {printf("Erreur : %s", s);}
