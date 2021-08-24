#include <iostream>
#include <string>

using namespace std;

// declaramos las funciones
void imprimir(string [], int []);
void solicitarDatos(string [], int []);
void ordenarDatos(string [], int []);

// variable global con la longitud de los arrays
int n;

int main() {

    cout << "ingrese el numero de alumnos" << endl;
    cin >> n;

    string vector1[n];
    int vector2[n];

    solicitarDatos(vector1, vector2);
    ordenarDatos(vector1,vector2);
    imprimir(vector1,vector2);

}

void solicitarDatos(string vector1[], int vector2[]){

    for (int i = 0; i < n; ++i) {
        cout << "ingrese el nombre" << endl;
        cin >> vector1[i];
        cout << "ingrese el promedio de: " << vector1[i] << endl;
        cin >> vector2[i];
    }
}

void imprimir(string vector1[], int vector2[]){


    for (int i = 0; i < n; ++i) {
        cout << vector1[i] << ", " << vector2[i] << endl;
    }

}

void ordenarDatos(string vector1[], int vector2[]){

    string temp1;
    int temp2;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if (vector2[j] < vector2[j+1]){
                temp1 = vector1[j];
                vector1[j] = vector1[j+1];
                vector1[j+1] = temp1;

                temp2 = vector2[j];
                vector2[j] = vector2[j+1];
                vector2[j+1] = temp2;
            }
        }
    }
}
