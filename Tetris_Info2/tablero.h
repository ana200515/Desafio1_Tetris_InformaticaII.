#ifndef TABLERO_H
#define TABLERO_H

class Tablero {
private:
    unsigned char* datos;
    int ancho;
    int alto;

public:
    Tablero(int _a, int _alt);
    ~Tablero();

    void limpiarFilas();
    bool verificarColision(int fila, unsigned char mascara);
    void fijarPieza(int fila, unsigned char mascara);
    void imprimir();
};

#endif
