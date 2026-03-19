#include <iostream>
#include "tablero.h"

using namespace std;

int main() {
    int ancho, alto;

    cout << "--- TETRIS UdeA 2026 ---" << endl;

    do {
        cout << "Ancho (multiplo de 8, min 8): ";
        cin >> ancho;
        cout << "Alto (min 8): ";
        cin >> alto;
        if (ancho % 8 != 0) cout << "Error: El ancho debe ser multiplo de 8." << endl;
    } while (ancho < 8 || alto < 8 || ancho % 8 != 0);

    Tablero miTablero(ancho, alto);
    bool ejecutando = true;
    char tecla;

    while (ejecutando) {
        miTablero.imprimir();
        cout << "\n[A]Izq [D]Der [S]Bajar [W]Rotar [Q]Salir" << endl;
        cout << "Accion: ";
        cin >> tecla;

        if (tecla == 'q' || tecla == 'Q') ejecutando = false;

        // Aquí puedes llamar a miTablero.limpiarFilas() despues de cada movimiento
        miTablero.limpiarFilas();
    }

    return 0;
}
