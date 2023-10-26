/*
Autor: Jeison Casonatti Caroly
Data: 26/11/2023
Disciplina: Compiladores B
Etapa 1
*/

#include <stdio.h>
#include <stdlib.h>

//lex.yy.h
int yylex();
extern char *yytext;
extern FILE *yyin;

int getLineNumber(void);
int isRunning(void);
void initMe(void);

int main(int argc, char** argv) {
  int token;
  FILE* output = 0;

  if (argc < 3)
  {
    printf("call: ./etapa1 input.txt output.txt \n");
    exit(1);
  }
  if (0==(yyin = fopen(argv[1],"r")))
  {
    printf("Cannot open file %s... \n",argv[1]);
    exit(1);
  }
  if (0==(output = fopen(argv[2],"w")))
  {
    printf("Cannot open file %s... \n",argv[2]);
    exit(1);
  }
  
  while(isRunning()) {
    token = yylex(); 

    if(!isRunning()) break;

    switch(token) {
      case ',': 
      case ';': 
      case '(':
      case ')': 
      case '[':
      case ']': 
      case '{':
      case '}': 
      case '=':
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
      case '<':
      case '>':
      case '&':
      case '|':
      case '~':	printf("%c\n", token); break;
      case KW_CHAR: printf("KW_CHAR | %s\n", yytext); fprintf(output, "KW_CHAR | %s\n", yytext); break;
      case KW_INT: printf("KW_INT | %s\n", yytext); fprintf(output, "KW_INT | %s\n", yytext); break;
      case KW_FLOAT: printf("KW_FLOAT | %s\n", yytext); fprintf(output, "KW_FLOAT | %s\n", yytext); break;
      case KW_IF: printf("KW_IF | %s\n", yytext); fprintf(output, "KW_IF | %s\n", yytext); break;
      case KW_ELSE: printf("KW_ELSE | %s\n", yytext); fprintf(output, "KW_ELSE | %s\n", yytext); break;
      case KW_WHILE: printf("KW_WHILE | %s\n", yytext); fprintf(output, "KW_WHILE | %s\n", yytext); break;
      case KW_CODE: printf("KW_CODE | %s\n", yytext); fprintf(output, "KW_CODE | %s\n", yytext); break;
      case KW_INPUT: printf("KW_INPUT | %s\n", yytext); fprintf(output, "KW_INPUT | %s\n", yytext); break;
      case KW_PRINT: printf("KW_PRINT | %s\n", yytext); fprintf(output, "KW_PRINT | %s\n", yytext); break;
      case KW_RETURN: printf("KW_RETURN | %s\n", yytext); fprintf(output, "KW_RETURN | %s\n", yytext); break;
      case OPERATOR_LE: printf("OPERATOR_LE | %s\n", yytext); fprintf(output, "OPERATOR_LE | %s\n", yytext); break;
      case OPERATOR_GE: printf("OPERATOR_GE | %s\n", yytext); fprintf(output, "OPERATOR_GE | %s\n", yytext); break;
      case OPERATOR_EQ: printf("OPERATOR_EQ | %s\n", yytext); fprintf(output, "OPERATOR_EQ | %s\n", yytext); break;
      case OPERATOR_DIF: printf("OPERATOR_DIF | %s\n", yytext); fprintf(output, "OPERATOR_DIF | %s\n", yytext); break;
      case TK_IDENTIFIER: printf("TK_IDENTIFIER | %s\n", yytext); fprintf(output, "TK_IDENTIFIER | %s\n", yytext); break;
      case LIT_INT: printf("LIT_INT | %s\n", yytext); fprintf(output, "LIT_INT | %s\n", yytext); break;
      case LIT_REAL: printf("LIT_REAL | %s\n", yytext); fprintf(output, "LIT_REAL | %s\n", yytext); break;
      case LIT_CHAR: printf("LIT_CHAR | %s\n", yytext); fprintf(output, "LIT_CHAR | %s\n", yytext); break;
      case LIT_STRING: printf("LIT_STRING | %s\n", yytext); fprintf(output, "LIT_STRING | %s\n", yytext); break;
      case TOKEN_ERROR: printf("TOKEN_ERROR | %s\n", yytext); fprintf(output, "TOKEN_ERROR | %s\n", yytext); break;
      default: printf("Default...\n"); return 1;
    }

  }
  hashPrint();
  printf("Esse programa tinha %d linhas\n", getLineNumber());

  return 0;
}