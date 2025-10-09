#include "pilha.hpp"
#include "lista_completa.hpp"

Pilha::Pilha() : ListaCompleta(), Tam(0) {}

void Pilha::Empilha(void *E) {
    IncorporeNoInicio(E);
    Tam++;
}

void *Pilha::Desempilha() {
    Tam--;
    return DescarteDoInicio();
}

int Pilha::Tamanho() const { return Tam; }

void *Pilha::Topo(){
    if(Tam == 0) return nullptr;
    void *elementoTopo = DescarteDoFinal();
    IncorporeNoFinal(elementoTopo);
    return elementoTopo;
}

