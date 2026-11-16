#include <iostream>
using namespace std;

const int MAX = 50;

// 39. Mostrar el borde en orden por filas (sin incluir los internos)
void printBorderByRows(int m[][MAX], int f, int c, int i = 0, int j = 0) {
    if (i == f) return;
    if (j == c) {
        printBorderByRows(m, f, c, i + 1, 0);
        return;
    }
    if (i == 0 || i == f - 1 || j == 0 || j == c - 1) {
        cout << m[i][j] << " ";
    }
    printBorderByRows(m, f, c, i, j + 1);
}

// 40. Sumar el borde (contando las esquinas una sola vez)
int sumBorder(int m[][MAX], int f, int c, int i = 0, int j = 0) {
    if (i == f) return 0;
    if (j == c) return sumBorder(m, f, c, i + 1, 0);
    int val = (i == 0 || i == f - 1 || j == 0 || j == c - 1) ? m[i][j] : 0;
    return val + sumBorder(m, f, c, i, j + 1);
}

// 41. Mostrar la transpuesta sin crear otra matriz (C x F)
void printTranspose(int m[][MAX], int f, int c, int j = 0, int i = 0) {
    if (j == c) return;
    if (i == f) {
        cout << "\n";
        printTranspose(m, f, c, j + 1, 0);
        return;
    }
    cout << m[i][j] << " ";
    printTranspose(m, f, c, j, i + 1);
}

// Auxiliar para 42: obtener el máximo de una fila específica
int maxInRow(int m[][MAX], int row, int c, int j = 0) {
    if (j == c - 1) return m[row][j];
    int maxRest = maxInRow(m, row, c, j + 1);
    return (m[row][j] > maxRest) ? m[row][j] : maxRest;
}

// 42. Mayor de cada fila recursivamente
void printMaxPerRow(int m[][MAX], int f, int c, int i = 0) {
    if (i == f) return;
    cout << "Fila " << i << ": " << maxInRow(m, i, c) << "\n";
    printMaxPerRow(m, f, c, i + 1);
}

int main() {
    // Prueba 39
    int m39[MAX][MAX] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    cout << "39. Borde por filas: ";
    printBorderByRows(m39, 3, 4);
    cout << "\n";

    // Prueba 40
    int m40[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "40. Suma del borde: " << sumBorder(m40, 3, 3) << "\n";

    // Prueba 41
    int m41[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "41. Transpuesta (3x2):\n";
    printTranspose(m41, 2, 3);

    // Prueba 42
    int m42[MAX][MAX] = {
        {2, 9, 4},
        {8, 1, 5},
        {3, 7, 6}
    };
    cout << "42. Mayor de cada fila:\n";
    printMaxPerRow(m42, 3, 3);

    return 0;
}
