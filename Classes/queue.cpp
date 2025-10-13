#include "../Headers/queue.hpp"
#include <cstdio>

Queue::Queue(int tamanho){
    maximo = tamanho;
    area = new void*[maximo];
    inicio = 0;
    fim = -1;
    quantidade = 0;
}

Queue::~Queue(){
    delete[] area;
}

void Queue::Enfileirar(void* elemento){
    if(Cheia()){
        printf("Erro: Fila cheia!\n");
        return;
    }
    fim = (fim + 1) % maximo;
    area[fim] = elemento;
    quantidade++;
}

void* Queue::Desenfileirar(){
    if(Vazia()){
        printf("Erro: fila vazia!\n");
        return nullptr;
    }
    void* elemento = area[inicio];
    inicio = (inicio + 1) % maximo;
    quantidade--;
    return elemento;
}

void* Queue::Frente(){
    if(Vazia()){
        printf("Erro: fila vazia!\n");
        return nullptr;
    }
    return area[inicio];
}

bool Queue::Vazia(){
    return quantidade == 0;
}

bool Queue::Cheia(){
    return quantidade == maximo;
}

int Queue::Tamanho(){
    return quantidade;
}