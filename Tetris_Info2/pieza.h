#ifndef PIEZA_H
#define PIEZA_H

class Pieza {
public:
    unsigned char forma[4];
    int posFila;
    int posCol;
    int tipo;

    Pieza(int t);
    void rotar();
};

#endif
