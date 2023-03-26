#include "Casillero.h"

Casillero::Casillero() {
    this->ficha = new Ficha();
}

Casillero::Casillero(char ficha) {
    this->ficha = new Ficha(ficha);
}
