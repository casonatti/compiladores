/*
Autor: Jeison Casonatti Caroly
Data: 16/12/2023
Disciplina: Compiladores B
Etapa 4
*/

#ifndef SEMANTIC_H
#define SEMANTIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

int semanticVerification(AST* root);
void setIdentifierType(AST* node);
void setNodeType(AST* node);
void checkUndeclared();
void checkUsage(AST* node);
int checkEveryVecElement(AST* node, int dataType);
int isDataTypeCompatible(int dataType_1, int dataType_2);
int isInteger(int dataType);
int isNumerical(int dataType);
int isRelational(int nodeType);
int isArithmetic(int nodeType);
int isLogical(int nodeType);
int greaterDataType(int dataType_1, int dataType_2);
void validateFunction(AST* node);
void checkPrint(AST* node);
AST* findFuncionDeclaration(char* name, AST* node);
int checkNumberOfArguments(AST* node, AST* decl);
int getNumberOfArguments(AST* node);
void compareCalledArguments(AST* node, AST* decl);
void isReturnCompatible(AST* node, int dataType);
void checkReturns(AST* node);

#endif