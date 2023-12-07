#ifndef AST_H
#define AST_H

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
  AST_KWCHAR,
  AST_KWINT,
  AST_KWFLOAT,
  AST_ARGLSTINIT,
  AST_ARGLST,
  AST_CMDLST,
  AST_BLOCK
};

typedef struct ast_node {
  int type;
  HASH_NODE* symbol;
  struct ast_node* son[MAX_SONS];
} AST;

AST* astCreate(int type, HASH_NODE* symbol, AST* son0, AST* son1, AST* son2, AST* son3);
void astPrint(AST* node, int level);

#endif