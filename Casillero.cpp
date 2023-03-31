#include "Casillero.h"

Casillero::Casillero() {
    this->ficha = new Ficha();
}

Casillero::Casillero(char ficha) {
    this->ficha = new Ficha(ficha);
}

Ficha *Casillero::getFicha() {
    return ficha;
}

bool Casillero::hayJugador(char jugador) {
    return this->ficha->getSimbolo() == jugador;
}
