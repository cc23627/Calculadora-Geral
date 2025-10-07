#include "fila.hpp"
#include "pilha.hpp"
#include <iostream>

int main(void) {
    Pilha P;
    std::cout << "Pilha\n";
    std::cout << "Empilhando: ";

    for (int I = 0; I <= 9; I++) {
        int *p = new int{I};
        P.Empilha(p);
        std::cout << I << ' ';
    }

    std::cout << "\nDesempilhando: ";
    while (P.Tamanho() != 0) {
        int *valor = (int *)P.Desempilha();
        std::cout << *valor << ' ';
        delete valor;
    }
    std::cout << "\n\n";

    Fila F;
    std::cout << "Fila\n";
    std::cout << "Enfileirando: ";

    for (int I = 0; I <= 9; I++) {
        int *p = new int{I};
        F.Enfileira(p);
        std::cout << I << ' ';
    }

    std::cout << "\nDesenfileirando: ";
    while (F.Tamanho() != 0) {
        int *valor = (int *)F.Desenfileira();
        std::cout << *valor << ' ';
        delete valor;
    }
    std::cout << std::endl;

    return 0;
}