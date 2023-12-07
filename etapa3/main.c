/*
Autor: Jeison Casonatti Caroly
Data: 06/12/2023
Disciplina: Compiladores B
Etapa 3
*/

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
//#include "y.tab.h"

//lex.yy.h
//int yylex();
extern int yyparse();
extern char* yytext;
extern FILE* yyin;
extern FILE* file();
extern AST* getAST();
extern int getLineNumber(void);
extern int isRunning(void);
extern void initMe(void);

int main(int argc, char* argv[]) {
  int token;
  int ret;
  FILE* output = 0;

  if (argc < 3) {
    printf("call: ./etapa3 <input_file> <output_file>\n");
    exit(1);
  }
  if (!(file(argv[1]))) {
    printf("Cannot open file %s...\n",argv[1]);
    exit(1);
  }
  if (!(output = fopen(argv[2], "w+"))) {
    printf("Cannot open file %s...\n",argv[1]);
    exit(1);
  }

  initMe();
  
  yyparse();

  //uncompile(output, getAST());

  fclose(output);

  exit(0);
}