#include <iostream>
using namespace std;

void imprimir(int []);
void pedirDatos(int []);
void ordenarDatos(int []);
int n;

int main() {

    cout << "Ingrese el numero de elementos" << endl;
    cin >> n;
    int vector[n];
    pedirDatos(vector);
    ordenarDatos(vector);
    imprimir(vector);
    return 0;
}

void imprimir(int vector[]){

    for (int i = 1; i <= n; ++i) {
        cout << vector[i] << endl;
    }
}

void pedirDatos(int vector[]){

    cout << "Introduzca los elementos" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> vector[i];
    }
}

void ordenarDatos(int vector[]){

    int j = n;
    for (int i = 0; i < n/2; ++i) {
        int temp = vector[i];
        vector[i] = vector[j];
        vector[j] = temp;
        j = j-1;
    }
}

