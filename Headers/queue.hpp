#pragma once

class Queue{
    private:
        int inicio;
        int fim;
        int maximo;
        void** area;
        int quantidade;

    public:
        Queue(int tamanho = 1000);
        ~Queue();

        void Enfileirar(void* elemento);
        void* Desenfileirar();
        void* Frente();
        bool Vazia();
        bool Cheia();
        int Tamanho();
};