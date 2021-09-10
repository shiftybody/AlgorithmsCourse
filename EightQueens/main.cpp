#include <iostream>
using namespace std;
#define N 4

void imprimirTablero(int[][N]);
void resolverTablero(int[][N], int);
bool valido(int[][N], int, int);
void nuevoTablero(int[][N]);

int  contadorSoluciones = 0;

int main() {

    int tablero[N][N];
    nuevoTablero(tablero);

    resolverTablero(tablero, 0);
    cout << endl << "El total de soluciones posibles es:" << contadorSoluciones;

}

void nuevoTablero(int tablero[][N]) {
    for (int fila = 0; fila < N; fila++) {
        for (int columna = 0; columna < N; columna++) {
            tablero[fila][columna] = 0;
        }
    }
}

void imprimirTablero(int tablero[][N]) {
    for (int fila = 0; fila < N; fila++) {
        for (int columna = 0; columna < N; columna++) {
            cout << tablero[fila][columna] << "  ";
        }
        cout << endl;
    }
}

void resolverTablero(int tablero[][N], int col) {

    for (int fila = 0; fila < N; fila++) {
        if (valido(tablero, fila, col)) {

            tablero[fila][col] = 1;

            if (col < N-1) {
                resolverTablero(tablero, col + 1);
            } else {
                imprimirTablero(tablero);
                contadorSoluciones ++;
                cout << endl;
            }
            tablero[fila][col] = 0;
        }
    }
}

bool valido(int tablero[][N], int fila, int col) {

    for (int i = 0; i < col; i++)
        if (tablero[fila][i])
            return false;

        /* Check upper diagonal on left side */
        for (int i = fila, j = col; i >= 0 && j >= 0; i--, j--)
            if (tablero[i][j])
                return false;

            /* Check lower diagonal on left side */
            for ( int i = fila, j = col; j >= 0 && i < N; i++, j--)
                if (tablero[i][j])
                    return false;

    return true;
}





