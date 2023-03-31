#ifndef TP1_BATALLADIGITAL_H
#define TP1_BATALLADIGITAL_H
#include "Tablero.h"
#include "Jugador.h"

static const char FICHA_JUGADOR_UNO = '1';
static const char FICHA_JUGADOR_DOS = '2';

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
    void mostrarTableroPorJugador(char jugador);
    void cargarMinas(char i);
    char hayGanador();
    void moverSoldado(char i);
    void cargarCoordenadas(int *fila, int *columna);

    void definirTurnoActual(char *turnoActual) const;

    void actualizarCasilleros(char i);
};

#endif
