/*
Autor: Jeison Casonatti Caroly
Data: 06/12/2023
Disciplina: Compiladores B
Etapa 5
*/

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "tac.h"

extern int yyparse();
extern char* yytext;
extern FILE* yyin;
extern FILE* file();
extern AST* getAST();
extern TAC* getTACs();
extern int getLineNumber(void);
extern int isRunning(void);
extern void initMe(void);
extern int checkSemantic();

int main(int argc, char* argv[]) {
  FILE* output;

  if (argc < 3) {
    printf("call: ./etapa5 <input_file> <output_file>\n");
    exit(1);
  }
  if (!(file(argv[1]))) {
    printf("Cannot open file %s...\n",argv[1]);
    exit(1);
  }
  if (!(output = fopen(argv[2], "w"))) {
    printf("Cannot open file %s...\n",argv[1]);
    exit(1);
  }

  initMe();
  
  yyparse();

  printf("\n\nStart uncompilation\n\n");

  uncompileAST(getAST(), output);

  fclose(output);

  // printf("\n\nChecking Semantic\n\n");

  // checkSemantic();

  printf("Creating TACs\n");

  generatedTac(getTACs());

  exit(0);
}