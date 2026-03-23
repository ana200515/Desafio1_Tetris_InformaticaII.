#include <iostream>
#include "tablero.h"

using namespace std;

Tablero::Tablero(int a, int h)
{
    ancho = a;
    alto = h;

    filas = new unsigned char[alto];

    for (int i = 0; i < alto; i++)
        filas[i] = 0;
}

Tablero::~Tablero()
{
    delete[] filas;
}

void Tablero::imprimir(Pieza &p)
{
    for (int i = 0; i < alto; i++) {

        unsigned char filaTemp = filas[i];

        for (int j = 0; j < 4; j++) {
            int filaPieza = p.posFila + j;

            if (i == filaPieza) {
                filaTemp |= (p.forma[j] >> p.posCol);
            }
        }

        for (int b = 7; b >= 0; b--) {
            if (filaTemp & (1 << b))
                cout << "#";
            else
                cout << ".";
        }

        cout << endl;
    }
}

bool Tablero::colision(Pieza &p)
{
    for (int i = 0; i < 4; i++) {

        int filaTablero = p.posFila + i;

        if (filaTablero >= alto)
            return true;

        unsigned char piezaFila = p.forma[i] >> p.posCol;

        if (filas[filaTablero] & piezaFila)
            return true;
    }

    return false;
}

void Tablero::fijar(Pieza &p)
{
    for (int i = 0; i < 4; i++) {

        int filaTablero = p.posFila + i;

        if (filaTablero < alto) {
            filas[filaTablero] |= (p.forma[i] >> p.posCol);
        }
    }
}

void Tablero::limpiarFilas()
{
    for (int i = 0; i < alto; i++) {

        if (filas[i] == 0b11111111) {

            for (int j = i; j > 0; j--)
                filas[j] = filas[j - 1];

            filas[0] = 0;

            i--;
        }
    }
}
