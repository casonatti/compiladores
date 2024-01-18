/*
Autor: Jeison Casonatti Caroly
Data: 16/12/2023
Disciplina: Compiladores B
Etapa 4
*/

#include "semantic.h"

int errorCounter = 0;
AST* g_root;

int semanticVerification(AST* root) {
  g_root = root;

  setIdentifierType(root);
  setNodeType(root);
  checkUndeclared();
  checkUsage(root);
  checkReturns(root);

  return errorCounter;
}

void setIdentifierType(AST* node) {
  if(node == NULL)
    return;

  switch (node->type) {
    case AST_DECVAR:
      if(node->symbol->type != SYMBOL_IDENTIFIER) {
        fprintf(stderr, "Semantic error in line %d: Variable %s redeclaration.\n", node->lineNumber, node->symbol->text);
        errorCounter++;
      } else {
        node->symbol->type = SYMBOL_VAR;
        if(node->son[0]->type == AST_INT)
          node->symbol->dataType = DATATYPE_INT;
        else if(node->son[0]->type == AST_FLOAT)
          node->symbol->dataType = DATATYPE_REAL;
        else if(node->son[0]->type == AST_CHAR)
          node->symbol->dataType = DATATYPE_CHAR;
      }

      if(!isDataTypeCompatible(node->symbol->dataType, node->son[1]->symbol->dataType)) {
        fprintf(stderr, "Semantic error in line %d: Variable declaration with mixed dataTypes.\n", node->lineNumber);
        errorCounter++;
      }

      break;

    case AST_DECVEC:
      if(node->symbol->type != SYMBOL_IDENTIFIER) {
        fprintf(stderr,"Semantic error in line %d: Vector %s redeclaration.\n", node->lineNumber, node->symbol->text);
              errorCounter++;
      } else {
        node->symbol->type = SYMBOL_VEC;
        if(node->son[0]->type == AST_INT)
          node->symbol->dataType = DATATYPE_INT;
        else if(node->son[0]->type == AST_FLOAT)
          node->symbol->dataType = DATATYPE_REAL;
        else if(node->son[0]->type == AST_CHAR)
          node->symbol->dataType = DATATYPE_CHAR;
      }

      if(!checkEveryVecElement(node->son[2], node->symbol->dataType)) {
        fprintf(stderr, "Semantic error on line %d: Vector declaration with elements of mixed datatype\n", node->lineNumber);
        printf("DT1: %d; DT2: %d\n", node->son[2]?1:-1, node->son[1]->symbol->dataType);
        errorCounter++;
      }
        
      break;

    case AST_DECPROTO:
      if(node->symbol->type != SYMBOL_IDENTIFIER){
        fprintf(stderr,"Semantic error in line %d: Function %s redeclaration.(proto)\n", node->lineNumber, node->symbol->text);
        errorCounter++;
      } else{
        node->symbol->type = SYMBOL_FUNC;
        if(node->son[0]->type == AST_INT) node->symbol->dataType = DATATYPE_INT;
        else if(node->son[0]->type == AST_FLOAT) node->symbol->dataType = DATATYPE_REAL;
        else if(node->son[0]->type == AST_CHAR) node->symbol->dataType = DATATYPE_CHAR;
      }

    break;

    case AST_CODE:
      if(node->symbol->type != SYMBOL_IDENTIFIER){
        fprintf(stderr,"Semantic error in line %d: Function %s redeclaration (code).\n", node->lineNumber, node->symbol->text);
        errorCounter++;
      } else {
        node->symbol->type = SYMBOL_FUNC;
        if(node->son[0]->type == AST_INT) node->symbol->dataType = DATATYPE_INT;
        else if(node->son[0]->type == AST_FLOAT) node->symbol->dataType = DATATYPE_REAL;
        else if(node->son[0]->type == AST_CHAR) node->symbol->dataType = DATATYPE_CHAR;
      }

      break;

    case AST_PARAM:
      if(node->symbol->type != SYMBOL_IDENTIFIER){
        fprintf(stderr,"Semantic error in line %d: Parameter %s redeclaration.\n", node->lineNumber, node->symbol->text);
        errorCounter++;
      } else {
        node->symbol->type = SYMBOL_PARAM;
        if(node->son[0]->type == AST_INT) node->symbol->dataType = DATATYPE_INT;
        else if(node->son[0]->type == AST_FLOAT) node->symbol->dataType = DATATYPE_REAL;
        else if(node->son[0]->type == AST_CHAR) node->symbol->dataType = DATATYPE_CHAR;
      }

      break;

    default:
      break;
  }

  for(int i = 0; i < MAX_SONS; i++)
    setIdentifierType(node->son[i]);
}

void setNodeType(AST* node) {
  if(node == NULL)
    return;

  for(int i = 0; i < MAX_SONS; i++)
    setNodeType(node->son[i]);

  if(node->type == AST_SYMBOL) {
    if(node->symbol->type == SYMBOL_VEC || node->symbol->type == SYMBOL_FUNC) {
      fprintf(stderr, "Semantic error in line %d: function/vector used as scalar variable.\n", node->lineNumber);
      errorCounter++;
    }
    node->dataType = node->symbol->dataType;
  } else if(node->type == AST_FUN || node->type == AST_VEC) {
    node->dataType = node->symbol->dataType;
  } else if(node->type == AST_PAREN){
    node->dataType = node->son[0]->dataType;
  } else if(isArithmetic(node->type)){
    AST* son0 = node->son[0];
    AST* son1 = node->son[1];
    if(!isDataTypeCompatible(son0->dataType, son1->dataType) || son0->dataType == DATATYPE_BOOL || son1->dataType == DATATYPE_BOOL){
        fprintf(stderr, "Semantic error in line %d: Arithmetic operation with incompatible data types.\n", node->lineNumber);
        errorCounter++;
    }
    node->dataType = greaterDataType(son0->dataType, son1->dataType);
  } else if(isRelational(node->type)) {
    if(!isNumerical(node->son[0]->dataType) || !isNumerical(node->son[1]->dataType)){
        fprintf(stderr, "Semantic error in line %d: Relational operation with incompatible data types.\n", node->lineNumber);
        errorCounter++;
    }
    node->dataType = DATATYPE_BOOL;
  } else if(isLogical(node->type)) {
    if(node->type == AST_NOT){
        if(node->son[0]->dataType != DATATYPE_BOOL){
            fprintf(stderr, "Semantic error in line %d: Logical operation with incompatible data types.\n", node->lineNumber);
            errorCounter++;
        }
    } else if(node->son[0]->dataType != DATATYPE_BOOL || node->son[1]->dataType != DATATYPE_BOOL){
        fprintf(stderr, "Semantic error in line %d: Logical operation with incompatible data types.\n", node->lineNumber);
        errorCounter++;
    }
      node->dataType = DATATYPE_BOOL;
  }
}
void checkUndeclared() {
  int undeclaredVariables = hashCheckUndeclared();
  errorCounter = errorCounter + undeclaredVariables;
}

void checkUsage(AST* node) {
  if(node == NULL)
    return;

  switch (node->type) {
    case AST_ATTR:
      if(node->symbol->type != SYMBOL_VAR) {
        fprintf(stderr, "Semantic error in line %d: Attribution must be to a scalar variable.\n", node->lineNumber);
        errorCounter++;
      }

      if(node->son[0]->type == AST_INPUT) {
        if(node->son[0]->son[0]->type == AST_INT)
          node->son[0]->son[0]->dataType = DATATYPE_INT;
        else if(node->son[0]->son[0]->type == AST_FLOAT)
          node->son[0]->son[0]->dataType = DATATYPE_REAL;
        else if(node->son[0]->son[0]->type == AST_CHAR)
          node->son[0]->son[0]->dataType = DATATYPE_CHAR;
        if(!isDataTypeCompatible(node->symbol->dataType, node->son[0]->son[0]->dataType)){
          fprintf(stderr, "Semantic error in line %d: Attribution with incompatible data type (input).\n", node->lineNumber);
          errorCounter++;
        }
      } else {
        if(!isDataTypeCompatible(node->symbol->dataType, node->son[0]->dataType)){
          fprintf(stderr, "Semantic error in line %d: Attribution with incompatible data type.\n", node->lineNumber);
          errorCounter++;
        }
      }

      break;

    case AST_VECATTR:
      if(node->symbol->type != SYMBOL_VEC){
        fprintf(stderr, "Semantic error in line %d: Indexing only allowed for vectors.\n", node->lineNumber);
        errorCounter++;
      }
      if(!isDataTypeCompatible(node->symbol->dataType, node->son[1]->dataType)){
        fprintf(stderr, "Semantic error in line %d: Attribution with incompatible data type.\n", node->lineNumber);
        errorCounter++;
      }
      if(!isInteger(node->son[0]->dataType)){
        fprintf(stderr, "Semantic error in line %d: Index must be an integer.\n", node->lineNumber);
        errorCounter++;
      }

      break;

    case AST_FUN:
      validateFunction(node);

      break;
    //TODO: tava bugando
    case AST_INPUT: break;

    case AST_PRINT:
      checkPrint(node);

      break;

    case AST_IF:
    case AST_WHILE:
      if(node->son[0]->dataType != DATATYPE_BOOL) {
        fprintf(stderr, "Semantic error in line %d: Condition must be a boolean expression.\n", node->lineNumber);
        errorCounter++;
      }

      break;

    default:
      break;
  }

  for(int i = 0; i < MAX_SONS; i++)
    checkUsage(node->son[i]);
}

int checkEveryVecElement(AST* node, int dataType) {
  if(node != NULL){
		if(!isDataTypeCompatible(node->son[0]->symbol->dataType, dataType))
			return 0;
		if(node->son[1] != NULL)
			return checkEveryVecElement(node->son[1], dataType);
	}
	return 1;
}

int isDataTypeCompatible(int dataType_1, int dataType_2) {
  if((isInteger(dataType_1) && isInteger(dataType_2)) || (dataType_1 == dataType_2))
    return 1;
  else
    return 0;
}

int isInteger(int dataType) {
  if(dataType == DATATYPE_CHAR || dataType == DATATYPE_INT)
    return 1;
  else
    return 0;
}

int isNumerical(int dataType) {
  if(dataType == DATATYPE_CHAR || dataType == DATATYPE_INT || dataType == DATATYPE_REAL)
    return 1;
  else
    return 0;
}

int isRelational(int nodeType) {
  if(nodeType == AST_LT || nodeType == AST_GT || nodeType == AST_EQ || nodeType == AST_LE || nodeType == AST_GE || nodeType == AST_DIF)
    return 1;
  else
    return 0;
}

int isArithmetic(int nodeType) {
  if(nodeType == AST_ADD || nodeType == AST_SUB || nodeType == AST_MUL || nodeType == AST_DIV)
    return 1;
  else
    return 0;
}

int isLogical(int nodeType) {
  if(nodeType == AST_AND || nodeType == AST_OR || nodeType == AST_NOT)
    return 1;
  else
    return 0;
}

int greaterDataType(int dataType_1, int dataType_2) {
  if(dataType_1 > dataType_2)
    return dataType_1;
  else
    return dataType_2;
}

void checkPrint(AST* node) {
  if(node == NULL)
    return;
  
  if(node->son[0]->type == AST_SYMBOL) {
    if(node->son[0]->symbol->type == SYMBOL_FUNC) {
      fprintf(stderr, "Semantic error in line %d: Cannot print function\n", node->lineNumber);
      errorCounter++;
    } else if(node->son[0]->symbol->type == SYMBOL_VEC) {
      fprintf(stderr, "Semantic error in line %d: Cannot print vector\n", node->lineNumber);
      errorCounter++;
    }
  }

  checkPrint(node->son[1]);
}

void validateFunction(AST* node) {
  AST* decl = findFuncionDeclaration(node->symbol->text, g_root);

  if(decl == NULL) {
    fprintf(stderr, "Semantic error in line %d: Only functions can be called.\n", node->lineNumber);
    errorCounter++;
  } else if(checkNumberOfArguments(node, decl)) {
    compareCalledArguments(node->son[0], decl->son[1]);
  }
}

AST* findFuncionDeclaration(char* name, AST* node) {
  if(node->symbol != NULL && node->type == AST_DECPROTO && strcmp(node->symbol->text, name) == 0)
    return node;

  for(int i = 0; i < MAX_SONS; i++) {
    if(node->son[i] == NULL)
      return NULL;
    AST* find = findFuncionDeclaration(name, node->son[i]);
    if(find != NULL)
      return find;
  }

  return NULL;
}

int checkNumberOfArguments(AST* node, AST* decl) {
  int calledArguments = getNumberOfArguments(node->son[0]);
  int calledDeclArguments = getNumberOfArguments(decl->son[0]);
  if(calledArguments != calledDeclArguments) {
    fprintf(stderr, "Semantic error in line %d: Incompatible number of arguments.\n", node->lineNumber);
		errorCounter++;
		return 0;
  }

  return 1;
}

int getNumberOfArguments(AST* node) {
  if(node == NULL)
    return 0;

  if(node->son[1] != NULL)
    return 1 + getNumberOfArguments(node->son[1]);
  else
    return 0;
}

void compareCalledArguments(AST* node, AST* decl) {
  if(node->son[0] != NULL) {
    if(!isDataTypeCompatible(node->son[0]->dataType, decl->son[0]->symbol->dataType)) {
      fprintf(stderr, "Semantic error in line %d: Incompatible argument types\n", node->lineNumber);
			errorCounter++;
    }

    if(node->son[0]->type == AST_SYMBOL) {
      if(node->son[0]->symbol->type == SYMBOL_FUNC) {
        fprintf(stderr, "Semantic error in line %d: Cannot pass function as argument\n", node->lineNumber);
			  errorCounter++;
      } else if(node->son[0]->symbol->type == SYMBOL_VEC) {
        fprintf(stderr, "Semantic error in line %d: Cannot pass vector as argument\n", node->lineNumber);
			  errorCounter++;
      }
    }

    if(node->son[0] != NULL)
      compareCalledArguments(node->son[1], decl->son[1]);
  }
}

void isReturnCompatible(AST* node, int dataType) {
  if(node == NULL) return;
	if(node->type == AST_RETURN){
		if(!isDataTypeCompatible(node->son[0]->dataType, dataType)){
			printf("Semantic error in line %d: Return statement with wrong datatype.\n", node->lineNumber);
			errorCounter++;
		}
	}
	for(int i = 0; i < MAX_SONS; i++){
		isReturnCompatible(node->son[i], dataType);
	}
}

void checkReturns(AST* node) {
  if(node != NULL && node->type == AST_CODE){
		isReturnCompatible(node, node->symbol->dataType);
	}

	for(int i = 0; i < MAX_SONS; i++){
		if(node->son[i] == NULL)
			break;
		checkReturns(node->son[i]);
	}
}