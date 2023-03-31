#ifndef TP1_CASILLERO_H
#define TP1_CASILLERO_H


#include "Ficha.h"

class Casillero {
private:
    Ficha * ficha;
public:
    /*
     * Inicializa el objeto Casillero cargando sus atributos
    */
    Casillero();
    /*
     * Inicializa el objeto Casillero cargando sus atributos y dando su ficha
    */
    Casillero(char ficha);
    /*
     * Obtiene la ficha actual
    */
    Ficha *getFicha();
    /*
     * Valida si hay un jugador en esa posicion
    */
    bool hayJugador(char jugador);


};


#endif
