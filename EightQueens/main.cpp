#include <iostream>
using namespace std;
#define N 8

void crearTablero(int[][N]);
void resolverTablero(int[][N], int);
void imprimirTablero(int[][N]);
bool esValido(int[][N], int, int);
bool reinasTranversales(int[][N], int, int);
bool reinasParalelas(int[][N], int, int);

int contadorSoluciones = 0;

int main() {

    int tablero[N][N];
    crearTablero(tablero);
    resolverTablero(tablero, 0);
    cout << "El total de soluciones posibles es: " << contadorSoluciones << endl;

}

// rellena el tablero con 0's de acuerdo a la dimensión establecida
// por el macro definido como N
void crearTablero(int tablero[][N]) {
    for (int fila = 0; fila < N; fila++) {
        for (int columna = 0; columna < N; columna++) {
            tablero[fila][columna] = 0;
        }
    }
}

//Imprime el tablero
void imprimirTablero(int tablero[][N]) {
    for (int fila = 0; fila < N; fila++) {
        for (int columna = 0; columna < N; columna++) {
            cout << tablero[fila][columna] << "  ";
        }
        cout << endl;
    }
}

// función recursiva
void resolverTablero(int tablero[][N], int columna) {


    //para cada una de las filas desde 0 hasta < N
    for (int fila = 0; fila < N; fila++) {
        //Verificamos si podemos colocar una reina en la
        // fila del contador y la columna recibida por la función.

        // Si no rompe alguna regla
        if (esValido(tablero, fila, columna)) {
            // colocamos una reina en el índice actual
            tablero[fila][columna] = 1;
            //si aún no llegamos al último indice de la columna
            // = no haber colocado las 8 reinas
            if (columna < N - 1 ) {
                //procede a colocar la siguiente reina
                //enviando el índice de la columna
                resolverTablero(tablero, columna + 1);
            } else {
                // cuenta el número de veces que se ha llegado
                // a un tablero con solución valida
                contadorSoluciones++;
                cout<< "         " << contadorSoluciones << endl ;
                //una vez colocada la última reina imprime
                // el tablero resultado
                imprimirTablero(tablero);
                cout << endl;
            }
            // si colocar una reina no conduce
            // a una solución la eliminamos
            tablero[fila][columna] = 0;
        }
        //pasamos a la siguiente fila
    }
}

// solo es necesario verificar el lado izquierdo para las filas y diagonales
bool esValido(int tablero[][N], int fila, int columna) {
    // devuelve verdadero si no existe uan reina a la izquierda en fila o diagonal
    //de donde se encuentra el índice fila, columna actual.
    return !reinasParalelas(tablero, fila, columna) && !reinasTranversales(tablero, fila, columna);

}

// leemos si en la fila que nos encontramos existe del lado izquierdo una reina
bool reinasParalelas(int tablero[][N], int filaActual, int columnaActual) {
    //comenzamos desde el índice de la columna 0 hasta la columna que nos encontramos
    for (int iColumna = 0; iColumna < columnaActual; iColumna++) {
        //si existe una reina devolvemos falso
        if (tablero[filaActual][iColumna] == 1) {
            return true;
        }
    }
    return false;
}

// leemos si en las diagonales a la izquierda del índice en el que nos encontramos existe una reina
bool reinasTranversales(int tablero[][N], int filaActual, int columnaActual) {

    // Comenzamos desde la fila, columna actual de manera decreciente. Eso significa
    //que nos acercaremos al índice 0,0 y cuando estemos allí parara el ciclo.
    for (int iFila = filaActual, iColumna = columnaActual; iFila >= 0 && iColumna >= 0; iFila--, iColumna--)
        if (tablero[iFila][iColumna] == 1) {
            return true;
        }
    //Comenzamos desde la fila, columna actual; el indiceFila subirá hasta llegar a la octava fila ( == indice 7 || <=N)
    // y el indiceColumna bajará hasta llegar al índice 0.
    for (int iFila = filaActual, iColumna = columnaActual; iFila < N && iColumna >= 0; iFila++, iColumna--) {
        if (tablero[iFila][iColumna] == 1) {
            return true;
        }
    }

    return false;
}










