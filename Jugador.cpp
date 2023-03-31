#include "Jugador.h"

using namespace std;

Jugador::Jugador(std::string nombre, char simboloFicha) {
    this->nombreJugador = nombre;
    this->fichaJugador = new Ficha(simboloFicha);
}

