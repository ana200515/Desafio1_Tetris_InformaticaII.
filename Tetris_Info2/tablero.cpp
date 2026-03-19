#include "tablero.h"
#include <iostream>

using namespace std;

Tablero::Tablero(int _a, int _alt) : ancho(_a), alto(_alt) {
    datos = new unsigned char[alto];
    for (int i = 0; i < alto; i++) {
        datos[i] = 0;
    }
}

Tablero::~Tablero() {
    delete[] datos;
}

void Tablero::limpiarFilas() {
    unsigned char filaLlena = 0xFF;

    for (int i = 0; i < alto; i++) {
        if (datos[i] == filaLlena) {
            for (int j = i; j > 0; j--) {
                datos[j] = datos[j - 1];
            }
            datos[0] = 0;
        }
    }
}

void Tablero::imprimir() {
    for (int i = 0; i < alto; i++) {
        cout << "|";
        for (int j = 7; j >= 0; j--) {
            if (datos[i] & (1 << j)) {
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << "|" << endl;
    }
}

bool Tablero::verificarColision(int fila, unsigned char mascara) {
    if (fila >= alto) return true;
    return (datos[fila] & mascara) != 0;
}

void Tablero::fijarPieza(int fila, unsigned char mascara) {
    if (fila < alto) {
        datos[fila] |= mascara;
    }
}
