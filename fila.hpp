#pragma once

#include "lista_completa.hpp"

class Fila : private ListaCompleta {
  private:
    int Tam;

  public:
    Fila();
    void Enfileira(void *);
    void *Desenfileira();
    int Tamanho() const;
};
