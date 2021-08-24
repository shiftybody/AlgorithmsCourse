#include <iostream>
using namespace std;

int main() {
    int fibonacci[15];
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i < 15; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    for (int i : fibonacci) {
        cout << i << endl;
    }

    return 0;
}
