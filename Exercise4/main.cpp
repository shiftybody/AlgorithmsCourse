
#include <iostream>
#define filas 2
#define columnas 2

using namespace std;

// Predefinición de funciones
void SoliciteArray(int [][columnas]);
void VisualArray(int [][columnas]);
void Sum(int [][columnas], int [][columnas]);
void Res(int [][columnas], int [][columnas]);
void Mult(int [][columnas], int [][columnas]);

int main() {

    char opcion;
    bool repetir = true;

    do {

        cout << "\n\nMenu de Opciones" << endl;
        cout << "" << endl;
        cout << "A. Enter Matrix A" << endl;
        cout << "B. Enter Matrix B" << endl;
        cout << "C. Display A + B" << endl;
        cout << "D. Display A - B" << endl;
        cout << "E. Display A * B" << endl;
        cout << "F. Exit" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 'A':

                int MatrizA[filas][columnas];

                cout << "Solicitando datos para la primera matriz";
                SoliciteArray(MatrizA);
                VisualArray(MatrizA);
                break;

            case 'B':

                int MatrizB[filas][columnas];

                cout << "Solicitando datos para la segunda matriz";
                SoliciteArray(MatrizB);
                VisualArray(MatrizB);

                break;

            case 'C':

                cout << "\nLa suma de las matrices es la siguiente:\n";
                Sum(MatrizA, MatrizB);
                break;

            case 'D':

                cout << "\nLa resta de las matrices es la siguiente:\n";
                Res(MatrizA, MatrizB);
                break;
            case 'E':

                cout <<"\nLa multiplicacion de las matrices es la siguiente:\n";
                Mult(MatrizA, MatrizB);
                break;
                break;

            case 'F':
                repetir = false;
                break;
        }
    } while (repetir);

    return 0;
}

// Funcion para solicitar los datos del array
void SoliciteArray(int Matriz[][columnas]) {

    cout << "\n";
    for (int fila = 0; fila < filas; fila++) {
        for (int columna = 0; columna < columnas; columna++) {
            cout << "Posicion " << fila << " - " << columna << " : ";
            cin >> Matriz[fila][columna];
        }
    }
    cout << "\n";
}

// Funcion para visualizar los datos de la matriz
void VisualArray(int Matriz[][columnas]) {

    cout << "\n";
    for (int fila = 0; fila < filas; fila++) {
        for (int columna = 0; columna < columnas; columna++) {
            cout << Matriz[fila][columna] << "  ";
        }
        cout << "\n";
    }
}

// Funcion para sumar matrices
void Sum(int Matriz1[][columnas], int Matriz2[][columnas]) {

    int resultado[filas][columnas];
    for (int fila = 0; fila < filas; fila++) {
        for (int columna = 0; columna < columnas; columna++) {
            resultado[fila][columna] =
                    Matriz1[fila][columna] + Matriz2[fila][columna];
        }
    }

    VisualArray(resultado);
}

// Funcion para restar matrices
void Res(int Matriz1[][columnas], int Matriz2[][columnas]) {

    int resultado[filas][columnas];
    for (int fila = 0; fila < filas; fila++) {
        for (int columna = 0; columna < columnas; columna++) {
            resultado[fila][columna] =
                    Matriz1[fila][columna] - Matriz2[fila][columna];
        }
    }
    VisualArray(resultado);
}

void Mult(int Matriz1[][columnas], int Matriz2[][columnas]) {

    int resultado[filas][columnas];
    for (int fila = 0; fila < filas; fila++) {
        for (int columna = 0; columna < columnas; columna++) {
            resultado[fila][columna] = 0;
            for (int k = 0; k < filas; k++) {
                resultado[fila][columna] += Matriz1[fila][k] * Matriz2[k][columna];
            }
        }
    }
    VisualArray(resultado);
}