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
    /*
      Este es el constructor de la clase BatallaDigital.
      Realiza la inicialización de los miembros de la clase.
    */
    BatallaDigital();
    /*
      Cargar los recursos necesarios
      Inicializar los objetos del juego
    */
    void inicializarJuego();
    /*
      Muestra el tablero actual
    */
    void mostrarTablero();
    /*
     * Crea el objeto tablero
    */
    void crearTablero();
    /*
     * Se encarga de pedir los nombres de los jugadores e inicializarlos
    */
    void crearJugadores();
    /*
     * Inicia el juego con todos sus caracteristicas ya cargadas
    */
    void jugarJuego();
    /*
     * Se define los soldados de cada jugador para llevarlos al tablero
    */
    void crearSoldados();
    /*
     * Se cargan las coordenadas de los soldados para cada jugador
    */
    void cargarSoldados(char jugador);
    /*
     * Se realiza la carga de los soldados para cada jugador
    */
    void cargarJugada(char jugador);
    /*
     * Se cargan las coordenadas de la ficha mina para ingresarla en el tablero
    */
    void cargarMinas(char i);
    /*
     * Valida si hay algun ganador validando sus soldados activos
    */
    char hayGanador();
    /*
     * Crea la movilidad de un soldado dada un movimiento y su ubicacion
    */
    void moverSoldado(char i);
    /*
     * Carga las coordenadas de fila y columna
    */
    void cargarCoordenadas(int *fila, int *columna);
    /*
     * Se define el turno actual
    */
    void definirTurnoActual(char *turnoActual) const;
    /*
     * Despues de cada turno se actualizan los casilleros que estan inactivos restando su contador
    */
    void actualizarCasilleros(char i);
    /*
     * Guarda toda la informacion del tablero de cada jugador en un archivo diferente
    */
    void GuardarTableroEnArchivo(char jugador, std::ofstream *archivo);
};

#endif
