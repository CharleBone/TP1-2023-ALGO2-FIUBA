//
// Created by carlos on 23/3/2023.
//

#include "Casillero.h"

Casillero::Casillero() {

}

Casillero::Casillero(char ficha) {
    this->ficha = new Ficha(ficha);
}
