%{
#include "table-symboles.h"
#include "y.tab.h"
%}

%%


"if"		{return tIf;}
"else"		{return tElse;}
"while"		{return tWhile;}
"printf"	{return tPrintf;}
"const"		{return tConst;}
"{"		{return tAo;}
"}"		{return tAf;}
"("		{return tPo;}
")"		{return tPf;}
";"		{return tPvir;}
","		{return tVir;}
"/"		{return tDivise;}
"="		{return tEgal;}
"+"		{return tPlus;}
"-"		{return tMoin;}
"return"	{return tReturn;}
"int"		{return tInt;}
"=="		{return tDoubleEgal;}
"&&"		{return tEt;}
"||"		{return tOu;}
[ |\t|\n]	{}		
[0-9]+ 		{yylval.nb = atoi(yytext) ; return tEntier ; /*Ajouter la forme exponentielle*/ }
[a-z|A-Z|0-9]+	{strncpy(yylval.str, yytext, 16) ; return tId ;}

%%

int yywrap(void) {return 1;}
	
