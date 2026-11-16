#include <iostream>
using namespace std;

// 01. Cargar un vector
void loadArray(int v[], int n, int i = 0) {
    if (i == n) return;
    cin >> v[i];
    loadArray(v, n, i + 1);
}

// 02. Mostrar un vector
void printArray(int v[], int n, int i = 0) {
    if (i == n) return;
    cout << v[i] << " ";
    printArray(v, n, i + 1);
}

// 03. Mostrar en orden inverso
void printReverse(int v[], int n) {
    if (n == 0) return;
    cout << v[n - 1] << " ";
    printReverse(v, n - 1);
}

// 04. Sumar elementos
int sumArray(int v[], int n) {
    if (n == 0) return 0;
    return v[n - 1] + sumArray(v, n - 1);
}

int main() {
    int n = 5;
    int v[100];

    cout << "Ingrese " << n << " numeros: ";
    loadArray(v, n);

    cout << "Vector cargado: ";
    printArray(v, n);
    cout << "\n";

    cout << "Orden inverso: ";
    printReverse(v, n);
    cout << "\n";

    cout << "Suma total: " << sumArray(v, n) << "\n";

    return 0;
}