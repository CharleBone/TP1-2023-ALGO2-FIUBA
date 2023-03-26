#include "Tablero.h"

Tablero::Tablero() {
    this->tablero = new Casillero *[20];
    for (int i = 0; i < 20; i++) {
        tablero[i] = new Casillero[20];
        for (int j = 0; j < 20; j++) {
            Casillero * casillero =  new Casillero('-');
            this->tablero[i][j] = * casillero;
        }
    }
}

Casillero **Tablero::obtener() {
    return this->tablero;
}


bool Tablero::validarPosicion(int fila, int columna) {
    bool estaOcupada = true;
    if (this->tablero[fila][columna].ficha->getSimbolo() != '-') {
        estaOcupada = false;
    }
    return estaOcupada;
}

void Tablero::insertarPosicion(int fila, int columna, char ficha) {
    Casillero * casillero =  new Casillero(ficha);
    this->tablero[fila][columna] = * casillero;
}

void Tablero::eliminarSoldado(int fila, int columna) {
    this->tablero[fila][columna].ficha->setSimbolo('X');
    this->tablero[fila][columna].ficha->setEstaBloqueada(true);
    this->tablero[fila][columna].ficha->setTurnosRestantesDesbloqueo(5);
}

int Tablero::obtenerCantidadDeSoldadosPorJugador(char jugador) {
    int cantidadTotal = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (this->tablero[i][j].ficha->getSimbolo() == jugador) {
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
            this->tablero[fila - 1][columna] =  * casillero;
        }
        case 's':
        case 'S': {
            vasiarPosicion(fila, columna);
            this->tablero[fila + 1][columna] =  * casillero;
        }
        case 'a':
        case 'A': {
            vasiarPosicion(fila, columna);
            this->tablero[fila][columna - 1] =  * casillero;
        }
        case 'd':
        case 'D': {
            vasiarPosicion(fila, columna);
            this->tablero[fila][columna + 1] =  * casillero;
        }
        case 'q':
        case 'Q': {
            vasiarPosicion(fila, columna);
            this->tablero[fila - 1][columna - 1] =  * casillero;
        }
        case 'e':
        case 'E': {
            vasiarPosicion(fila, columna);
            this->tablero[fila - 1][columna + 1] =  * casillero;
        }
        case 'z':
        case 'Z': {
            vasiarPosicion(fila, columna);
            this->tablero[fila + 1][columna - 1] =  * casillero;
        }
        case 'x':
        case 'X': {
            vasiarPosicion(fila, columna);
            this->tablero[fila - 1][columna + 1] =  * casillero;
        }
    }


}

void Tablero::vasiarPosicion(int fila, int columna) {
    Casillero * casillero =  new Casillero();
    this->tablero[fila][columna] = * casillero;
}

