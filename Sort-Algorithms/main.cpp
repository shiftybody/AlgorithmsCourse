#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int pos = i;
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[pos]) {
                pos = j;
                swap(arr[i], arr[pos]);
            }
        }
    }
}

void quickSort(int arr[], int izq, int der) {
    int i = izq, j = der, tmp;
    int p = arr[(izq + der) / 2];

    while (i <= j) {
        while (arr[i] < p) i++;
        while (arr[j] > p) j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (izq < j)
        quickSort(arr, izq, j);
    if (i < der)
        quickSort(arr, i, der);
}

void merge(int *arr, int p, int q, int r) {
    int i, j, k, pr, nr;
    pr = q - p + 1;
    nr = r - q;
    int larr[pr], rarr[nr];

    for (i = 0; i < pr; i++)
        larr[i] = arr[p + i];
    for (j = 0; j < nr; j++)
        rarr[j] = arr[q + 1 + j];
    i = 0;
    j = 0;
    k = p;

    while (i < pr && j < nr) {
        if (larr[i] <= rarr[j]) {
            arr[k] = larr[i];
            i++;
        } else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < pr) {
        arr[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr) {
        arr[k] = rarr[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int p, int r) {
    int q;
    if (p < r) {
        q = p + (r - p) / 2;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

void CountingSort(int arr[], int n) {
    int i, j, k;
    int idx = 0;
    int min, max;

    min = max = arr[0];
    for (i = 1; i < n; i++) {
        min = (arr[i] < min) ? arr[i] : min;
        max = (arr[i] > max) ? arr[i] : max;
    }

    k = max - min + 1;

    int *B = new int[k];
    for (i = 0; i < k; i++) B[i] = 0;

    for (i = 0; i < n; i++) B[arr[i] - min]++;
    for (i = min; i <= max; i++)
        for (j = 0; j < B[i - min]; j++) arr[idx++] = i;

    delete[] B;
}

void insertionSort(int array[], int size) {
    for (int pivote = 1; pivote < size; pivote++) {
        int posActual = pivote;
        for (int numIzq = pivote; numIzq >= 0; numIzq--) {
            if (array[numIzq] > array[posActual]) {
                swap(array[numIzq], array[posActual]);
                posActual = numIzq;
            }
        }
    }
}


void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    quickSort(arr, 0, 6);
    printArray(arr, n);
    mergeSort(arr, 0, 6);
    printArray(arr, n);
    CountingSort(arr, n);
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}



