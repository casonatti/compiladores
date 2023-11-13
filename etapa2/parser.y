%{
  #include <stdio.h>
  #include <stdlib.h>

  int getLineNumber (void);
  int yylex(void);
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


%left '+' '-'
%left '*' '/'

%%

programa: ldecl_globais
          ;

ldecl_globais:  lista_decl ldecl_proto
                ;

lista_decl: declaracao lista_decl
            |
            ;

ldecl_proto:  decl_proto ldecl_proto
              |
              ;

declaracao: tipo TK_IDENTIFIER '=' literal ';'
          | tipo TK_IDENTIFIER '[' LIT_INT ']' opcional ';'
          ;

opcional: literal opcional
          |
          ;

decl_proto: tipo TK_IDENTIFIER '(' lparam ')' ';'
            ;

lparam: param fim_param
        |
        ;

fim_param:  ',' param fim_param
            |
            ;

param:  tipo TK_IDENTIFIER
        ;

tipo: KW_CHAR
      | KW_INT
      | KW_FLOAT
      ;

literal:  LIT_CHAR
          | LIT_INT
          | LIT_REAL
          ;


%%

int yyerror() {
  printf("Erro sintatico na linha %d\n", getLineNumber());
  exit(3);
}