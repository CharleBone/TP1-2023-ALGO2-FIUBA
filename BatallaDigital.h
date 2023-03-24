#ifndef TP1_BATALLADIGITAL_H
#define TP1_BATALLADIGITAL_H
#include "Tablero.h"
#include "Jugador.h"

class BatallaDigital {

private:
    Tablero * tablero;
    Jugador * jugadorUno;
    Jugador * jugadorDos;

public:
    BatallaDigital();
    void inicializarJuego();
    void mostrarTablero();
    void crearTablero();
    void crearJugadores();
    void jugarJuego();
    void crearSoldados();
    void cargarSoldados(char jugador);
    void cargarJugada(char jugador);
    void mostrarTableroJugadorUno(char jugador);
    void cargarMinas();
    bool hayGanador();
};

#endif
