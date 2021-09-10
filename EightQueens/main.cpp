#include <iostream>

using namespace std;
#define N 8


void imprimirTablero(int[][N]);

bool resolverTablero(int[][N]);

int main() {
    int tablero[N][N];

    for (int fila = 0; fila < N; fila++) {
        for (int columna = 0; columna < N; columna++) {
            tablero[fila][columna] = 0;
        }
    }

    if (resolverTablero(tablero)) {
        imprimirTablero(tablero);
    } else cout << "No se puede resolver";

}

bool resolverTablero(int [][N] int col) {

    return false;
}

void imprimirTablero(int tablero[][N]) {
    for (int fila = 0; fila < N; fila++) {
        for (int columna = 0; columna < N; columna++) {
            cout << tablero[fila][columna] << "  ";
        }
        cout << endl;
    }
}





