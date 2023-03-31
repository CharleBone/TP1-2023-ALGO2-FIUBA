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
            cout<< this->tablero->obtener()[i][j].getFicha()->getSimbolo() << " " ;
        }
        cout << endl;
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
    string primerJugador;
    cout<<"Ingrese el nombre del Primer Jugador:"<<endl;
    cin>>primerJugador;
    this->jugadorUno = new Jugador(primerJugador, FICHA_JUGADOR_UNO);

    string segundoJugador;
    cout<<"Ingrese el nombre del Primer Jugador"<<endl;
    cin>>segundoJugador;
    this->jugadorDos = new Jugador(segundoJugador, FICHA_JUGADOR_DOS);
}

void BatallaDigital::jugarJuego() {
    char turnoActual = FICHA_JUGADOR_UNO;
    while (hayGanador() == 'N'){
        this->cargarMinas(turnoActual);
        this->mostrarTablero();
        this->moverSoldado(turnoActual);
        this->mostrarTablero();
        this->definirTurnoActual(&turnoActual);
    }
    this->mostrarTablero();
    cout << endl;
    cout << "El Ganador es el jugador !!! : " << hayGanador() << endl;
}

void BatallaDigital::definirTurnoActual(char *turnoActual) const {
    if (*turnoActual == FICHA_JUGADOR_UNO) {
        *turnoActual = FICHA_JUGADOR_DOS;
    } else if (*turnoActual == FICHA_JUGADOR_DOS){
        *turnoActual = FICHA_JUGADOR_UNO;
    }
}

void BatallaDigital::crearSoldados() {
    cargarSoldados(FICHA_JUGADOR_UNO);
    cargarSoldados(FICHA_JUGADOR_DOS);
}

void BatallaDigital::cargarSoldados(char jugador) {
    for (int i = 0; i < 4; i++) {
        cargarJugada( jugador);
        mostrarTableroPorJugador(jugador);
    }
}

void BatallaDigital::cargarJugada(char jugador) {
    cout <<  "Turno del Jugador: " << jugador << endl;
    cout << "Ingrese las 4 posiciones para sus soldados:" << endl;
    int fila ;
    int columna ;
    this->cargarCoordenadas(&fila, &columna);
    while (!this->tablero->validarRangoTablero(fila, columna) ){
        cout << "Error, Vuelva a Ingresar los datos correctos" << endl;
        cout << "Ingrese las 4 posiciones para sus soldados" << endl;
        int fila ;
        int columna ;
        this->cargarCoordenadas(&fila, &columna);
    }
    if (this->tablero->hayJugador(fila, columna, jugador == FICHA_JUGADOR_UNO ? FICHA_JUGADOR_DOS : FICHA_JUGADOR_UNO)) {
        this->tablero->eliminarSoldado(fila, columna);
    } else {
        this->tablero->insertarPosicion(fila,columna,jugador);
    }
}

void BatallaDigital::mostrarTableroPorJugador(char jugador) {

}

void BatallaDigital::cargarMinas(char jugador) {
    cout << "Turno del jugador : " << jugador << endl;
    cout << "Ingrese la posicion de su mina: " << endl;
    int fila ;
    int columna ;
    this->cargarCoordenadas(&fila, &columna);
    bool esPosicionValida = this->tablero->validarPosicion(fila,columna);
    if (esPosicionValida) {
        this->tablero->insertarPosicion(fila,columna, jugador == FICHA_JUGADOR_UNO ? FICHA_MINA_JUGADOR_UNO : FICHA_MINA_JUGADOR_DOS);
    } else {
        this->tablero->eliminarSoldado(fila,columna);
    }
}

char BatallaDigital::hayGanador() {
    int totalSoldados = this->tablero->obtenerCantidadDeSoldadosPorJugador(FICHA_JUGADOR_UNO);
    int totalSoldadosDos = this->tablero->obtenerCantidadDeSoldadosPorJugador(FICHA_JUGADOR_DOS);
    if (totalSoldados == 0) {
        return FICHA_JUGADOR_UNO;
    } else if (totalSoldadosDos == 0){
        return FICHA_JUGADOR_DOS;
    } else {
        return 'N';
    }
}

void BatallaDigital::moverSoldado(char jugador) {
    cout << "Turno del jugador : " << jugador << endl;
    cout << "Ingrese la posicion del soldado a mover: " << endl;
    int fila ;
    int columna ;
    char movimiento;
    this->cargarCoordenadas(&fila, &columna);
    cout << "Ingrese Movimiento" << endl;
    cin >> movimiento;
    this->tablero->moverElemento(fila, columna, movimiento, FICHA_JUGADOR_UNO);
}

void BatallaDigital::cargarCoordenadas(int *fila, int *columna) {
    cout << "Ingrese Fila" << endl;
    cin >> *fila ;

    cout << "Ingrese Columna" << endl;
    cin >> *columna;
}



