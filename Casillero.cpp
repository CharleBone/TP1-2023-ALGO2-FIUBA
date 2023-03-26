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
