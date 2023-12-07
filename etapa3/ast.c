#include "ast.h"

AST* astCreate(int type, HASH_NODE* symbol, AST* son0, AST* son1, AST* son2, AST* son3) {
  AST* newnode = (AST*)calloc(1, sizeof(AST));
  newnode->type = type;
  newnode->symbol = symbol;
  newnode->son[0] = son0;
  newnode->son[1] = son1;
  newnode->son[2] = son2;
  newnode->son[3] = son3;

  return newnode;
}

void astPrint(AST* node, int level) {
  int i;

  if(!node) return;

  for(i=0; i<level; i++) {
    printf(" ");
  }

  printf("AST( ");
  switch((node->type)) {
    case AST_SYMBOL: printf("AST_SYMBOL"); break;
    case AST_ADD: printf("AST_ADD"); break;
    case AST_SUB: printf("AST_SUB"); break;
    case AST_DIV: printf("AST_DIV"); break;
    case AST_MUL: printf("AST_MUL"); break;
    case AST_DIF: printf("AST_DIF"); break;
    case AST_EQ: printf("AST_EQ"); break;
    case AST_LE: printf("AST_LE"); break;
    case AST_GE: printf("AST_GE"); break;
    case AST_LT: printf("AST_LT"); break;
    case AST_GT: printf("AST_GT"); break;
    case AST_AND: printf("AST_AND"); break;
    case AST_OR: printf("AST_OR"); break;
    case AST_NOT: printf("AST_NOT"); break;
    case AST_PAREN: printf("AST_PAREN"); break;
    case AST_VEC: printf("AST_VEC"); break;
    case AST_FUN: printf("AST_FUN"); break;
    case AST_CHAR: printf("AST_KWCHAR"); break;
    case AST_INT: printf("AST_KWINT"); break;
    case AST_FLOAT: printf("AST_KWFLOAT"); break;
    case AST_ARGLSTINIT: printf("AST_ARGLSTINIT"); break;
    case AST_ARGLST: printf("AST_ARGLST"); break;
    case AST_CMDLST: printf("AST_CMDLST"); break;
    case AST_BLOCK: printf("AST_BLOCK"); break;
    case AST_DECVAR: printf("AST_DECVAR"); break;
    case AST_DECVEC: printf("AST_DECVEC"); break;
    case AST_DECPROTO: printf("AST_DECPROTO"); break;
    case AST_OPT: printf("AST_OPT"); break;
    case AST_LSTPARAMINIT: printf("AST_LSTPARAMINIT"); break;
    case AST_LSTPARAM: printf("AST_LSTPARAM"); break;
    case AST_PARAM: printf("AST_PARAM"); break;
    case AST_ATTR: printf("AST_ATTR"); break;
    case AST_VECATTR: printf("AST_VECATTR"); break;
    case AST_CODE: printf("AST_CODE"); break;
    case AST_INPUT: printf("AST_INPUT"); break;
    case AST_PRINT: printf("AST_PRINT"); break;
    case AST_IF: printf("AST_IF"); break;
    case AST_ELSE: printf("AST_ELSE"); break;
    case AST_WHILE: printf("AST_WHILE"); break;
    case AST_RETURN: printf("AST_RETURN"); break;
    case AST_LSTDECGLOB: printf("AST_LSTDECGLOB"); break;
    case AST_LSTDEC: printf("AST_LSTDEC"); break;
    case AST_LSTCODE: printf("AST_LSTCODE"); break;
    default: printf("AST_UNKNOWN"); break;
  }

  printf(" %s )\n", node->symbol?node->symbol->text:"");
  for(i=0; i<MAX_SONS; i++) {
    astPrint(node->son[i], level+1);
  }
}

void uncompileAST(AST* node, FILE* file){

  if(node == NULL)
    return;

  printf("Node: %d\n", node->type);

  switch(node->type){
    case AST_LSTDECGLOB:
      uncompileAST(node->son[0], file);
      uncompileAST(node->son[1], file);
      break;

    case AST_LSTDEC:
      uncompileAST(node->son[0], file);
      uncompileAST(node->son[1], file);
      break;

    case AST_DECVAR:
      uncompileAST(node->son[0], file);
      fprintf(file, " %s = ", node->symbol->text);
      uncompileAST(node->son[1], file);
      fprintf(file, ";\n");
      break;

    case AST_DECVEC:
      uncompileAST(node->son[0], file);
      fprintf(file, " %s[", node->symbol->text);
      uncompileAST(node->son[1], file);
      fprintf(file, "]");      
      uncompileAST(node->son[2], file);
      fprintf(file, ";\n");
      break;

    case AST_DECPROTO:
      uncompileAST(node->son[0], file);
      fprintf(file, " %s(", node->symbol->text);
      uncompileAST(node->son[1], file);
      fprintf(file, ");\n");
      break;

    case AST_OPT:
      uncompileAST(node->son[0], file);
      fprintf(file, " ");
      uncompileAST(node->son[1], file);
      break;

    case AST_LSTPARAMINIT:
      uncompileAST(node->son[0], file);
      uncompileAST(node->son[1], file);
      break;

    case AST_LSTPARAM:
      fprintf(file, ", ");
      uncompileAST(node->son[0], file);
      uncompileAST(node->son[1], file);
      break;

    case AST_PARAM:
      uncompileAST(node->son[0], file);
      fprintf(file, " ");
      fprintf(file, "%s", node->symbol->text);
      break;

    case AST_LSTCODE:
      uncompileAST(node->son[0], file);
      uncompileAST(node->son[1], file);
      break;
    
    case AST_CODE:
      fprintf(file, "code ");
      fprintf(file, " %s ", node->symbol->text);
      uncompileAST(node->son[0], file);
      break;

    case AST_ATTR:
      fprintf(file, "%s = ", node->symbol->text);
      uncompileAST(node->son[0], file);
      fprintf(file, ";\n");
      break;

    case AST_VECATTR:
      fprintf(file, " %s[", node->symbol->text);
      uncompileAST(node->son[0], file);
      fprintf(file, "] = ");
      uncompileAST(node->son[1], file);
      fprintf(file, ";\n");
      break;

    case AST_PRINT:
      fprintf(file, " print ");
      uncompileAST(node->son[0], file);
      fprintf(file, ";\n");
      break;

    case AST_SYMBOL:
      fprintf(file, " %s ", node->symbol->text);
      break;

    case AST_RETURN:
      fprintf(file, "return ");
      uncompileAST(node->son[0], file);
      fprintf(file, ";\n");
      break;

    case AST_WHILE:
      fprintf(file, " while( ");
      uncompileAST(node->son[0], file);
      fprintf(file, " )");
      uncompileAST(node->son[1], file);
      break;

    case AST_IF:
      fprintf(file, "if( ");
      uncompileAST(node->son[0], file);
      fprintf(file, " ) \n");
      uncompileAST(node->son[1], file);
      break;

    case AST_ELSE:
      fprintf(file, " else\n");
      uncompileAST(node->son[2], file);
      break;

    case AST_BLOCK:
      fprintf(file, " {\n");
      uncompileAST(node->son[0], file);
      fprintf(file, "} ");
      break;

    case AST_CMDLST:
      uncompileAST(node->son[0], file);
      uncompileAST(node->son[1], file);
      break;

    case AST_ADD:
      uncompileAST(node->son[0], file);
      fprintf(file, " + ");
      uncompileAST(node->son[1], file);
      break;

    case AST_SUB:
      uncompileAST(node->son[0], file);
      fprintf(file, " - ");
      uncompileAST(node->son[1], file);
      break;

    case AST_DIV:
      uncompileAST(node->son[0], file);
      fprintf(file, " / ");
      uncompileAST(node->son[1], file);
      break;

    case AST_MUL:
      uncompileAST(node->son[0], file);
      fprintf(file, " * ");
      uncompileAST(node->son[1], file);
      break;

    case AST_LT:
      uncompileAST(node->son[0], file);
      fprintf(file, " < ");
      uncompileAST(node->son[1], file);
      break;

    case AST_GT:
      uncompileAST(node->son[0], file);
      fprintf(file, " > ");
      uncompileAST(node->son[1], file);
      break;

    case AST_AND:
      uncompileAST(node->son[0], file);
      fprintf(file, " & ");
      uncompileAST(node->son[1], file);
      break;

    case AST_OR:
      uncompileAST(node->son[0], file);
      fprintf(file, " | ");
      uncompileAST(node->son[1], file);
      break;

    case AST_NOT:
      fprintf(file, " ~ ");
      uncompileAST(node->son[0], file);
      break;

    case AST_DIF:
      uncompileAST(node->son[0], file);
      fprintf(file, " != ");
      uncompileAST(node->son[1], file);
      break;

    case AST_EQ:
      uncompileAST(node->son[0], file);
      fprintf(file, " == ");
      uncompileAST(node->son[1], file);
      break;

    case AST_GE:
      uncompileAST(node->son[0], file);
      fprintf(file, " >= ");
      uncompileAST(node->son[1], file);
      break;

    case AST_LE:
      uncompileAST(node->son[0], file);
      fprintf(file, " <= ");
      uncompileAST(node->son[1], file);
      break;

    case AST_INPUT:
      fprintf(file, " input( ");
      uncompileAST(node->son[0], file);
      fprintf(file, " ) ");
      break;

    case AST_FUN:
      fprintf(file, " %s( ", node->symbol->text);
      uncompileAST(node->son[0], file);
      fprintf(file, " ) ");
      break;

    case AST_VEC:
      fprintf(file, " %s[", node->symbol->text);
      uncompileAST(node->son[0], file);
      fprintf(file, "] ");
      break;

    case AST_PAREN:
      fprintf(file, " ( ");
      uncompileAST(node->son[0], file);
      fprintf(file, " ) ");
      break;

    case AST_ARGLSTINIT:
      uncompileAST(node->son[0], file);
      uncompileAST(node->son[1], file);
      break;

    case AST_ARGLST:
      fprintf(file, ", ");
      uncompileAST(node->son[0], file);
      uncompileAST(node->son[1], file);
      break;

    case AST_CHAR:
      fprintf(file, " char ");
      break;

    case AST_INT:
      fprintf(file, " int ");
      break;

    case AST_FLOAT:
      fprintf(file, " float ");
      break;
  }
}