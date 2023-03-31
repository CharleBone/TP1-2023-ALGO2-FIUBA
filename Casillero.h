#ifndef TP1_CASILLERO_H
#define TP1_CASILLERO_H


#include "Ficha.h"

class Casillero {
private:
    Ficha * ficha;
public:
    Casillero();
    Casillero(char ficha);
    Ficha *getFicha();
    void setFicha(Ficha *ficha);
    bool esCasillaInactiva();
    bool hayJugador(char jugador);


};


#endif
