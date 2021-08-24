#include <iostream>

using namespace std;

int fibonacci(int);
int arrayFibonacci[15];

int main() {

    cout << "Algoritmo que calcula el n-esimo termino de la sucesion" << endl;
    cout << "de fibonacci, dado un numero ingresado por el usuario\n" << endl;

    int n = 0;
    int opc = 0;

    do {
        cout << "\n Ingrese un numero: " << endl;
        cin >> n;

        cout << "El numero de la serie en la posicion " << n << " es: " << fibonacci(n) << endl;
        cout << "Para salir presione 0 o cualquier otro numero para continuar";
        cin >> opc;

    } while (opc != 0);

    return 0;

}

int fibonacci(int n) {

    if (n == 1) {
        return 0;
    } else {
        if (n == 2) {
            return 1;
        }
    }

    if (arrayFibonacci[n] == 0) {
        arrayFibonacci[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }

    return arrayFibonacci[n];
}
