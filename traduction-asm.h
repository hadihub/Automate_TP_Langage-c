#ifndef TRADUC_ASM_H
#define TRADUC_ASM_H

#define TAILLE_MAX_PROG 1024

#define ADD 0x01
#define MUL 0x02
#define SOU 0x03
#define DIV 0x04
#define COP 0x05
#define AFC 0x06
#define LOAD 0x07
#define STORE 0x08
#define EQU 0x09
#define INF 0xA
#define INFE 0xB
#define SUP 0xC
#define SUPE 0xD
#define JMP 0xE
#define JMPC 0xF



void expr_nb (int nb) ;

#endif // TRADUC_ASM_H
