/*
Autor: Jeison Casonatti Caroly
Data: 09/11/2023
Disciplina: Compiladores B
Etapa 2
*/

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

//lex.yy.h
int yylex();
int yyparse();
extern char *yytext;
extern FILE *yyin;

int getLineNumber(void);
int isRunning(void);
void initMe(void);

int main(int argc, char** argv) {
  int token;
  int ret;
  FILE* output = 0;

  if (argc < 2)
  {
    printf("call: ./etapa2 input_file \n");
    exit(1);
  }
  if (0==(yyin = fopen(argv[1],"r")))
  {
    printf("Cannot open file %s... \n",argv[1]);
    exit(1);
  }

  ret = yyparse();
  
  hashPrint();
  printf("Esse programa tinha %d linhas\n", getLineNumber());

  exit(0);
}