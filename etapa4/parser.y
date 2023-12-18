/*
Autor: Jeison Casonatti Caroly
Data: 06/12/2023
Disciplina: Compiladores B
Etapa 3
*/

%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "hash.h"
  #include "ast.h"

  int getLineNumber (void);
  int yylex(void);
  int yyerror();

  AST *root;

%}

%union {
  HASH_NODE *symbol;
  AST *ast;
}

%token KW_CHAR          
%token KW_INT           
%token KW_FLOAT         
%token KW_CODE          
%token KW_IF            
%token KW_ELSE          
%token KW_WHILE         
%token KW_INPUT         
%token KW_PRINT         
%token KW_RETURN        

%token OPERATOR_LE      
%token OPERATOR_GE      
%token OPERATOR_EQ      
%token OPERATOR_DIF     

%token <symbol>TK_IDENTIFIER    

%token <symbol> LIT_INT          
%token <symbol> LIT_REAL         
%token <symbol> LIT_CHAR         
%token <symbol> LIT_STRING       

%token TOKEN_ERROR

%type <ast> programa
%type <ast> ldecl_globais
%type <ast> lista_decl
%type <ast> decl_var
%type <ast> decl_vetor
%type <ast> decl_proto
%type <ast> opcional
%type <ast> lparam
%type <ast> fim_param
%type <ast> param
%type <ast> lista_code
%type <ast> decl_func
%type <ast> cmd
%type <ast> cmd_atribuicao
%type <ast> cmd_print
%type <ast> aux_print
%type <ast> cmd_return
%type <ast> cmd_ctrl_fluxo
%type <ast> cmd_if
%type <ast> tail
%type <ast> bloco
%type <ast> lista_cmd
%type <ast> expr
%type <ast> lista_args
%type <ast> lista_args_fim
%type <ast> tipo
%type <ast> literal

%left '<' '>' '&' '|' '~' OPERATOR_DIF OPERATOR_EQ OPERATOR_GE OPERATOR_LE
%left '+' '-'
%left '*' '/'

%%

programa: ldecl_globais                                           {root=$$; astPrint(root, 0);}
          ;

ldecl_globais:  lista_decl lista_code                             {$$=astCreate(AST_LSTDECGLOB, 0, $1, $2, 0, 0);}
                ;

lista_decl: decl_var lista_decl                                   {$$=astCreate(AST_LSTDEC, 0, $1, $2, 0, 0);}
            | decl_vetor lista_decl                               {$$=astCreate(AST_LSTDEC, 0, $1, $2, 0, 0);}
            | decl_proto lista_decl                               {$$=astCreate(AST_LSTDEC, 0, $1, $2, 0, 0);}
            |                                                     {$$=0;}
            ;

decl_var: tipo TK_IDENTIFIER '=' literal ';'                      {$$=astCreate(AST_DECVAR, $2, $1, $4, 0, 0);}
          ;

decl_vetor: tipo TK_IDENTIFIER '[' LIT_INT ']' opcional ';'       {$$=astCreate(AST_DECVEC, $2, $1, astCreate(AST_SYMBOL, $4, 0, 0, 0, 0), $6, 0);}
            ;

decl_proto: tipo TK_IDENTIFIER '(' lparam ')' ';'                 {$$=astCreate(AST_DECPROTO, $2, $1, $4, 0, 0);}
            ;

opcional: literal opcional                                        {$$=astCreate(AST_OPT, 0, $1, $2, 0, 0);}
          |                                                       {$$=0;}
          ;

lparam: param fim_param                                           {$$=astCreate(AST_LSTPARAMINIT, 0, $1, $2, 0, 0);}
        |                                                         {$$=0;}
        ;

fim_param:  ',' param fim_param                                   {$$=astCreate(AST_LSTPARAM, 0, $2, $3,0 , 0);}
            |                                                     {$$=0;}
            ;

param:  tipo TK_IDENTIFIER                                        {$$=astCreate(AST_PARAM, $2, $1, 0, 0, 0);}
        ;

lista_code: decl_func lista_code                                  {$$=astCreate(AST_LSTCODE, 0, $1, $2, 0, 0);}
            |                                                     {$$=0;}
            ;

decl_func:  KW_CODE TK_IDENTIFIER cmd                             {$$=astCreate(AST_CODE, $2, $3, 0, 0, 0);}
            ;

cmd:  cmd_atribuicao                                              {$$=$1;}
      | cmd_print                                                 {$$=$1;}
      | cmd_return                                                {$$=$1;}
      | cmd_ctrl_fluxo                                            {$$=$1;}
      | bloco                                                     {$$=$1;}
      | ';'                                                       {$$=0;}
      ;

cmd_atribuicao: TK_IDENTIFIER '=' expr ';'                        {$$=astCreate(AST_ATTR, $1, $3, 0, 0, 0);}
                | TK_IDENTIFIER '[' expr ']' '=' expr ';'         {$$=astCreate(AST_VECATTR, $1, $3, $6, 0, 0);}
                ;

cmd_print:  KW_PRINT aux_print ';'                                {$$=astCreate(AST_PRINT, 0, $2, 0, 0, 0);}

aux_print:  LIT_STRING                                            {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
            | expr                                                {$$=$1;}
            ;

cmd_return: KW_RETURN expr ';'                                    {$$=astCreate(AST_RETURN, 0, $2, 0, 0, 0);}
            ;

cmd_ctrl_fluxo: cmd_if                                            {$$=$1;}
                | KW_WHILE '(' expr ')' cmd                       {$$=astCreate(AST_WHILE, 0, $3, $5, 0, 0);}
                ;

cmd_if: KW_IF '(' expr ')' cmd tail                               {$$=astCreate(AST_IF, 0, $3, $5, $6, 0);}
        ;

tail: KW_ELSE cmd                                                 {$$=astCreate(AST_ELSE, 0, $2, 0, 0, 0);}
      |                                                           {$$=0;}
      ;

bloco:  '{' lista_cmd '}'                                         {$$=astCreate(AST_BLOCK, 0, $2, 0, 0, 0);}
        ;

lista_cmd:  cmd lista_cmd                                         {$$=astCreate(AST_CMDLST, 0, $1, $2, 0, 0);}
            |                                                     {$$=0;}
            ;

expr: expr '+' expr                                               {$$=astCreate(AST_ADD, 0, $1, $3, 0, 0);}
      | expr '-' expr                                             {$$=astCreate(AST_SUB, 0, $1, $3, 0, 0);}
      | expr '/' expr                                             {$$=astCreate(AST_DIV, 0, $1, $3, 0, 0);}
      | expr '*' expr                                             {$$=astCreate(AST_MUL, 0, $1, $3, 0, 0);}
      | expr '<' expr                                             {$$=astCreate(AST_LT, 0, $1, $3, 0, 0);}
      | expr '>' expr                                             {$$=astCreate(AST_GT, 0, $1, $3, 0, 0);}
      | expr '&' expr                                             {$$=astCreate(AST_AND, 0, $1, $3, 0, 0);}
      | expr '|' expr                                             {$$=astCreate(AST_OR, 0, $1, $3, 0, 0);}
      | expr '~' expr                                             {$$=astCreate(AST_NOT, 0, $1, $3, 0, 0);}
      | expr OPERATOR_DIF expr                                    {$$=astCreate(AST_DIF, 0, $1, $3, 0, 0);}
      | expr OPERATOR_EQ expr                                     {$$=astCreate(AST_EQ, 0, $1, $3, 0, 0);}
      | expr OPERATOR_GE expr                                     {$$=astCreate(AST_GE, 0, $1, $3, 0, 0);}
      | expr OPERATOR_LE expr                                     {$$=astCreate(AST_LE, 0, $1, $3, 0, 0);}
      | KW_INPUT '(' tipo ')'                                     {$$=astCreate(AST_INPUT, 0, $3, 0, 0, 0);}
      | TK_IDENTIFIER                                             {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
      | TK_IDENTIFIER '(' lista_args ')'                          {$$=astCreate(AST_FUN, $1, $3, 0, 0, 0);}
      | TK_IDENTIFIER '[' expr ']'                                {$$=astCreate(AST_VEC, $1, $3, 0, 0, 0);}
      | LIT_CHAR                                                  {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
      | LIT_INT                                                   {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
      | LIT_REAL                                                  {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
      | '(' expr ')'                                              {$$=astCreate(AST_PAREN, 0, $2, 0, 0, 0);}
      ;

lista_args: expr lista_args_fim                                   {$$=astCreate(AST_ARGLSTINIT, 0, $1, $2, 0, 0);}
            |                                                     {$$=0;}
            ;

lista_args_fim: ',' expr lista_args_fim                           {$$=astCreate(AST_ARGLST, 0, $2, $3, 0, 0);}
                |                                                 {$$=0;}
                ;

tipo: KW_CHAR                                                     {$$=astCreate(AST_CHAR, 0, 0, 0, 0, 0);}
      | KW_INT                                                    {$$=astCreate(AST_INT, 0, 0, 0, 0, 0);}
      | KW_FLOAT                                                  {$$=astCreate(AST_FLOAT, 0, 0, 0, 0, 0);}
      ;

literal:  LIT_CHAR                                                {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
          | LIT_INT                                               {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
          | LIT_REAL                                              {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
          | LIT_STRING                                            {$$=astCreate(AST_SYMBOL, $1, 0, 0, 0, 0);}
          ;


%%

int yyerror() {
  printf("Erro sintatico na linha %d\n", getLineNumber());
  exit(3);
}

AST * getAST() {
  return root;
}