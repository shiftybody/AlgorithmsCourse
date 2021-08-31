#include <iostream>
using namespace std;

void hanoi(int, char, char, char);

int main() {
    int n;
    cin >> n;
    // nótese el orden de los parámetros
    hanoi(n, 'A', 'C', 'B');
}

void hanoi(int n, char origen, char destino, char auxiliar) {

         // condición base que terminara con la función recursiva
         // y que indica que se ha llegado al último disco.
    if (n == 1) {
        cout << "Mueve el disco " << n << " de " << origen << " a " << destino << endl;
    } else {
        // si tenemos más de un disco, primero movemos n -1 discos
        // de la torre origen a la torre auxiliar.
        hanoi(n - 1, origen, auxiliar, destino);
        // se imprime el movimiento del disco que queda en la torre origen a la torre destino
        cout << "Mueve el disco " << n << " de " << origen << " a " << destino << endl;
        // y se realiza el movimiento de los n-1 discos de la torre auxiliar a la torre destino
        hanoi(n - 1, auxiliar, destino, origen);
        // quedando plasmados los tres pasos del planteamiento recursivo.
    }
}

