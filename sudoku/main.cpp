#include <iostream>
using namespace std;
#define N 9

void imprimirSudoku(int [][N]);
void separarFila();
void separarColumna();
bool resolverSudoku(int [][N]);
bool usadoEnFila(int [][N], int, int);
bool usadoEnColumna(int [][N], int, int);
bool usadoEnSubMatriz(int [][N], int, int, int);
bool estaVacio(int [][N], int &, int &);
bool esSeguro(int [][N], int, int, int);

int main() {

    int matriz[N][N] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                        {6, 0, 0, 1, 9, 5, 0, 0, 0},
                        {0, 9, 8, 0, 0, 0, 0, 6, 0},
                        {8, 0, 0, 0, 6, 0, 0, 0, 3},
                        {4, 0, 0, 8, 0, 3, 0, 0, 1},
                        {7, 0, 0, 0, 2, 4, 0, 0, 6},
                        {0, 6, 0, 0, 0, 0, 2, 8, 0},
                        {0, 0, 0, 4, 1, 9, 0, 0, 5},
                        {0, 0, 0, 0, 8, 6, 0, 7, 9}};

    imprimirSudoku(matriz);
    cout << endl;

    if (resolverSudoku(matriz))
        imprimirSudoku(matriz);
    else
        cout << "No existe solución";

    return 0;
}

void imprimirSudoku(int matriz[N][N]) {

    for (int fila = 0; fila < N; fila++) {
        if (fila % 3 == 0) {
            separarFila();
        }
        for (int columna = 0; columna < N; columna++) {
            if (columna % 3 == 0) {
                separarColumna();
                cout << matriz[fila][columna];
            } else
                cout << "  " << matriz[fila][columna];
        }
        separarColumna();
        cout << endl;
    }
    separarFila();
}

void separarFila() {
    for (int i = 0; i < N; ++i) {
        if (i % 3 == 0) {
            cout << "  *" << "  -";
        } else cout << "  -";
    }
    cout << "  * " << endl;
}

void separarColumna() {
    cout << "  |  ";
}

bool resolverSudoku(int matriz[N][N]) {
    int fila, columna;
    // busca una casilla vacía.
    if (!estaVacio(matriz, fila, columna)) {
        // si no hay regresa verdadero
        return true;
    }

    //para los dígitos del 1 al 9
    for (int num = 1; num <= 9; num++) {
        // si no hay conflicto, rellena la casilla
        if (esSeguro(matriz, fila, columna, num)) {
            matriz[fila][columna] = num;
            // recursivamente volvemos a realizar la búsqueda
            if (resolverSudoku(matriz)) {
                //si la recursion fue exitosa
                return true;
                // si no, vacía la casilla y trata con otro número.
            } else matriz[fila][columna] = 0;
        }
    }

    //regresamos falso si todos los digitos han sido intentados y no
    //se ha logrado llenar las casillas.
    return false;
}

bool estaVacio(int matriz[N][N], int &fila, int &columna) {
    for (fila = 0; fila < N; fila++) {
        for (columna = 0; columna < N; columna++) {
            if (matriz[fila][columna] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool usadoEnFila(int matriz[N][N], int fila, int num) {
    for (int columna = 0; columna < N; columna++) {
        if (matriz[fila][columna] == num) {
            return true;
        }
    }
    return false;
}

bool usadoEnColumna(int matriz[N][N], int columna, int num) {
    for (int fila = 0; fila < N; fila++) {
        if (matriz[fila][columna] == num) {
            return true;
        }
    }
    return false;
}

bool usadoEnSubMatriz(int subMatriz[N][N], int filaInicio, int columnaInicio, int num) {
    for (int fila = 0; fila < 3; fila++) {
        for (int columna = 0; columna < 3; columna++) {
            if (subMatriz[fila + filaInicio][columna + columnaInicio] == num) {
                return true;
            }
        }
    }
    return false;
}

bool esSeguro(int matriz[N][N], int fila, int columna, int num) {
    return !usadoEnFila(matriz, fila, num)
           && !usadoEnColumna(matriz, columna, num)
           && !usadoEnSubMatriz(matriz, fila - (fila % 3), columna - (columna % 3), num);
}
