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

void Casillero::setFicha(Ficha *ficha) {
    Casillero::ficha = ficha;
}

bool Casillero::esCasillaInactiva() {
    return this->ficha->isEstaBloqueada();
}

bool Casillero::hayJugador(char jugador) {
    return this->ficha->getSimbolo() == jugador;
}
