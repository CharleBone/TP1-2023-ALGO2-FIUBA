#include "Ficha.h"

Ficha::Ficha() {
    this->simbolo = '-';
    this->estaBloqueada = false;
    this->turnosRestantesDesbloqueo = 0;
}

Ficha::Ficha(char ficha) {
    this->simbolo = ficha;
    this->estaBloqueada = false;
    this->turnosRestantesDesbloqueo = 0;
}

char Ficha::getSimbolo() const {
    return simbolo;
}

void Ficha::setSimbolo(char simbolo) {
    Ficha::simbolo = simbolo;
}

bool Ficha::isEstaBloqueada() const {
    return estaBloqueada;
}

void Ficha::setEstaBloqueada(bool estaBloqueada) {
    Ficha::estaBloqueada = estaBloqueada;
}

void Ficha::setTurnosRestantesDesbloqueo(int cantidadTurnos) {
    this->turnosRestantesDesbloqueo = cantidadTurnos;
}

int Ficha::getTurnosRestantesDesbloqueo() {
    return this->turnosRestantesDesbloqueo;
}

void Ficha::decrementarTurnosRestantesDesbloqueo() {
    this->turnosRestantesDesbloqueo--;
}
