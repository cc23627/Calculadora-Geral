#pragma once
#include "../Headers/lexer.hpp"
#include "../Headers/stack.hpp"

#define MAX_FILA 256

void infixaParaPosfixa(Token* tokens, Token* saida, int& tamanhoSaida);
int precedencia(const char* op);
int associativoDireita(const char* op);
