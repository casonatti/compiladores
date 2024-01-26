/*
Autor: Jeison Casonatti Caroly
Data: 19/01/2024
Disciplina: Compiladores B
Etapa 5
*/

#ifndef TAC_H
#define TAC_H

#include <stdlib.h>
#include "ast.h"
#include "hash.h"

enum TAC_ENUM {
  TAC_SYMBOL,
  TAC_MOVE,
  TAC_BEGINFUN,
  TAC_ENDFUN,
  TAC_CALL,
  TAC_JUMP,
  TAC_LABEL,
  TAC_PARAMPOP,
  TAC_ADD,
  TAC_SUB,
  TAC_MUL,
  TAC_DIV,
  TAC_GT,
  TAC_LT,
  TAC_GE,
  TAC_LE,
  TAC_EQ,
  TAC_DIF,
  TAC_AND,
  TAC_OR,
  TAC_NOT,
  TAC_RET,
  TAC_ARGPUSH,
  TAC_IF,
  TAC_ARG,
  TAC_PRINT,
  TAC_INPUT,
  TAC_VECATTR,
  TAC_VEC
};

typedef struct tac {
  int type;
  HASH_NODE* res;
  HASH_NODE* op_1;
  HASH_NODE* op_2;
  struct tac* previous;
  struct tac* next;
} TAC;

TAC* newTac(int type, HASH_NODE* res, HASH_NODE* op_1, HASH_NODE* op_2);
TAC* tacUnion(TAC* list_1, TAC* list_2);
TAC* rewindTac(TAC* list);
TAC* createTac(AST* node, HASH_NODE* currentLabel);
void printTac(TAC* list);
void generatedTac(TAC* list);

TAC* createBinOp(int type, TAC* son[]);
TAC* createIf(TAC* son[]);
TAC* createLoop(TAC* son[], HASH_NODE* label);
TAC* createFunction(TAC* symbol, TAC* params, TAC* code);

#endif