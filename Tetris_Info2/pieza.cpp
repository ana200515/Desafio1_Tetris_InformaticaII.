#include "pieza.h"

Pieza::Pieza(int t)
{
    tipo = t;
    posFila = 0;
    posCol = 3;

    for (int i = 0; i < 4; i++)
        forma[i] = 0;

    if (tipo == 0) { // O
        forma[0] = 0b00110000;
        forma[1] = 0b00110000;
    }
    else if (tipo == 1) { // I
        forma[1] = 0b00111100;
    }
    else if (tipo == 2) { // L
        forma[0] = 0b00100000;
        forma[1] = 0b00100000;
        forma[2] = 0b00110000;
    }
    else if (tipo == 3) { // T
        forma[0] = 0b00111000;
        forma[1] = 0b00010000;
    }
    else if (tipo == 4) { // Z
        forma[0] = 0b00110000;
        forma[1] = 0b00011000;
    }
}

void Pieza::rotar()
{
    unsigned char temp[4] = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            if (forma[i] & (1 << (7 - j))) {

                int newRow = j;
                int newCol = 3 - i;

                temp[newRow] |= (1 << (7 - newCol));
            }
        }
    }

    for (int i = 0; i < 4; i++)
        forma[i] = temp[i];
}
