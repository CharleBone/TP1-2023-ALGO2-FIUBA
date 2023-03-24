#ifndef TP1_FICHA_H
#define TP1_FICHA_H


class Ficha {
    char simbolo;
    bool estaBloqueada;
    int  turnosRestantesDesbloqueo;
public:
    Ficha();
    Ficha(char simbolo);

    char getSimbolo() const;

    void setSimbolo(char simbolo);

    bool isEstaBloqueada() const;

    void setEstaBloqueada(bool estaBloqueada);
    void setTurnosRestantesDesbloqueo(int cantidadTurnos);
    int getTurnosRestantesDesbloqueo();
    void decrementarTurnosRestantesDesbloqueo();

};


#endif
