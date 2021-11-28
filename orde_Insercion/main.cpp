#include<iostream>
using namespace std;

/*PASOS
 * 1. TRABAJAMOS DE IZQUIERDA A DERECHA
 * 2. COMPARAMOS CADA ELEMENTO CON TODOS LOS ELEMENTOS A LA IZQUIERDA
 * 3. SE INSERTA EL ELEMENTO EN LA POSICIÓN CORRECTA QUE CUMPLA CON LA CONDICIÓN ESTABLECIDA*/

void orde_Insercion(int l[]) {

    cout << "Algoritmo por ordenamiento de insercion" << endl;

    for (int pivote = 1; pivote < 5; pivote++) {
        int posActual = pivote;
        for (int numIzq = pivote; numIzq >= 0; numIzq--) {
            if (l[numIzq] > l[posActual]) {
                swap(l[numIzq], l[posActual]);
                posActual = numIzq;
            }
        }
    }
}

void imprimir(int l[]) {
    for (int i = 0; i < 5; i++) {
        cout << l[i] << " ";
    }
    cout << endl;
}

int main() {
    int lista[] = {5, 3, 4, 2, 1};
    imprimir(lista);
    orde_Insercion(lista);
    imprimir(lista);
    return 0;
}


