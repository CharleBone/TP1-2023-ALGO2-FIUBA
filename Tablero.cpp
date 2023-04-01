#include "Tablero.h"

Tablero::Tablero() {
    this->tablero = new Casillero *[MAX_FILA];
    for (int i = 0; i < MAX_FILA; i++) {
        tablero[i] = new Casillero[MAX_COLUMNA];
        for (int j = 0; j < MAX_COLUMNA; j++) {
            Casillero * casillero =  new Casillero(FICHA_VACIA);
            this->tablero[i][j] = * casillero;
        }
    }
}

Casillero **Tablero::obtener() {
    return this->tablero;
}


bool Tablero::validarPosicion(int fila, int columna) {
    bool estaOcupada = true;
    if (this->tablero[fila][columna].getFicha()->getSimbolo() != FICHA_VACIA) {
        estaOcupada = false;
    }
    return estaOcupada;
}

void Tablero::insertarPosicion(int fila, int columna, char ficha) {
    Casillero * casillero =  new Casillero(ficha);
    this->tablero[fila][columna] = * casillero;
}

void Tablero::eliminarSoldado(int fila, int columna) {
    this->tablero[fila][columna].getFicha()->setSimbolo(FICHA_INACTIVA);
    this->tablero[fila][columna].getFicha()->setEstaBloqueada(true);
    this->tablero[fila][columna].getFicha()->setTurnosRestantesDesbloqueo(5);
}

int Tablero::obtenerCantidadDeSoldadosPorJugador(char jugador) {
    int cantidadTotal = 0;
    for (int i = 0; i < MAX_FILA; i++) {
        for (int j = 0; j < MAX_COLUMNA; j++) {
            if (this->tablero[i][j].getFicha()->getSimbolo() == jugador) {
                cantidadTotal++;
            }
        }
    }
    return cantidadTotal;
}

void Tablero::moverElemento(int fila, int columna, char movimiento, char simbolo) {
    Casillero * casillero =  new Casillero(simbolo);
    switch (movimiento) {
        case 'w':
        case 'W': {
            vasiarPosicion(fila, columna);
            if (hayMina(fila - 1 , columna)) {
                eliminarSoldado(fila - 1, columna);
            } else {
                this->tablero[fila - 1][columna] =  * casillero;
            }
            break;
        }
        case 's':
        case 'S': {
            vasiarPosicion(fila, columna);
            if (hayMina(fila + 1 , columna)) {
                eliminarSoldado(fila + 1, columna);
            } else {
                this->tablero[fila + 1][columna] =  * casillero;
            }
            break;
        }
        case 'a':
        case 'A': {
            vasiarPosicion(fila, columna);
            if (hayMina(fila , columna - 1)) {
                eliminarSoldado(fila, columna - 1);
            } else {
                this->tablero[fila][columna - 1] =  * casillero;
            }
            break;
        }
        case 'd':
        case 'D': {
            vasiarPosicion(fila, columna);
            if (hayMina(fila , columna + 1)) {
                eliminarSoldado(fila, columna + 1);
            } else {
                this->tablero[fila][columna + 1] =  * casillero;
            }
            break;
        }
        case 'q':
        case 'Q': {
            vasiarPosicion(fila, columna);
            if (hayMina(fila - 1, columna - 1)) {
                eliminarSoldado(fila - 1, columna - 1);
            } else {
                this->tablero[fila - 1][columna - 1] =  * casillero;
            }
            break;
        }
        case 'e':
        case 'E': {
            vasiarPosicion(fila, columna);
            if (hayMina(fila - 1, columna + 1)) {
                eliminarSoldado(fila - 1, columna + 1);
            } else {
                this->tablero[fila - 1][columna + 1] =  * casillero;
            }
            break;
        }
        case 'z':
        case 'Z': {
            vasiarPosicion(fila, columna);
            if (hayMina(fila + 1, columna - 1)) {
                eliminarSoldado(fila + 1, columna - 1);
            } else {
                this->tablero[fila + 1][columna - 1] =  * casillero;
            }
            break;
        }
        case 'x':
        case FICHA_INACTIVA: {
            vasiarPosicion(fila, columna);
            if (hayMina(fila + 1, columna + 1)) {
                eliminarSoldado(fila + 1, columna + 1);
            } else {
                this->tablero[fila + 1][columna + 1] =  * casillero;
            }
            break;
        }
    }
}

void Tablero::vasiarPosicion(int fila, int columna) {
    Casillero * casillero =  new Casillero();
    this->tablero[fila][columna] = * casillero;
}

bool Tablero::hayMina(int fila, int columna) {
    bool hayMina = false;
    if (this->tablero[fila][columna].getFicha()->getSimbolo() == FICHA_MINA_JUGADOR_UNO) {
        hayMina = true;
    }
    return hayMina;
}

bool Tablero::hayJugador(int fila, int columna, char jugador) {
    return this->tablero[fila][columna].hayJugador(jugador);
}

bool Tablero::validarRangoTablero(int fila, int columna) {
    return (fila >= 0 && fila < 20) && (columna >= 0 && columna < 20);
}

bool Tablero::validarSoldadoElegido(int fila, int columna, char jugador) {
    return this->tablero[fila][columna].getFicha()->getSimbolo() == jugador;
}

bool Tablero::validarMovimiento(char movimiento) {
    bool esMovimientoValido = false;
    if (movimiento == 'w' || movimiento == 'W' || movimiento == 'a' || movimiento == 'A' ||
            movimiento == 's' || movimiento == 'S' || movimiento == 'd' || movimiento == 'D' ||
            movimiento == 'z' || movimiento == 'Z' || movimiento == 'x' || movimiento == 'X' ){
        esMovimientoValido = true;
    }
    return esMovimientoValido;
}

