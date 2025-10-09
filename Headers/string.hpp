#pragma once

#include <cstring>
#include <cstdio>  

class String {
private:
    char* dados;
    int tamanho;
    int capacidade;

    void realocar(int novaCapacidade);

public:
    
    String();                    
    String(const char* texto);   
    String(const String& outra); 
    ~String();                   

    // --- Operadores ---
    String& operator=(const String& outra);
    String& operator=(const char* texto);

    String operator+(const String& outra) const;
    String& operator+=(const String& outra);

    bool operator==(const String& outra) const;
    bool operator!=(const String& outra) const;

    char& operator[](int indice);
    const char& operator[](int indice) const;

    // --- Utilitarios ---
    int tamanhoStr() const;
    const char* c_str() const;
    void limpar();
    void exibir() const;
    void ler();
};

