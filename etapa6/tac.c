/*
Autor: Jeison Casonatti Caroly
Data: 19/01/2024
Disciplina: Compiladores B
Etapa 5
*/

#include "tac.h"

TAC* newTac(int type, HASH_NODE* res, HASH_NODE* op_1, HASH_NODE* op_2) {
  TAC* node = (TAC*) calloc(1, sizeof(TAC));

  node->type = type;
  node->res = res;
  node->op_1 = op_1;
  node->op_2 = op_2;
  node->previous = NULL;
  node->next = NULL;

  return node;
}

TAC* tacUnion(TAC* list_1, TAC* list_2) {
  TAC* aux;

  if(!list_1)
    return list_2;
  
  if(!list_2)
    return list_1;

  aux = list_2;

  while(aux->previous)
    aux = aux->previous;

  aux->previous = list_1;

  return list_2;
}

TAC* rewindTac(TAC* list) {
  TAC* aux;

  for(aux = list; aux->previous; aux = aux->previous)
    aux->previous->next = aux;

  return aux;
}

TAC* createTac(AST* node, HASH_NODE* currentLabel) {
  if(!node) return NULL;

	TAC* son[MAX_SONS];
	if(node->type == AST_WHILE){
		currentLabel = makeLabel();
	}
	
	for(int i = 0; i < MAX_SONS; i++)
		son[i] = createTac(node->son[i], currentLabel);

	switch(node->type){
		case AST_SYMBOL: return newTac(TAC_SYMBOL, node->symbol, 0, 0);
		case AST_ATTR: return tacUnion(son[0], newTac(TAC_MOVE, node->symbol, son[0]?son[0]->res:0, 0));
		case AST_VECATTR: return tacUnion(son[0], tacUnion(son[1], newTac(TAC_VECATTR, node->symbol, son[0]?son[0]->res:0, son[1]?son[1]->res:0))); 
		case AST_INPUT: return newTac(TAC_INPUT, node->symbol, 0, 0);
		case AST_PRINT: return tacUnion(tacUnion(son[0], newTac(TAC_PRINT, son[0]?son[0]->res:0, 0, 0)), son[1]);
		case AST_RETURN: return tacUnion(son[0], newTac(TAC_RET, son[0]?son[0]->res:0, 0, 0));
		case AST_ELSE:
		case AST_IF: return createIf(son);
		case AST_WHILE: return createLoop(son, currentLabel);
		case AST_CODE: return createFunction(newTac(TAC_SYMBOL, node->symbol, 0, 0), son[0], son[1]);
		case AST_FUN: return tacUnion(son[0], newTac(TAC_CALL, makeTemp(), node->symbol, 0));
		case AST_ARGLSTINIT:
		case AST_ARGLST: return tacUnion(son[1], tacUnion(son[0], newTac(TAC_ARGPUSH, son[0]?son[0]->res:0, 0, 0)));
		case AST_VEC: return tacUnion(son[0], newTac(TAC_VEC, makeTemp(), node->symbol, son[0]?son[0]->res:0));
		case AST_PARAM: return tacUnion(newTac(TAC_PARAMPOP, node->symbol, 0, 0), son[1]);
		case AST_ADD: return createBinOp(TAC_ADD, son);
		case AST_SUB: return createBinOp(TAC_SUB, son);
		case AST_MUL: return createBinOp(TAC_MUL, son);
		case AST_DIV: return createBinOp(TAC_DIV, son);
		case AST_GT: return createBinOp(TAC_GT, son);
		case AST_LT: return createBinOp(TAC_LT, son);
		case AST_EQ: return createBinOp(TAC_EQ, son);
		case AST_GE: return createBinOp(TAC_GE, son);
		case AST_LE: return createBinOp(TAC_LE, son);
		case AST_DIF: return createBinOp(TAC_DIF, son);
		case AST_AND: return createBinOp(TAC_AND, son);
		case AST_OR: return createBinOp(TAC_OR, son);
		case AST_NOT: return createBinOp(TAC_NOT, son);

		default: return tacUnion(tacUnion(tacUnion(son[0], son[1]), son[2]), son[3]);
	}
}

void printTac(TAC* list) {
  if(list->type == TAC_SYMBOL) return;
	
	fprintf(stderr, "TAC(");
	switch(list->type){
		case TAC_MOVE: fprintf(stderr, "MOVE(");break;
		case TAC_ADD: fprintf(stderr, "ADD(");break;
		case TAC_SUB: fprintf(stderr, "SUB(");break;
		case TAC_MUL: fprintf(stderr, "MUL(");break;
		case TAC_DIV: fprintf(stderr, "DIV(");break;
		case TAC_GT: fprintf(stderr, "GREAT(");break;
		case TAC_LT: fprintf(stderr, "LESS(");break;
		case TAC_GE: fprintf(stderr, "GE(");break;
		case TAC_LE: fprintf(stderr, "LE(");break;
		case TAC_EQ: fprintf(stderr, "EQ(");break;
		case TAC_DIF: fprintf(stderr, "DIF(");break;
		case TAC_AND: fprintf(stderr, "AND(");break;
		case TAC_OR: fprintf(stderr, "OR(");break;
		case TAC_NOT: fprintf(stderr, "NOT(");break;
		case TAC_LABEL: fprintf(stderr, "LABEL(");break;
		case TAC_BEGINFUN: fprintf(stderr, "BEGINFUN(");break;
		case TAC_ARGPUSH: fprintf(stderr, "ARGPUSH(");break;
		case TAC_ENDFUN: fprintf(stderr, "ENDFUN(");break;
		case TAC_IF: fprintf(stderr, "IF(");break;
		case TAC_JUMP: fprintf(stderr, "JUMP(");break;
		case TAC_CALL: fprintf(stderr, "CALL(");break;
		case TAC_ARG: fprintf(stderr, "ARG(");break;
		case TAC_RET: fprintf(stderr, "RET(");break;
		case TAC_PRINT: fprintf(stderr, "PRINT(");break;
		case TAC_INPUT: fprintf(stderr, "INPUT(");break;
		case TAC_VECATTR: fprintf(stderr, "VECATTR(");break;
		case TAC_VEC: fprintf(stderr, "VEC(");break;
		case TAC_PARAMPOP: fprintf(stderr, "PARAMPOP(");break;

		default: fprintf(stderr, "UNKNOWN TAC TYPE!(");break;
	}

	if(list->res)
		fprintf(stderr, "%s, ", list->res->text);
	else
		fprintf(stderr, "0, ");

	if(list->op_1)
		fprintf(stderr, "%s, ", list->op_1->text);
	else
		fprintf(stderr, "0, ");

	if(list->op_2)
		fprintf(stderr, "%s", list->op_2->text);
	else
		fprintf(stderr, "0");

	fprintf(stderr, "))\n");
}

void generatedTac(TAC* list) {
  TAC* aux;

  for(aux = list; aux; aux = aux->next)
    printTac(aux);
}

TAC* createBinOp(int type, TAC* son[]) {
  HASH_NODE* op_1;
  HASH_NODE* op_2;
  TAC* aux;

  if(son[0])
    op_1 = son[0]->res;
  else
    op_1 = 0;

  if(son[1])
    op_2 = son[1]->res;
  else
    op_2 = 0;

  aux = tacUnion(son[0], tacUnion(son[1], newTac(type, makeTemp(), op_1, op_2)));

  return aux;
}

TAC* createIf(TAC* son[]) {
  HASH_NODE* ifLabel = makeLabel();
  TAC* ifTac = tacUnion(son[0], newTac(TAC_IF, ifLabel, son[0]?son[0]->res:0, 0));
  TAC* ifLabelTac = newTac(TAC_LABEL, ifLabel, 0, 0);

  if(son[2]) {
    HASH_NODE* elseLabel = makeLabel();
    TAC* elseLabelTac = newTac(TAC_LABEL, elseLabel, 0, 0);
    TAC* elseJumpTac = newTac(TAC_JUMP, elseLabel, 0, 0);
    TAC* ifElseTac = tacUnion(tacUnion(tacUnion(tacUnion(tacUnion(ifTac, son[1]), elseJumpTac), ifLabelTac), son[2]), elseLabelTac);

    return ifElseTac;
  } else {
    return tacUnion(tacUnion(ifTac, son[1]), ifLabelTac);
  }
}
TAC* createLoop(TAC* son[], HASH_NODE* label) {
  HASH_NODE* jumpLabel = makeLabel();

  TAC* whileTac = newTac(TAC_IF, jumpLabel, son[0]?son[0]->res:0, 0);
  TAC* whileLabelTac = newTac(TAC_LABEL, label, 0, 0);
  TAC* jumpTac = newTac(TAC_JUMP, label, 0, 0);
	TAC* jumpLabelTac= newTac(TAC_LABEL, jumpLabel, 0, 0);

  return tacUnion(tacUnion(tacUnion(tacUnion(tacUnion(whileLabelTac, son[0]), whileTac), son[1]), jumpTac), jumpLabelTac);
}
TAC* createFunction(TAC* symbol, TAC* params, TAC* code) {
  return tacUnion(tacUnion(tacUnion(newTac(TAC_BEGINFUN, symbol->res, 0, 0), params), code), newTac(TAC_ENDFUN, symbol->res, 0, 0));
}