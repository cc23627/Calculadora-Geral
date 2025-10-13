#pragma once

#define MAX_TOKEN 64

enum TipoToken {
    NUMERO,
    BOOLEANO,
    OPERADOR,
    PARENTESE_ABRE,
    PARENTESE_FECHA,
    FIM
};

struct Token {
    TipoToken tipo;
    char valor[MAX_TOKEN];
};

int ehOperador(char c);
int ehBooleano(const char* s);
int ehNumero(const char* s);

void lexer(const char* expressao, Token* tokens, int& numTokens);
