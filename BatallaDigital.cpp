#include "iostream"
#include "BatallaDigital.h"

using namespace std;

BatallaDigital::BatallaDigital() {
    this->tablero = NULL;
    this->jugadorUno = NULL;
    this->jugadorDos = NULL;
}

void BatallaDigital::mostrarTablero() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            std::cout<< this->tablero->obtener()[i][j].ficha->getSimbolo() << " " ;
        }
        std::cout << std::endl;
    }
}

void BatallaDigital::inicializarJuego() {
    this->crearTablero();
    this->crearJugadores();
    this->crearSoldados();
}

void BatallaDigital::crearTablero() {
    this->tablero = new Tablero();
}

void BatallaDigital::crearJugadores() {
    std::string primerJugador;
    cout<<"Ingrese el nombre del Primer Jugador ";
    cin>>primerJugador;
    this->jugadorUno = new Jugador(primerJugador, '1');

    std::string segundoJugador;
    cout<<"Ingrese el nombre del Primer Jugador ";
    cin>>segundoJugador;
    this->jugadorDos = new Jugador(segundoJugador, '2');
}

void BatallaDigital::jugarJuego() {
    while (!hayGanador()){
        this->cargarMinas();
        this->mostrarTablero();
        this->moverSoldado();
        this->mostrarTablero();
    }
    this->mostrarTablero();
}

void BatallaDigital::crearSoldados() {
    cargarSoldados('1');
    cargarSoldados('2');
}

void BatallaDigital::cargarSoldados(char jugador) {
    for (int i = 0; i < 4; i++) {
        cargarJugada( jugador);
        mostrarTableroJugadorUno(jugador);
    }
}

void BatallaDigital::cargarJugada(char jugador) {
    cout << "Ingrese las 4 posiciones para sus soldados" << endl;
    int fila ;
    int columna ;
    cout << "Ingrese Fila" << endl;
    cin >> fila ;

    cout << "Ingrese Columna" << endl;
    cin >> columna;
    bool esPosicionValida = this->tablero->validarPosicion(fila,columna);
    if (esPosicionValida) {
        this->tablero->insertarPosicion(fila,columna,jugador);
    } else {
        string error = "Error";
        throw error;
    }
}

void BatallaDigital::mostrarTableroJugadorUno(char jugador) {

}

void BatallaDigital::cargarMinas() {
    cout << "Ingrese la posicion de su mina" << endl;
    int fila ;
    int columna ;
    cout << "Ingrese Fila" << endl;
    cin >> fila ;

    cout << "Ingrese Columna" << endl;
    cin >> columna;
    bool esPosicionValida = this->tablero->validarPosicion(fila,columna);
    if (esPosicionValida) {
        this->tablero->insertarPosicion(fila,columna, '#');
    } else {
        this->tablero->eliminarSoldado(fila,columna);
    }
}

bool BatallaDigital::hayGanador() {
    int totalSoldados = this->tablero->obtenerCantidadDeSoldadosPorJugador('1');
    int totalSoldadosDos = this->tablero->obtenerCantidadDeSoldadosPorJugador('2');
    if (totalSoldados == 0) {
        return true;
    } else if (totalSoldadosDos == 0){
        return true;
    }
    return false;
}

void BatallaDigital::moverSoldado() {
    cout << "Ingrese la posicion del soldado a mover" << endl;
    int fila ;
    int columna ;
    char movimiento;
    cout << "Ingrese Fila" << endl;
    cin >> fila ;

    cout << "Ingrese Columna" << endl;
    cin >> columna;

    cout << "Ingrese Movimiento" << endl;
    cin >> movimiento;
    this->tablero->moverElemento(fila, columna, movimiento, '1');
}


