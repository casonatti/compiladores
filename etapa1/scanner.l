/*
Autor: Jeison Casonatti Caroly
Data: 25/11/2023
Disciplina: Compiladores B
Etapa 1
 */

%{

#include "tokens.h"
int lineNumber = 1;

%}

%x COMMENT

%%

  /* palavras reservadas */
"char"                {return KW_CHAR;}
"int"                 {return KW_INT;}
"float"               {return KW_FLOAT;}
"code"                {return KW_CODE;}
"if"                  {return KW_IF;}
"else"                {return KW_ELSE;}
"while"               {return KW_WHILE;}
"input"               {return KW_INPUT;}
"print"               {return KW_PRINT;}
"return"              {return KW_RETURN;}

  /* caracteres especiais */
[-+/*,;(){}=%<>&|~]   {printf("Achei um %c\n", yytext[0]); /* TODO */}

  /* operadores compostos */
"<="                  {return OPERATOR_LE;}
">="                  {return OPERATOR_GE;}
"=="                  {return OPERATOR_EQ;}
"!="                  {return OPERATOR_DIF;}

  /* literais */
['].*[']              {return LIT_CHAR;}
[-+]?[0-9]+           {return LIT_INT;}
[-+]?[0-9]+[.][0-9]+  {return LIT_REAL;}
["].*["]              {return LIT_STRING}

  /* comentarios */
((\/\/.*)|(\/\/\/[^(\\\\\\)]*\\\\\\))|(\/\/\/)|(\\\\\\) {printf("ACHEI ESSE DAQUI %s\n", yytext);}
  /* "///"                 {BEGIN COMMENT;} */
  /* "//".*                {} */

  /* identificadores */
[0-9_]*?[a-zA-Z_0-9]+  {return TK_IDENTIFIER;}

  /* espacos em branco */
"\n"                  {lineNumber++;}
[ "\t"]               {}

.                     {return TOKEN_ERROR;}

<COMMENT>[^.\n]* {BEGIN(INITIAL);}
<COMMENT>\n {lineNumber++;}
<COMMENT>.*"\\\\\\" {}

%%

int main() {
  yyin = fopen("teste.txt", "r");
  yylex();
  printf("Esse programa tinha %d linhas\n", lineNumber);

  return 0;
}

int yywrap() {
  return 1;
}