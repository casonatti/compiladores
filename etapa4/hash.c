/*
Codigo gerado pelo professor Marcelo Johann em aula.
*/

#include "hash.h"

HASH_NODE *hashTable[HASH_SIZE];

void hashInit(void) {
  int i;

  for(i = 0; i < HASH_SIZE; i++)
    hashTable[i] = 0;
}

int hashCheckUndeclared() {
  HASH_NODE *node;
	int undeclaredVariables = 0;
	for(int i = 0; i < HASH_SIZE; i++){
		if(hashTable[i] != NULL){
			for(node = hashTable[i]; node != NULL; node = node->next){
				if(node->type == SYMBOL_IDENTIFIER){
					fprintf(stderr, "Semantic error: Variable %s undeclared.\n", node->text);				
					undeclaredVariables++;
				}
			}
		}
	}

	return undeclaredVariables;	
}

HASH_NODE *hashInsert(int type, char* text) {
  HASH_NODE *newNode;
  int address = hashAddress(text);

  if((newNode = hashFind(text)) != 0)
    return newNode;

  newNode = (HASH_NODE*) calloc(1, sizeof(HASH_NODE));
  newNode->type = type;

  if(newNode->type == SYMBOL_LIT_INT)
    newNode->dataType = DATATYPE_INT;
  else if(newNode->type == SYMBOL_LIT_CHAR)
    newNode->dataType = DATATYPE_CHAR;
  else if(newNode->type == SYMBOL_LIT_REAL)
    newNode->dataType = DATATYPE_REAL; 

  newNode->text = (char*) calloc(strlen(text)+1, sizeof(char));
  strcpy(newNode->text, text);
  newNode->next = hashTable[address];
  hashTable[address] = newNode;
  
  return newNode;
}

HASH_NODE *hashFind(char* text) {
  HASH_NODE *node;
  int address = hashAddress(text);

  for(node = hashTable[address]; node; node = node->next) {
    if(strcmp(node->text, text) == 0)
      return node;
  }

  return 0;
}

int hashAddress(char* text) {
  int i;
  int address = 1;

  for(i = 0; i < strlen(text); i++) {
    address = (address * text[i]) % HASH_SIZE + 1;
  }

  return address - 1;
}

void hashPrint(void) {
  int i;
  HASH_NODE *node;

  for(i = 0; i < HASH_SIZE; i++) {
    for(node = hashTable[i]; node; node = node->next)
      printf("hashTable[%d] = %s\n", i, node->text);
  }
}