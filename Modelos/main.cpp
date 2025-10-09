#include "fila.hpp"
#include "pilha.hpp"
#include <iostream>
#include <cctype>
#include <stdexcept>

int precedencia(char operador){
    if(operador == '=' || operador == '>' || operador == '<') return 1;
    if(operador == '+' || operador == '-') return 2;
    if(operador == '*' || operador == '/' || operador == '%') return 3;
    return 0;
}

bool ehOperador(char caracter){
    return caracter=='+' || caracter=='-' ||
           caracter=='*' || caracter=='/' ||
           caracter=='%' || caracter=='<' || 
           caracter=='>' || caracter=='=';
}

void removerEspacos(char* s){
    int j = 0;
    for (int i = 0; s[i]; i++) 
        if(!isspace(s[i])) s[j++] = s[i];
    s[j] = '\0';
}

void infixaParaPosfixa(const char* expressao, char* saida){
    Pilha pilha;
    int indiceSaida = 0;
    char temporario[100];
    int i = 0;

    while(expressao[i] != '\0'){
        char caracter = expressao[i];

        // número
        if(isdigit(caracter)){
            int j = 0;
            while(isdigit(expressao[i]) || expressao[i] == '.') 
                temporario[j++] = expressao[i++];
            temporario[j] = '\0';
            i--;

            for(int k = 0; temporario[k]; k++) 
                saida[indiceSaida++] = temporario[k];
            saida[indiceSaida++] = ' ';
        }
        // abre parêntese
        else if(caracter == '('){
            char* ptr = new char(caracter);
            pilha.Empilha(ptr);
        }
        // fecha parêntese
        else if(caracter == ')'){
            // desempilha até encontrar '('
            while(pilha.Tamanho() != 0 && *(char*)pilha.Topo() != '('){
                char* ptr = (char*)pilha.Desempilha();
                saida[indiceSaida++] = *ptr;
                saida[indiceSaida++] = ' ';
                delete ptr;
            }

            if(pilha.Tamanho() == 0)
                throw std::runtime_error("Parênteses desbalanceados");

            // remove '(' da pilha
            char* ptr = (char*)pilha.Desempilha();
            delete ptr;
        }
        // operador
        else if(ehOperador(caracter)){
            while(pilha.Tamanho() != 0 && ehOperador(*(char*)pilha.Topo()) &&
                  precedencia(*(char*)pilha.Topo()) >= precedencia(caracter)){
                char* ptr = (char*)pilha.Desempilha();
                saida[indiceSaida++] = *ptr;
                saida[indiceSaida++] = ' ';
                delete ptr;
            }
            char* ptr = new char(caracter);
            pilha.Empilha(ptr);
        }
        else{
            throw std::runtime_error("Símbolo inválido");
        }

        i++;
    }

    // desempilha o que sobrou
    while(pilha.Tamanho() > 0){
        if(*(char*)pilha.Topo() == '(')
            throw std::runtime_error("Parênteses desbalanceados");

        char* ptr = (char*)pilha.Desempilha();
        saida[indiceSaida++] = *ptr;
        saida[indiceSaida++] = ' ';
        delete ptr;
    }

    saida[indiceSaida] = '\0';
}


int main() {
    char expressao[100];
    char posFixa[200];

    std::cout << "Digite a expressão: ";
    std::cin.getline(expressao, 100);

    try{
        removerEspacos(expressao);
        infixaParaPosfixa(expressao, posFixa);
        std::cout << "Pós-fixa: " << posFixa << std::endl;
    }catch(std::exception& e){
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}
