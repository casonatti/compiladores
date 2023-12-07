#ifndef AST_H
#define AST_H

#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

#define MAX_SONS 4

enum AST_ENUM {
  AST_SYMBOL,
  AST_ADD,
  AST_SUB,
  AST_DIV,
  AST_MUL,
  AST_DIF,
  AST_EQ,
  AST_LE,
  AST_GE,
  AST_LT,
  AST_GT,
  AST_AND,
  AST_OR,
  AST_NOT,
  AST_PAREN,
  AST_VEC,
  AST_FUN,
  AST_CHAR,
  AST_INT,
  AST_FLOAT,
  AST_ARGLSTINIT,
  AST_ARGLST,
  AST_CMDLST,
  AST_BLOCK,
  AST_DECVAR,
  AST_DECVEC,
  AST_DECPROTO,
  AST_OPT,
  AST_LSTPARAMINIT,
  AST_LSTPARAM,
  AST_PARAM,
  AST_ATTR,
  AST_VECATTR,
  AST_CODE,
  AST_INPUT,
  AST_PRINT,
  AST_IF,
  AST_ELSE,
  AST_WHILE,
  AST_RETURN,
  AST_LSTDECGLOB,
  AST_LSTDEC,
  AST_LSTCODE
};

typedef struct ast_node {
  int type;
  HASH_NODE* symbol;
  struct ast_node* son[MAX_SONS];
} AST;

AST* astCreate(int type, HASH_NODE* symbol, AST* son0, AST* son1, AST* son2, AST* son3);
void astPrint(AST* node, int level);

#endif