#include <cstdio>
#include <cstring>
#include "../Headers/lexer.hpp"
#include "../Headers/shunting_yard.hpp"
#include "../Headers/evaluator.hpp"

int main() {
    char expressao[256];

    printf("Digite a expressao: ");
    if (!fgets(expressao, 256, stdin)) {
        printf("Erro na leitura da entrada.\n");
        return 1;
    }

    int len = strlen(expressao);
    if (len > 0 && expressao[len - 1] == '\n')
        expressao[len - 1] = '\0';

    Token tokens[128];
    int numTokens = 0;
    lexer(expressao, tokens, numTokens);

    Token posfixa[128];
    int tamanhoPosfixa = 0;
    infixaParaPosfixa(tokens, posfixa, tamanhoPosfixa);

    printf("\nExpressao em pos-fixa:\n");
    for (int i = 0; i < tamanhoPosfixa; i++) {
        printf("%s ", posfixa[i].valor);
    }
    printf("\n");

    char resultado[64];
    if (avaliarPosfixa(posfixa, tamanhoPosfixa, resultado)) {
        printf("\nResultado: %s\n", resultado);
    } else {
        printf("\nErro ao avaliar a expressao.\n");
    }

    return 0;
}
