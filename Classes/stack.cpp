#include "../Headers/stack.hpp"
#include <cstdio>

Stack::Stack(int tamanho){
    maximo = tamanho;
    topo = -1;
    area = new void*[maximo];
}

Stack::~Stack(){
    delete[] area;
}

void Stack::Empilhar(void* elemento){
    if(topo >= maximo - 1){
        printf("Erro: Pilha cheia!\n");
        return;
    }
    area[++topo] = elemento;
}

void* Stack::Desempilhar(){
    if(topo < 0){
        printf("Erro: Pilha vazia!\n");
        return nullptr;
    }
    return area[topo--];
}

void* Stack::Topo(){
    if(topo < 0){
        printf("Erro: Pilha vazia!\n");
        return nullptr;
    }
    return area[topo];
}

bool Stack::Vazia(){
    return topo < 0;
}

int Stack::Tamanho(){
    return topo + 1;
}