/*
Autor: Jeison Casonatti Caroly
Data: 25/11/2023
Disciplina: Compiladores B
Etapa 1
*/

%{

#include "y.tab.h"
#include "hash.c"

int lineNumber = 1;
int running = 1;

int getLineNumber(void) {
  return lineNumber;
}

int isRunning(void) {
  return running;
}

int yyerror();

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
\[|\]                 {return yytext[0];}

  /* operadores compostos */
"<="                  {return OPERATOR_LE;}
">="                  {return OPERATOR_GE;}
"=="                  {return OPERATOR_EQ;}
"!="                  {return OPERATOR_DIF;}

  /* literais */
(['].['])|([']['])    {hashInsert(LIT_CHAR, yytext); return LIT_CHAR;}
[0-9]+                {hashInsert(LIT_INT, yytext); return LIT_INT;}
[0-9]+[.][0-9]+       {hashInsert(LIT_REAL, yytext); return LIT_REAL;}
["](\\.|[^\"\\])*["]  {hashInsert(LIT_STRING, yytext); return LIT_STRING;}

  /* comentarios */
"///"                 {BEGIN(COMMENT);}
"//"                  {BEGIN(COMMENT_LINE);}

  /* identificadores */
[a-zA-Z0-9_]+  {hashInsert(TK_IDENTIFIER, yytext); return TK_IDENTIFIER;}

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

void initMe(void) {
  hashInit();
}

#include "main.c"

int yywrap() {
  running = 0;
  return 1;
}