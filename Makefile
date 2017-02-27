CC=gcc

all: compilator y.output y.dot

y.output y.dot y.tab.h y.tab.c: langage-c_yacc.y
	yacc -dvg langage-c_yacc.y

lex.yy.c: langage-c_lex.l y.tab.h
	lex langage-c_lex.l

compilator: lex.yy.o y.tab.o table-symbole.c
	$(CC) -o compilator lex.yy.o y.tab.o table-symbole.c

clean:
	rm *.o

test: compilator
	./compilator < input
