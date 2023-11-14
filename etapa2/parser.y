%{
  #include <stdio.h>
  #include <stdlib.h>

  int getLineNumber (void);
  int yylex(void);
  int yyerror();
%}

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

%token TK_IDENTIFIER    

%token LIT_INT          
%token LIT_REAL         
%token LIT_CHAR         
%token LIT_STRING       

%token TOKEN_ERROR

%left '<' '>' '&' '|' '~' OPERATOR_DIF OPERATOR_EQ OPERATOR_GE OPERATOR_LE
%left '+' '-'
%left '*' '/'

%%

programa: ldecl_globais
          ;

ldecl_globais:  lista_decl lista_code
                ;

lista_decl: decl_var lista_decl
            | decl_vetor lista_decl
            | decl_proto lista_decl
            |
            ;

decl_var: tipo TK_IDENTIFIER '=' literal ';'
          ;

decl_vetor: tipo TK_IDENTIFIER '[' LIT_INT ']' opcional ';'
            ;

decl_proto: tipo TK_IDENTIFIER '(' lparam ')' ';'
            ;

opcional: literal opcional
          |
          ;

lparam: param fim_param
        |
        ;

fim_param:  ',' param fim_param
            |
            ;

param:  tipo TK_IDENTIFIER
        ;

lista_code: decl_func lista_code
            |
            ;

decl_func:  KW_CODE TK_IDENTIFIER cmd
            ;

cmd:  cmd_atribuicao
      | cmd_print
      | cmd_return
      | cmd_ctrl_fluxo
      | bloco
      | ';'
      ;

cmd_atribuicao: TK_IDENTIFIER '=' expr ';'
                | TK_IDENTIFIER '[' expr ']' '=' expr ';'
                ;

cmd_print:  KW_PRINT aux_print ';'

aux_print:  LIT_STRING
            | expr
            ;

cmd_return: KW_RETURN expr ';'
            ;

cmd_ctrl_fluxo: cmd_if
                | KW_WHILE '(' expr ')' cmd
                ;

cmd_if: KW_IF '(' expr ')' cmd tail
        ;

tail: KW_ELSE cmd
      |
      ;

bloco:  '{' lista_cmd '}'
        ;

lista_cmd:  cmd lista_cmd
            |
            ;

expr: expr '+' expr
      | expr '-' expr
      | expr '/' expr
      | expr '*' expr
      | expr '<' expr
      | expr '>' expr
      | expr '&' expr
      | expr '|' expr
      | expr '~' expr
      | expr OPERATOR_DIF expr
      | expr OPERATOR_EQ expr
      | expr OPERATOR_GE expr
      | expr OPERATOR_LE expr
      | KW_INPUT '(' tipo ')'
      | TK_IDENTIFIER
      | TK_IDENTIFIER '(' lista_args ')'
      | TK_IDENTIFIER '[' expr ']'
      | LIT_CHAR
      | LIT_INT
      | LIT_REAL
      // | LIT_STRING /* se descomentar da conflito reduce/reduce */
      | '(' expr ')'
      ;

lista_args: expr lista_args_fim
            |
            ;

lista_args_fim: ',' expr lista_args_fim
                |
                ;

tipo: KW_CHAR
      | KW_INT
      | KW_FLOAT
      ;

literal:  LIT_CHAR
          | LIT_INT
          | LIT_REAL
          | LIT_STRING
          ;


%%

int yyerror() {
  printf("Erro sintatico na linha %d\n", getLineNumber());
  exit(3);
}