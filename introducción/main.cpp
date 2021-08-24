//directiva instruccion que nos permiten cargar las librerias que
//utilizaremos en nuestros programas

#include <iostream>
using namespace std;
void pedirDatos(int [5]);
int determinarMayor(int [5]);
void calcularDiferencia(int [5]);

// el espacio de nombres estandar
//es el lugar en donde nuestro pograma va a
// saber que existen todas las variables que van a
// estar disponibles en nuestro programa

//codigo fuente en .cpp
//archivo compilado es codigo objeto  por eso la extension .o

int main(){
    //declarar arreglo
    // tipo nombre del vector tamaño

    int numeros[5];
    pedirDatos(numeros);
    calcularDiferencia(numeros);
    return 0;
}

//lectura de datos
// mandamos como parametro
void pedirDatos(int numeros[5]){
    cout<< "Ingresa 5 elementos numericos"<< endl;
    for (int i = 0; i < 5; ++i) {
        cin>>numeros[i];
    }
}

int determinarMayor( int numeros[5]){

    //posicion logica
    int mayor = numeros[0];
    for (int i = 0; i < 5; ++i) {
        if (mayor < numeros[i]){
            mayor = numeros[i];
        }
    }

    return mayor;
}

void calcularDiferencia(int numeros[5]){
    int may =determinarMayor(numeros);
    int dif = 0;

    for (int i = 0; i < 5; ++i) {
        dif = may - numeros[i];
        cout<< "la diferencia que separa a " << i+1 << " elemento es: "<< dif <<endl;
    }
}
