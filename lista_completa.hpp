#pragma once

#include "lista.hpp"

class ListaCompleta : public Lista {
  public:
    void IncorporeNoInicio(void *);
    void *DescarteDoInicio();
    void IncorporeNoFinal(void *);
    void *DescarteDoFinal();
    int Contem(void *) const;
    void Descarte(void *);
    char *NaFormaDeString() const;
};
