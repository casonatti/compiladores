/*
Codigo gerado pelo professor Marcelo Johann em aula.
*/

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