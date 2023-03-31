#ifndef TP1_TABLERO_H
#define TP1_TABLERO_H


#include "Casillero.h"

static const int MAX_FILA = 20;
static const int MAX_COLUMNA = 20;
static const char FICHA_INACTIVA = 'X';
static const char FICHA_MINA_JUGADOR_UNO = '#';
static const char FICHA_MINA_JUGADOR_DOS = '%';
class Tablero {
private:
    Casillero **tablero;
public:
    Tablero();
    Casillero **obtener();
    bool validarRangoTablero(int fila, int columna);
    bool validarPosicion(int fila, int columna);
    void insertarPosicion(int fila, int columna, char jugador);
    void eliminarSoldado(int fila, int columna);
    int obtenerCantidadDeSoldadosPorJugador(char jugador);
    void moverElemento(int fila, int columna, char movimiento, char simbolo);
    void vasiarPosicion(int fila, int columna);
    bool hayMina(int fila, int columna);
    bool esCasilleroInactivo(int fila, int columna);
    bool hayJugador(int fila, int columna, char jugador);
};


#endif
