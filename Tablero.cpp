#include "Tablero.h"

Tablero::Tablero() {
    this->tablero = new Casillero *[20];
    for (int i = 0; i < 20; i++) {
        tablero[i] = new Casillero  [20];
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

