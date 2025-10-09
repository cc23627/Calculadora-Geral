#include "../Headers/string.hpp"

void String::realocar(int novaCapacidade){
    char* novo = new char[novaCapacidade];
    if(dados){
        std::strcpy(novo, dados);
        delete[] dados;
    }else novo[0] = '\0';

    dados = novo;
    capacidade = novaCapacidade;
}

// Constutores e Destrutor

String::String(){
    tamanho = 0;
    capacidade = 16;
    dados = new char[capacidade];
    dados[0] = '\0';
}

String::String(const char* texto){
    tamanho = std::strlen(texto);
    capacidade = tamanho + 1;
    dados = new char[capacidade];
    std::strcpy(dados, texto);
}

String::String(const String& outra){
    tamanho = outra.tamanho;
    capacidade = outra.capacidade;
    dados = new char[capacidade];
    std::strcpy(dados, outra.dados);
}

String::~String(){
    delete[] dados;
}