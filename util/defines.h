#ifndef DEFINES_H
#define DEFINES_H

//Lexic analyzer MACROS
#define _init_ 0
#define ID 1
#define INT 2
#define _REAL_ 3
#define REAL 4
#define _EXP_ 5
#define EXP_S 6
#define EXP 7
#define STR 8
#define _ATRIB_ 9
#define ATRIB 10
#define _OPER_ 11
#define OPER 12
#define ARITM 13
#define COMMENT 14
#define ERROR 15
#define _eof_ 16
#define AB_P 17
#define FC_P 18
#define PT_V 19
#define END -1
#define SIZE 4096
#define MAX_ID 64
#define BUFFER 256

//Sintatic analyzer MACROS

//System defines
#define OK 200
#define ERR 406
#define ACC 202


//Terminals
//In struct Token: int token_name;
#define inicio 0
#define varinicio 1
#define varfim 2
#define _id_ 3
#define _int_ 4
#define _real_ 5
#define _lit_ 6
#define leia 7
#define escreva 8
#define literal 9
#define num 10
#define rcb 11
#define ab_p 12
#define fc_p 13
#define opr 14
#define opm 15
#define pt_v 16
#define se 17
#define entao 18
#define fimse 19
#define fim 20
#define $ 21

//Non-Terminals
#define NTerm 22
#define P 22
#define V 23
#define A 24
#define LV 25
#define D 26
#define TIPO 27
#define ES 28
#define ARG 29
#define CMD 30
#define OPRD 31
#define LD 32
#define COND 33
#define CABECALHO 34
#define CORPO 35
#define EXP_R 36

//Stack/empilha
//...

//Prodution lengths

#endif
