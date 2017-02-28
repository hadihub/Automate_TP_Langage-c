/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tMain = 258,
    tIf = 259,
    tElse = 260,
    tWhile = 261,
    tAo = 262,
    tAf = 263,
    tPo = 264,
    tPf = 265,
    tVir = 266,
    tPvir = 267,
    tEgal = 268,
    tDivise = 269,
    tMoin = 270,
    tPlus = 271,
    tFois = 272,
    tReturn = 273,
    tInt = 274,
    tEt = 275,
    tOu = 276,
    tDoubleEgal = 277,
    tConst = 278,
    tPrintf = 279,
    tEntier = 280,
    tId = 281
  };
#endif
/* Tokens.  */
#define tMain 258
#define tIf 259
#define tElse 260
#define tWhile 261
#define tAo 262
#define tAf 263
#define tPo 264
#define tPf 265
#define tVir 266
#define tPvir 267
#define tEgal 268
#define tDivise 269
#define tMoin 270
#define tPlus 271
#define tFois 272
#define tReturn 273
#define tInt 274
#define tEt 275
#define tOu 276
#define tDoubleEgal 277
#define tConst 278
#define tPrintf 279
#define tEntier 280
#define tId 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 7 "langage-c_yacc.y" /* yacc.c:1909  */
int nb; char *str; /*apparemment, c'est obligatoire... (pas testé sans)*/

#line 109 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
