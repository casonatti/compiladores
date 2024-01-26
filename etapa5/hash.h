/*
Codigo gerado pelo professor Marcelo Johann em aula.
*/

#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HASH_SIZE 997

// enum HASH_SYMBOL_ENUM {
//   SYMBOL_LIT_INT,
//   SYMBOL_LIT_REAL,
//   SYMBOL_LIT_CHAR,
//   SYMBOL_LIT_STRING,
//   SYMBOL_IDENTIFIER,
//   SYMBOL_VAR,
//   SYMBOL_VEC,
//   SYMBOL_FUNC,
//   SYMBOL_PARAM,
//   DATATYPE_INT,
//   DATATYPE_REAL,
//   DATATYPE_CHAR,
//   DATATYPE_BOOL
// };

#define SYMBOL_LIT_INT 1 
#define SYMBOL_LIT_CHAR 2
#define SYMBOL_LIT_REAL 3
#define SYMBOL_LIT_STRING 4
#define SYMBOL_IDENTIFIER 5
#define SYMBOL_VAR 6
#define SYMBOL_VEC 7
#define SYMBOL_PROTO 8
#define SYMBOL_CODE 9
#define SYMBOL_PARAM 10
#define DATATYPE_INT 11
#define DATATYPE_REAL 12
#define DATATYPE_CHAR 13
#define DATATYPE_BOOL 14
typedef struct hash_node {
  int type;
  int dataType;
  char* text;
  struct hash_node* next;
} HASH_NODE;

void hashInit(void);
int hashCheckUndeclared();
HASH_NODE *hashInsert(int type, char* text);
HASH_NODE *hashFind(char* text);
int hashAddress(char* text);
void hashPrint(void);
HASH_NODE *makeTemp();
HASH_NODE *makeLabel();

#endif