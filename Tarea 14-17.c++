#include <iostream>
using namespace std;

// 14. Invertir el vector (en el mismo espacio)
void reverseArray(int v[], int start, int end) {
    if (start >= end) return;
    int temp = v[start];
    v[start] = v[end];
    v[end] = temp;
    reverseArray(v, start + 1, end - 1);
}

// 15. Verificar orden ascendente (permite empates)
bool isSortedAscending(int v[], int n, int i = 0) {
    if (i >= n - 1) return true;
    if (v[i] > v[i + 1]) return false;
    return isSortedAscending(v, n, i + 1);
}

// 16. Sumar posiciones pares e impares (índices desde 0)
void sumEvenOddIndices(int v[], int n, int &evenSum, int &oddSum, int i = 0) {
    if (i == n) return;
    if (i % 2 == 0) evenSum += v[i];
    else oddSum += v[i];
    sumEvenOddIndices(v, n, evenSum, oddSum, i + 1);
}

// 17. Eliminar un elemento por posición (desplaza a la izquierda y reduce N)
void removeAt(int v[], int &n, int p) {
    if (p < 0 || p >= n) return;
    if (p == n - 1) {
        n--;
        return;
    }
    v[p] = v[p + 1];
    removeAt(v, n, p + 1);
}

// Función auxiliar para mostrar el vector
void printArray(int v[], int n, int i = 0) {
    if (i == n) return;
    cout << v[i] << " ";
    printArray(v, n, i + 1);
}

int main() {
    // Prueba 14
    int v14[] = {1, 2, 3, 4, 5};
    reverseArray(v14, 0, 4);
    cout << "14. Vector invertido: ";
    printArray(v14, 5);
    cout << "\n";

    // Prueba 15
    int v15[] = {1, 2, 2, 5, 8, 8};
    cout << "15. Esta ordenado?: " << (isSortedAscending(v15, 6) ? "Si" : "No") << "\n";

    // Prueba 16
    int v16[] = {10, 3, 20, 4, 30, 5};
    int evenSum = 0, oddSum = 0;
    sumEvenOddIndices(v16, 6, evenSum, oddSum);
    cout << "16. Suma indices pares: " << evenSum << "; suma indices impares: " << oddSum << "\n";

    // Prueba 17
    int v17[] = {7, 2, 9, 4, 6};
    int n17 = 5;
    removeAt(v17, n17, 2);
    cout << "17. N nuevo: " << n17 << "; vector logico: ";
    printArray(v17, n17);
    cout << "\n";

    return 0;
}