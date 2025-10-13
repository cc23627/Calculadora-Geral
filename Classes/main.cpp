#include <cstdio>
#include "../Headers/lexer.hpp"
#include "../Headers/shunting_yard.hpp"

int main() {
    char expressao[256];

    printf("Digite a expressao: ");
    fgets(expressao, 256, stdin);

    // Remove \n se houver
    int len = 0;
    while(expressao[len] != '\0') len++;
    if(len > 0 && expressao[len-1] == '\n') expressao[len-1] = '\0';

    // Tokenização
    Token tokens[128];
    int numTokens = 0;
    lexer(expressao, tokens, numTokens);

    // Adiciona token de FIM ao final
    tokens[numTokens].tipo = FIM;

    // Conversão infixa → pós-fixa
    Token posfixa[128];
    int tamanhoPosfixa = 0;
    infixaParaPosfixa(tokens, posfixa, tamanhoPosfixa);

    // Exibe resultado
    printf("Expressao em pos-fixa:\n");
    for(int i=0; i<tamanhoPosfixa; i++){
        printf("%s ", posfixa[i].valor);
    }
    printf("\n");

    return 0;
}
