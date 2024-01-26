/*
Autor: Jeison Casonatti Caroly
Data: 06/12/2023
Disciplina: Compiladores B
Etapa 3
*/

#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

#define MAX_SONS 4

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_SUB 3
#define AST_DIV 4
#define AST_MUL 5
#define AST_DIF 6
#define AST_EQ 7
#define AST_LE 8
#define AST_GE 9
#define AST_LT 10
#define AST_GT 11
#define AST_AND 12
#define AST_OR 13 
#define AST_NOT 14
#define AST_PAREN 15
#define AST_VEC 16
#define AST_FUN 17
#define AST_CHAR 18
#define AST_INT 19
#define AST_FLOAT 20
#define AST_ARGLSTINIT 21
#define AST_ARGLST 22
#define AST_CMDLST 23 
#define AST_BLOCK 24
#define AST_DECVAR 25
#define AST_DECVEC 26
#define AST_DECPROTO 27
#define AST_OPT 28
#define AST_LSTPARAMINIT 29
#define AST_LSTPARAM 30
#define AST_PARAM 31
#define AST_ATTR 32 
#define AST_VECATTR 33
#define AST_CODE 34
#define AST_INPUT 35 
#define AST_PRINT 36
#define AST_IF 37
#define AST_ELSE 38
#define AST_WHILE 39
#define AST_RETURN 40
#define AST_LSTDECGLOB 41
#define AST_LSTDEC 42
#define AST_LSTCODE 43

typedef struct ast_node {
  int type;
  int dataType;
  HASH_NODE* symbol;
  struct ast_node* son[MAX_SONS];
  int lineNumber;
} AST;

AST* astCreate(int type, HASH_NODE* symbol, AST* son0, AST* son1, AST* son2, AST* son3, int lineNumber);
void astPrint(AST* node, int level);
void uncompileAST(AST* node, FILE* file);

#endif