#ifndef TP1_CASILLERO_H
#define TP1_CASILLERO_H


#include "Ficha.h"

class Casillero {
public:
    Casillero();
    Casillero(char ficha);

    Ficha * ficha;
};


#endif
