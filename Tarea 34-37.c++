#include <iostream>
using namespace std;

const int MAX = 50;

// Auxiliar para 34: sumar los elementos de una fila específica
int sumRow(int m[][MAX], int row, int c, int j = 0) {
    if (j == c) return 0;
    return m[row][j] + sumRow(m, row, c, j + 1);
}

// 34. Sumar cada fila (muestra suma independiente para cada fila)
void printRowSums(int m[][MAX], int f, int c, int i = 0) {
    if (i == f) return;
    cout << "Fila " << i << ": " << sumRow(m, i, c) << "\n";
    printRowSums(m, f, c, i + 1);
}

// Auxiliar para 35: sumar los elementos de una columna específica
int sumCol(int m[][MAX], int f, int col, int i = 0) {
    if (i == f) return 0;
    return m[i][col] + sumCol(m, f, col, i + 1);
}

// 35. Sumar cada columna (muestra suma independiente para cada columna)
void printColSums(int m[][MAX], int f, int c, int j = 0) {
    if (j == c) return;
    cout << "Columna " << j << ": " << sumCol(m, f, j) << "\n";
    printColSums(m, f, c, j + 1);
}

// 36. Diagonal principal (matriz cuadrada N x N)
int sumMainDiagonal(int m[][MAX], int n, int i = 0) {
    if (i == n) return 0;
    return m[i][i] + sumMainDiagonal(m, n, i + 1);
}

// 37. Diagonal secundaria (elementos M[i][N - 1 - i])
int sumSecondaryDiagonal(int m[][MAX], int n, int i = 0) {
    if (i == n) return 0;
    return m[i][n - 1 - i] + sumSecondaryDiagonal(m, n, i + 1);
}

// 38. Sumar estrictamente encima y debajo de la diagonal principal
void sumAboveBelowDiagonal(int m[][MAX], int n, int &above, int &below, int i = 0, int j = 0) {
    if (i == n) return;
    if (j == n) {
        sumAboveBelowDiagonal(m, n, above, below, i + 1, 0);
        return;
    }
    if (j > i) above += m[i][j];
    else if (i > j) below += m[i][j];
    sumAboveBelowDiagonal(m, n, above, below, i, j + 1);
}

int main() {
    // Prueba 34
    int m34[MAX][MAX] = {
        {2, 4, 6},
        {1, 3, 5},
        {7, 8, 9}
    };
    cout << "34. Suma por filas:\n";
    printRowSums(m34, 3, 3);

    // Prueba 35
    int m35[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "\n35. Suma por columnas:\n";
    printColSums(m35, 2, 3);

    // Prueba 36
    int m36[MAX][MAX] = {
        {3, 5, 7},
        {2, 8, 4},
        {1, 6, 9}
    };
    cout << "\n36. Suma diagonal principal: " << sumMainDiagonal(m36, 3) << "\n";

    // Prueba 37 y 38
    int m37[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "37. Suma diagonal secundaria: " << sumSecondaryDiagonal(m37, 3) << "\n";

    int above = 0, below = 0;
    sumAboveBelowDiagonal(m37, 3, above, below);
    cout << "38. Encima: " << above << "; debajo: " << below << "\n";

    return 0;
}
