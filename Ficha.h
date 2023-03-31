#ifndef TP1_FICHA_H
#define TP1_FICHA_H


class Ficha {
    char simbolo;
    bool estaBloqueada;
    int  turnosRestantesDesbloqueo;
public:
    /*
     * Inicializa el objeto Ficha cargando sus atributos
    */
    Ficha();
    /*
     * Inicializa el objeto Casillero cargando sus atributos y su simbolo
    */
    Ficha(char simbolo);
    /*
     * Obtiene de la ficha actual su simbolo
    */
    char getSimbolo() const;
    /*
     * Setea en la ficha actual el nuevo valor del simbolo
    */
    void setSimbolo(char simbolo);
    /*
     * Pregunta si la ficha actual esta bloqueada
    */
    bool isEstaBloqueada() const;
    /*
     * Actualiza el nuevo valor si la ficha esta bloqueada o no
    */
    void setEstaBloqueada(bool estaBloqueada);
    /*
     * Actualiza los turnos
    */
    void setTurnosRestantesDesbloqueo(int cantidadTurnos);
    /*
     * Obtiene los turnos
    */
    int getTurnosRestantesDesbloqueo();
    /*
     * Resta 1 en 1 los turnos
    */
    void decrementarTurnosRestantesDesbloqueo();
};


#endif
