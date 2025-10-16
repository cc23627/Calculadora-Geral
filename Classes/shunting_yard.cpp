#include "../Headers/shunting_yard.hpp"
#include <cstring>
#include <cstdio>

// Precedência
int precedencia(const char* op){
    if(strcmp(op,"!") == 0) return 9;
    if(strcmp(op,"^") == 0) return 8;
    if(strcmp(op,"*") == 0 || strcmp(op,"/") == 0) return 7;
    if(strcmp(op,"+") == 0 || strcmp(op,"-") == 0) return 6;
    if(strcmp(op,">") == 0 || strcmp(op,"<") == 0 ||
       strcmp(op,">=") == 0 || strcmp(op,"<=") == 0) return 5;
    if(strcmp(op,"==") == 0 || strcmp(op,"!=") == 0) return 4;
    if(strcmp(op,"&&") == 0) return 3;
    if(strcmp(op,"||") == 0) return 2;
    return 0;
}

int associativoDireita(const char* op){
    if(strcmp(op,"!") == 0 || strcmp(op,"^") == 0) return 1;
    return 0;
}

void infixaParaPosfixa(Token* tokens, Token* saida, int& tamanhoSaida) {
    Stack pilha;
    tamanhoSaida = 0;

    for (int i = 0; tokens[i].tipo != FIM; i++) {
        Token t = tokens[i];

        if (t.tipo == NUMERO || t.tipo == BOOLEANO) {

            saida[tamanhoSaida++] = t;
        }
        else if (t.tipo == OPERADOR) {

            while (!pilha.Vazia()) {
                Token* topo = (Token*)pilha.Topo();
                if (topo->tipo != OPERADOR) break;

                int precTopo = precedencia(topo->valor);
                int precAtual = precedencia(t.valor);
                int rightAssoc = associativoDireita(t.valor);

                if ((precTopo > precAtual) || (precTopo == precAtual && !rightAssoc)) {
                    Token* x = (Token*)pilha.Desempilhar();
                    saida[tamanhoSaida++] = *x;
                    delete x;
                } else break;
            }

            Token* p = new Token;
            *p = t;
            pilha.Empilhar(p);
        }
        else if (t.tipo == PARENTESE_ABRE) {
            Token* p = new Token;
            *p = t;
            pilha.Empilhar(p);
        }
        else if (t.tipo == PARENTESE_FECHA) {
            int achouAbre = 0;
            while (!pilha.Vazia()) {
                Token* x = (Token*)pilha.Desempilhar();
                if (x->tipo == PARENTESE_ABRE) {
                    achouAbre = 1;
                    delete x;
                    break;
                }
                saida[tamanhoSaida++] = *x;
                delete x;
            }
            if (!achouAbre) {
                printf("Erro: Parênteses desbalanceados\n");
                return;
            }
        }
    }

    // Desempilha o restante dos operadores
    while (!pilha.Vazia()) {
        Token* x = (Token*)pilha.Desempilhar();
        if (x->tipo == PARENTESE_ABRE) {
            printf("Erro: Parênteses desbalanceados\n");
            delete x;
            return;
        }
        saida[tamanhoSaida++] = *x;
        delete x;
    }

}
