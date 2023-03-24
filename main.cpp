#include <iostream>
#include "BatallaDigital.h"

int main() {
    BatallaDigital * batallaDigital = new BatallaDigital();
    batallaDigital->inicializarJuego();
    batallaDigital->jugarJuego();
    batallaDigital->mostrarTablero();
    return 0;
}
