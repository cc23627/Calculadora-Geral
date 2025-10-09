#include "../Headers/string.hpp"

void String::realocar(int novaCapacidade){
    char* novo = new char[novaCapacidade];
    if(dados){
        strcpy(novo, dados);
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
    strcpy(dados, texto);
}

String::String(const String& outra){
    tamanho = outra.tamanho;
    capacidade = outra.capacidade;
    dados = new char[capacidade];
    strcpy(dados, outra.dados);
}

String::~String(){
    delete[] dados;
}

// Atribuição
String& String::operator=(const String& outra){
    if(this != &outra){
        delete[] dados;
        tamanho = outra.tamanho;
        capacidade = outra.capacidade;
        dados = new char[capacidade];
        strcpy(dados, outra.dados);
    }
    return *this;
}

String& String::operator=(const char* texto){
    int novoTamanho = std::strlen(texto);
    if(novoTamanho + 1 > capacidade){
        realocar(novoTamanho + 1);
    }
    tamanho = novoTamanho;
    strcpy(dados, texto);
    return *this;
}

// Concatenação
String String::operator+(const String& outra) const {
    String resultado;
    resultado.tamanho = tamanho + outra.tamanho;
    resultado.capacidade = resultado.tamanho + 1;
    delete[] resultado.dados;
    resultado.dados = new char[resultado.capacidade];
    strcpy(resultado.dados, dados);
    strcat(resultado.dados, outra.dados);
    return resultado;
}

String& String::operator+=(const String& outra) {
    int novoTam = tamanho + outra.tamanho;
    if (novoTam + 1 > capacidade)
        realocar(novoTam + 1);
    strcat(dados, outra.dados);
    tamanho = novoTam;
    return *this;
}

// Comparação
bool String::operator==(const String& outra) const {
    return strcmp(dados, outra.dados) == 0;
}

bool String::operator!=(const String& outra) const {
    return !(*this == outra);
}

// Acesso
char& String::operator[](int indice) {
    return dados[indice];
}

const char& String::operator[](int indice) const {
    return dados[indice];
}

// Utilitários
int String::tamanhoStr() const {
    return tamanho;
}

const char* String::c_str() const {
    return dados;
}

void String::limpar() {
    dados[0] = '\0';
    tamanho = 0;
}

// I/O Básico
void String::exibir() const {
    printf("%s", dados);
}

void String::ler() {
    char buffer[1024];
    std::scanf(" %[^\n]", buffer);
    *this = buffer;
}