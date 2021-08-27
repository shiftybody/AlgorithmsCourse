#include <iostream>
using namespace std;
int fibonacci (int);

int main() {
    cout << fibonacci(15) << " " ;
}

int arrayFibonacci[15];

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


