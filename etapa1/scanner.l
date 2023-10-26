/*
Autor: Jeison Casonatti Caroly
Data: 25/11/2023
Disciplina: Compiladores B
Etapa 1
*/

%{

#include "tokens.h"

int lineNumber = 1;
int running = 1;

int getLineNumber(void) {
  return lineNumber;
}

int isRunning(void) {
  return running;
}

%}

%x COMMENT
%x COMMENT_LINE

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
[-+/*,;(){}=%<>&|~]   {return yytext[0];}

  /* operadores compostos */
"<="                  {return OPERATOR_LE;}
">="                  {return OPERATOR_GE;}
"=="                  {return OPERATOR_EQ;}
"!="                  {return OPERATOR_DIF;}

  /* literais */
(['].['])|([']['])    {return LIT_CHAR;}
[0-9]+                {return LIT_INT;}
[0-9]+[.][0-9]+       {return LIT_REAL;}
["].*["]              {return LIT_STRING;}

  /* comentarios */
"///"                 {BEGIN(COMMENT);}
"//"                  {BEGIN(COMMENT_LINE);}

  /* identificadores */
[a-zA-Z0-9_]+  {return TK_IDENTIFIER;}

  /* espacos em branco */
"\n"                  {lineNumber++;}
[ "\t"]               {}

.                     {return TOKEN_ERROR;}

<COMMENT>"\n"         {lineNumber++;}
<COMMENT>.            {}
<COMMENT>"\\\\\\"     {BEGIN(INITIAL);}

<COMMENT_LINE>"\n"    {lineNumber++; BEGIN(INITIAL);}
<COMMENT_LINE>.       {}

%%

#include "main.c"

int yywrap() {
  running = 0;
  return 1;
}