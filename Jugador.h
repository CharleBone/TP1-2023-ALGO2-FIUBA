#ifndef TP1_JUGADOR_H
#define TP1_JUGADOR_H
#include <string>
#include "Ficha.h"

class Jugador {
private:
    std::string  nombreJugador;
    Ficha * fichaJugador;
public:
    Jugador(std::string nombre,char simboloFicha);
    std::string obtenerNombreJugador();
    char obtenerSimboloFichaJugador();
    void setNombreJugador(std::string nombre);
    void setFichaJugador(Ficha * nuevaFicha);
};


#endif
