/*
Codigo gerado pelo professor Marcelo Johann em aula.
*/

#ifndef HASH_H
#define HASH_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HASH_SIZE 997

typedef struct hash_node {
  int type;
  char* text;
  struct hash_node* next;
} HASH_NODE;

void hashInit(void);
HASH_NODE *hashInsert(int type, char* text);
HASH_NODE *hashFind(char* text);
int hashAddress(char* text);
void hashPrint(void);

#endif