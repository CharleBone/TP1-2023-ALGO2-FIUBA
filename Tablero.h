#ifndef TP1_TABLERO_H
#define TP1_TABLERO_H


#include "Casillero.h"

class Tablero {
private:
    Casillero **tablero;
public:
    Tablero();
    Casillero **obtener();
    bool validarPosicion(int fila, int columna);
    void insertarPosicion(int fila, int columna, char jugador);
    void eliminarSoldado(int fila, int columna);
    int obtenerCantidadDeSoldadosPorJugador(char jugador);
    void moverElemento(int fila, int columna, char movimiento, char simbolo);
    void vasiarPosicion(int fila, int columna);
};


#endif
