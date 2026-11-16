#include <iostream>
using namespace std;

const int MAX = 50; // Tamaño máximo para declarar matrices estáticas en parámetros

// 26. Cargar una matriz (F x C) mediante llamadas recursivas
void loadMatrix(int m[][MAX], int f, int c, int i = 0, int j = 0) {
    if (i == f) return;
    if (j == c) {
        loadMatrix(m, f, c, i + 1, 0);
        return;
    }
    cin >> m[i][j];
    loadMatrix(m, f, c, i, j + 1);
}

// 27. Mostrar una matriz respetando filas y columnas
void printMatrix(int m[][MAX], int f, int c, int i = 0, int j = 0) {
    if (i == f) return;
    if (j == c) {
        cout << "\n";
        printMatrix(m, f, c, i + 1, 0);
        return;
    }
    cout << m[i][j] << " ";
    printMatrix(m, f, c, i, j + 1);
}

// 28. Sumar todos los elementos de una matriz
int sumMatrix(int m[][MAX], int f, int c, int i = 0, int j = 0) {
    if (i == f) return 0;
    if (j == c) return sumMatrix(m, f, c, i + 1, 0);
    return m[i][j] + sumMatrix(m, f, c, i, j + 1);
}

// 29. Contar pares e impares de la matriz
void countEvenOddMatrix(int m[][MAX], int f, int c, int &evens, int &odds, int i = 0, int j = 0) {
    if (i == f) return;
    if (j == c) {
        countEvenOddMatrix(m, f, c, evens, odds, i + 1, 0);
        return;
    }
    if (m[i][j] % 2 == 0) evens++;
    else odds++;
    countEvenOddMatrix(m, f, c, evens, odds, i, j + 1);
}

int main() {
    // Prueba 26 y 27 (usando los datos del ejemplo para probar directo)
    int m26[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    // Si quieres probar la carga manual por teclado, descomenta estas 2 líneas:
    // cout << "Ingrese 6 valores para matriz 2x3: ";
    // loadMatrix(m26, 2, 3);

    cout << "27. Matriz mostrada:\n";
    printMatrix(m26, 2, 3);

    // Prueba 28
    cout << "28. Suma total: " << sumMatrix(m26, 2, 3) << "\n";

    // Prueba 29
    int m29[MAX][MAX] = {
        {2, 3, 4},
        {5, 6, 7}
    };
    int evens = 0, odds = 0;
    countEvenOddMatrix(m29, 2, 3, evens, odds);
    cout << "29. Pares: " << evens << "; impares: " << odds << "\n";

    return 0;
}
