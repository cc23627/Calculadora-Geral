#pragma once

#include "lista_completa.hpp"

class Pilha : private ListaCompleta {
  private:
    int Tam;

  public:
    Pilha();
    void Empilha(void *);
    void *Desempilha();
    int Tamanho() const;
    void *Topo();
};
