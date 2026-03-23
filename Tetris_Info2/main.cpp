#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pieza.h"
#include "tablero.h"

using namespace std;

int main()
{
    srand(time(0));

    int ancho = 8;
    int alto = 16;

    Tablero tablero(ancho, alto);
    Pieza pieza(rand() % 5);

    char opcion;

    while (true) {

        system("cls");

        tablero.imprimir(pieza);

        cout << "\nControles:\n";
        cout << "a: izquierda\n";
        cout << "d: derecha\n";
        cout << "s: bajar\n";
        cout << "w: rotar\n";
        cout << "q: salir\n";

        cin >> opcion;

        int oldFila = pieza.posFila;
        int oldCol = pieza.posCol;

        if (opcion == 'a') pieza.posCol--;
        if (opcion == 'd') pieza.posCol++;
        if (opcion == 's') pieza.posFila++;
        if (opcion == 'w') pieza.rotar();
        if (opcion == 'q') break;

        if (pieza.posCol < 0) pieza.posCol = 0;
        if (pieza.posCol > 7) pieza.posCol = 7;

        if (tablero.colision(pieza)) {

            pieza.posFila = oldFila;
            pieza.posCol = oldCol;

            if (opcion == 's') {
                tablero.fijar(pieza);
                tablero.limpiarFilas();

                pieza = Pieza(rand() % 5);

                if (tablero.colision(pieza)) {
                    cout << "GAME OVER\n";
                    break;
                }
            }
        }
    }

    return 0;
}
