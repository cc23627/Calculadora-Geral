#include "fila.hpp"
#include "lista_completa.hpp"

Fila::Fila() : ListaCompleta(), Tam(0) {}

void Fila::Enfileira(void *E) {
    IncorporeNoFinal(E);
    Tam++;
}

void *Fila::Desenfileira() {
    Tam--;
    return DescarteDoInicio();
}

int Fila::Tamanho() const { return Tam; }
