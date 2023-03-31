#include <iostream>
#include "BatallaDigital.h"

using namespace std;
int main() {
    BatallaDigital * batallaDigital = new BatallaDigital();
    batallaDigital->inicializarJuego();
    batallaDigital->jugarJuego();
    batallaDigital->mostrarTablero();
    return 0;
}
