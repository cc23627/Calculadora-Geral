#include "../Headers/lexer.hpp"
#include <cstring>
#include <cctype>
#include <cstdio>

int ehOperador(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||
           c=='<'||c=='>'||c=='='||c=='!'||c=='&'||c=='|';
}

int ehBooleano(const char* s) {
    return strcmp(s, "true") == 0 || strcmp(s, "false") == 0;
}

int ehNumero(const char* s) {
    int i = 0;
    int ponto = 0;
    if(s[0]=='-' || s[0]=='+') i++;
    for(; s[i]; i++){
        if(s[i]=='.'){
            if(ponto) return 0;
            ponto = 1;
        } else if(!isdigit(s[i])) return 0;
    }
    return (i>0);
}

void lexer(const char* expressao, Token* tokens, int& numTokens){
    int i=0;
    numTokens=0;

    while(expressao[i]){
        if(isspace(expressao[i])) { i++; continue; }

        Token t;
        memset(&t, 0, sizeof(Token));

        if(isdigit(expressao[i]) || ((expressao[i]=='+' || expressao[i]=='-') && isdigit(expressao[i+1]))){
            int j=0;
            while(isdigit(expressao[i]) || expressao[i]=='.' || expressao[i]=='+' || expressao[i]=='-'){
                t.valor[j++] = expressao[i++];
            }
            t.valor[j] = '\0';
            t.tipo = NUMERO;
        } else if(expressao[i]=='('){
            t.tipo = PARENTESE_ABRE;
            t.valor[0] = '(';
            t.valor[1] = '\0';
            i++;
        } else if(expressao[i]==')'){
            t.tipo = PARENTESE_FECHA;
            t.valor[0] = ')';
            t.valor[1] = '\0';
            i++;
        } else if(ehOperador(expressao[i])){
            int j=0;
            while(ehOperador(expressao[i])){
                t.valor[j++] = expressao[i++];
            }
            t.valor[j] = '\0';
            t.tipo = OPERADOR;
        } else if(isalpha(expressao[i])){
            int j=0;
            while(isalpha(expressao[i])){
                t.valor[j++] = expressao[i++];
            }
            t.valor[j] = '\0';
            if(ehBooleano(t.valor)) t.tipo = BOOLEANO;
            else {
                printf("Token inválido: '%s'\n", t.valor);
                t.tipo = FIM;
                return;
            }
        } else {
            printf("Símbolo inválido: '%c'\n", expressao[i]);
            t.tipo = FIM;
            return;
        }

        tokens[numTokens++] = t;
    }

    Token fim;
    fim.tipo = FIM;
    fim.valor[0] = '\0';
    tokens[numTokens++] = fim;
}
