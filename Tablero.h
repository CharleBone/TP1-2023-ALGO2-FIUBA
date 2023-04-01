#ifndef TP1_TABLERO_H
#define TP1_TABLERO_H


#include "Casillero.h"

static const int MAX_FILA = 20;
static const int MAX_COLUMNA = 20;
static const char FICHA_INACTIVA = 'X';
static const char FICHA_MINA_JUGADOR_UNO = '#';
static const char FICHA_MINA_JUGADOR_DOS = '%';
static const char FICHA_VACIA = '-';

class Tablero {
private:
    Casillero **tablero;
public:
    /*
     * Inicializa el tablero con sus respectivas filas y columnas asignando a cada casillero como vacio
    */
    Tablero();
    /*
     * Obtiene el casillero actual
    */
    Casillero **obtener();
    /*
     * Verifica si la fila y la columna son validos en el rango de la matriz
    */
    bool validarRangoTablero(int fila, int columna);
    /*
     * Valida si la posicion esta vacia
    */
    bool validarPosicion(int fila, int columna);
    /*
     * Inserta un nuevo elemento en dada posicion
    */
    void insertarPosicion(int fila, int columna, char jugador);
    /*
     * Elimina el soldado de cierta  posicion del tablero
    */
    void eliminarSoldado(int fila, int columna);
    /*
     * Obtiene la cantidad de soldados vivos por jugador
    */
    int obtenerCantidadDeSoldadosPorJugador(char jugador);
    /*
     * Dada posicion se mueve el elemento a otro casillero segun su movimiento
    */
    void moverElemento(int fila, int columna, char movimiento, char simbolo);
    /*
     * Dada la posicion se vacia completamente el casillero
    */
    void vasiarPosicion(int fila, int columna);
    /*
     * Valida si en la posicion dada hay una mina
    */
    bool hayMina(int fila, int columna);
    /*
     * Valida si en la posicion dada hay un jugador contrario
    */
    bool hayJugador(int fila, int columna, char jugador);
    /*
     * Valida si el soldado que ingresaste es un soldado tuyo
    */
    bool validarSoldadoElegido(int fila, int columna, char jugador);

    bool validarMovimiento(char movimiento);
};


#endif
