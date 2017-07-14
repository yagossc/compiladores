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
#define ACC 500
#define STACK 100
#define REDUCE 200


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

//Stack push items
#define S2 102
#define S3 103
#define S10 110
#define S11 111
#define S12 112
#define S13 113
#define S14 114
#define S15 115
#define S16 116
#define S18 118
#define S19 119
#define S20 120
#define S21 121
#define S22 122
#define S23 123
#define S26 126
#define S27 127
#define S29 129
#define S31 131
#define S32 132
#define S33 133
#define S35 135
#define S45 145
#define S48 148
#define S51 151
#define S53 153
#define S54 154
#define S55 155
#define S57 157
#define S58 158


//Reduce items
#define R2 202
#define R3 203
#define R4 204
#define R5 205
#define R6 206
#define R7 207
#define R8 208
#define R9 209
#define R10 210
#define R11 211
#define R12  212
#define R13 213
#define R14 214
#define R15 215
#define R16 216
#define R17  217
#define R18 218
#define R19  219
#define R20 220
#define R21 221
#define R22 222
#define R23 223
#define R24 224
#define R25 225
#define R26 226
#define R27 227
#define R28 228
#define R29 229
#define R30 230

//Prodution lengths

#endif
