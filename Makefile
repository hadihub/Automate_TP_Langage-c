CC=gcc

all: compilator y.output y.dot

y.output y.dot y.tab.h y.tab.c: langage-c_yacc.y
	yacc -dvg langage-c_yacc.y

lex.yy.c: langage-c_lex.l y.tab.h
	lex langage-c_lex.l

compilator: lex.yy.o y.tab.o
	$(CC) -o compilator lex.yy.o y.tab.o

test: compilator
	./compilator < input
