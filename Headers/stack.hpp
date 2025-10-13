#pragma once

class Stack{
    private:
        int topo;
        void** area;
        int maximo; // Quantidade realmente alocada

    public:
        Stack(int max = 1000);
        ~Stack();

        void Empilhar(void* element);
        void* Desempilhar();
        void* Topo();
        bool Vazia();
        int Tamanho();
};