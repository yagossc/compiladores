#ifndef TABLE_H
#define TABLE_H

int trans_table[12][19] = 
{/*	L |  D | . | ESPAÇO | TAB | \n |"*//* | _ | EOF | { | } | < | - | OP_R | OP_A | ( | ) | ; | OUTRO |*/
/*init*/ ID, INT, ERROR, _init_, END, _init_, STR, ERROR, _eof_, COMMENT, ERROR, _ATRIB_, ARITM, OPER, ARITM, END, END, END, ERROR,
/*ID*/	ID, ID, ERROR, END, END, END, ERROR, ID, _eof_, COMMENT, ERROR, END, END, END, END, END, END, END, ERROR,
/*INT*/ ERROR, INT, REAL, END, END, END, ERROR, ERROR, _eof_, COMMENT, ERROR, END, END, END, END, ERROR, END, END, ERROR,
/*REAL*/ ERROR, REAL, ERROR, END, END, END, ERROR, ERROR, _eof_, COMMENT, ERROR, END, END, END, END, ERROR, ERROR, END, ERROR,
/*STR*/	STR, STR, STR, STR, STR, STR, END, STR, ERROR, STR, STR, STR, STR, STR, STR, STR, STR, STR, STR,
/*_ATRIB_*/ END, END, ERROR, END, END, END, ERROR, ERROR, _eof_, COMMENT, ERROR, ERROR, ATRIB, END, ERROR, END, END, END, ERROR,
/*ATRIB*/ END, END, ERROR, END, END, END, END, ERROR, _eof_, COMMENT, ERROR, ERROR, ERROR, ERROR, ERROR, END, ERROR, END, ERROR,
/*OPER*/ END, END, ERROR, END, END, END, ERROR, ERROR, _eof_, COMMENT, ERROR, ERROR, ERROR, OPER, ERROR, END, ERROR, ERROR, ERROR,
/*ARITM*/ END, END, ERROR, END, END, END, ERROR, ERROR, _eof_, COMMENT, ERROR, ERROR, ERROR, ERROR, ERROR, END, END, END, ERROR,
/*COMMENT*/ COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, ERROR, COMMENT, END, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT, COMMENT , COMMENT,
/*ERROR*/ END, END, END, END, END, END, END, END, END, END, END, END, END, END, END, END, END, END, END,
/*EOF*/  END, END, END, END, END, END, END, END, END, END, END, END, END, END, END, END, END, END, END,
};

#endif
