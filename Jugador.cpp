#include "Jugador.h"

using namespace std;

Jugador::Jugador(std::string nombre, char simboloFicha) {
    this->nombreJugador = nombre;
    this->fichaJugador = new Ficha(simboloFicha);
}

string Jugador::obtenerNombreJugador() {
    return this->nombreJugador;
}

char Jugador::obtenerSimboloFichaJugador() {
    return this->fichaJugador->getSimbolo();
}

void Jugador::setNombreJugador(string nombre) {
    this->nombreJugador = nombre;
}

void Jugador::setFichaJugador(Ficha *nuevaFicha) {
    this->fichaJugador = nuevaFicha;
}
