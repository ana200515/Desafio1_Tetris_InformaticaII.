#ifndef TABLERO_H
#define TABLERO_H

#include "pieza.h"

class Tablero {
public:
    int ancho;
    int alto;
    unsigned char* filas;

    Tablero(int a, int h);
    ~Tablero();

    void imprimir(Pieza &p);
    bool colision(Pieza &p);
    void fijar(Pieza &p);
    void limpiarFilas();
};

#endif
