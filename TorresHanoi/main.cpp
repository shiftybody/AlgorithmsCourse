#include <iostream>
using namespace std;

void hanoi(int, char, char, char);

int main() {
    int n;
    cin >> n;
    hanoi(n, 'A', 'C', 'B');
}

void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        cout << "Mueve el disco " << n << " de " << origen << " a " << destino << endl;
    } else {
        hanoi(n - 1, origen, auxiliar, destino);
        cout << "Mueve el disco " << n << " de " << origen << " a " << destino << endl;
        hanoi(n - 1, auxiliar, destino, origen);
    }
}

