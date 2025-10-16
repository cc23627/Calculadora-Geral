#include "../Headers/evaluator.hpp"
#include "../Headers/stack.hpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

static bool ehBooleanoStr(const char* s) {
    return strcmp(s, "true") == 0 || strcmp(s, "false") == 0;
}

static double strParaNumero(const char* s) {
    if (strcmp(s, "true") == 0) return 1.0;
    if (strcmp(s, "false") == 0) return 0.0;
    return atof(s);
}

static const char* boolStr(double v) {
    return (fabs(v) > 1e-9) ? "true" : "false";
}


bool avaliarPosfixa(Token* tokens, int tamanho, char* resultado) {
    Stack pilha;

    for (int i = 0; i < tamanho; i++) {
        Token t = tokens[i];

        if (t.tipo == NUMERO || t.tipo == BOOLEANO) {
            char* valor = new char[MAX_TOKEN];
            strcpy(valor, t.valor);
            pilha.Empilhar(valor);
        }
        else if (t.tipo == OPERADOR) {
            // Operadores unários e binários
            if (strcmp(t.valor, "!") == 0) {
                if (pilha.Vazia()) {
                    printf("Erro: operador '!' sem operando\n");
                    return false;
                }
                char* op = (char*)pilha.Desempilhar();
                double v = strParaNumero(op);
                delete[] op;

                char* res = new char[MAX_TOKEN];
                strcpy(res, v == 0 ? "true" : "false");
                pilha.Empilhar(res);
            }
            else {
                if (pilha.Tamanho() < 2) {
                    printf("Erro: operandos insuficientes para operador '%s'\n", t.valor);
                    return false;
                }

                char* op2 = (char*)pilha.Desempilhar();
                char* op1 = (char*)pilha.Desempilhar();
                double b = strParaNumero(op2);
                double a = strParaNumero(op1);
                delete[] op1;
                delete[] op2;

                double resNum = 0;
                bool boolRes = false;
                bool isBool = false;

                // Operadores aritméticos
                if (strcmp(t.valor, "+") == 0) resNum = a + b;
                else if (strcmp(t.valor, "-") == 0) resNum = a - b;
                else if (strcmp(t.valor, "*") == 0) resNum = a * b;
                else if (strcmp(t.valor, "/") == 0) {
                    if (b == 0) {
                        printf("Erro: divisao por zero\n");
                        return false;
                    }
                    resNum = a / b;
                }
                else if (strcmp(t.valor, "^") == 0) resNum = pow(a, b);

                // Relacionais
                else if (strcmp(t.valor, ">") == 0) { boolRes = (a > b); isBool = true; }
                else if (strcmp(t.valor, "<") == 0) { boolRes = (a < b); isBool = true; }
                else if (strcmp(t.valor, ">=") == 0) { boolRes = (a >= b); isBool = true; }
                else if (strcmp(t.valor, "<=") == 0) { boolRes = (a <= b); isBool = true; }
                else if (strcmp(t.valor, "==") == 0) { boolRes = (fabs(a - b) < 1e-9); isBool = true; }
                else if (strcmp(t.valor, "!=") == 0) { boolRes = (fabs(a - b) >= 1e-9); isBool = true; }

                // Lógicos
                else if (strcmp(t.valor, "&&") == 0) { boolRes = (a != 0 && b != 0); isBool = true; }
                else if (strcmp(t.valor, "||") == 0) { boolRes = (a != 0 || b != 0); isBool = true; }
                else {
                    printf("Erro: operador desconhecido '%s'\n", t.valor);
                    return false;
                }

                char* res = new char[MAX_TOKEN];
                if (isBool) {
                    strcpy(res, boolRes ? "true" : "false");
                } else {
                    snprintf(res, MAX_TOKEN, "%.6g", resNum);
                }
                pilha.Empilhar(res);
            }
        }
    }

    if (pilha.Tamanho() != 1) {
        printf("Erro: expressao invalida (operandos ou operadores em excesso)\n");
        return false;
    }

    char* final = (char*)pilha.Desempilhar();
    strcpy(resultado, final);
    delete[] final;

    return true;
}
