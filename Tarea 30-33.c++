#include <iostream>
using namespace std;

const int MAX = 50;

// 30. Encontrar el mayor valor de una matriz no vacía (F > 0, C > 0)
int findMaxMatrix(int m[][MAX], int f, int c, int i = 0, int j = 0) {
    if (i == f - 1 && j == c - 1) return m[i][j];
    if (j == c) return findMaxMatrix(m, f, c, i + 1, 0);
    int maxRest = findMaxMatrix(m, f, c, i, j + 1);
    return (m[i][j] > maxRest) ? m[i][j] : maxRest;
}

// 31. Encontrar el menor e indicar primera fila y columna donde aparece
void findMinAndCoords(int m[][MAX], int f, int c, int &minVal, int &minRow, int &minCol, int i = 0, int j = 0) {
    if (i == f) return;
    if (j == c) {
        findMinAndCoords(m, f, c, minVal, minRow, minCol, i + 1, 0);
        return;
    }
    if ((i == 0 && j == 0) || m[i][j] < minVal) {
        minVal = m[i][j];
        minRow = i;
        minCol = j;
    }
    findMinAndCoords(m, f, c, minVal, minRow, minCol, i, j + 1);
}

// 32. Contar positivos, negativos y ceros en una matriz
void countSignsMatrix(int m[][MAX], int f, int c, int &pos, int &neg, int &zeros, int i = 0, int j = 0) {
    if (i == f) return;
    if (j == c) {
        countSignsMatrix(m, f, c, pos, neg, zeros, i + 1, 0);
        return;
    }
    if (m[i][j] > 0) pos++;
    else if (m[i][j] < 0) neg++;
    else zeros++;
    countSignsMatrix(m, f, c, pos, neg, zeros, i, j + 1);
}

// 33. Buscar un elemento (coordenadas de primera aparición en recorrido por filas)
bool searchMatrix(int m[][MAX], int f, int c, int x, int &foundRow, int &foundCol, int i = 0, int j = 0) {
    if (i == f) return false;
    if (j == c) return searchMatrix(m, f, c, x, foundRow, foundCol, i + 1, 0);
    if (m[i][j] == x) {
        foundRow = i;
        foundCol = j;
        return true;
    }
    return searchMatrix(m, f, c, x, foundRow, foundCol, i, j + 1);
}

int main() {
    // Prueba 30
    int m30[MAX][MAX] = {
        {-5, -1, -9},
        {-3, -7, -2}
    };
    cout << "30. Mayor: " << findMaxMatrix(m30, 2, 3) << "\n";

    // Prueba 31
    int m31[MAX][MAX] = {
        {5, 2, 8},
        {1, 7, 6},
        {1, 4, 9}
    };
    int minVal, minRow, minCol;
    findMinAndCoords(m31, 3, 3, minVal, minRow, minCol);
    cout << "31. Menor: " << minVal << "; fila: " << minRow << "; columna: " << minCol << "\n";

    // Prueba 32
    int m32[MAX][MAX] = {
        {-1, 0, 2, 5},
        {0, -3, 4, -2}
    };
    int pos = 0, neg = 0, zeros = 0;
    countSignsMatrix(m32, 2, 4, pos, neg, zeros);
    cout << "32. Positivos: " << pos << "; negativos: " << neg << "; ceros: " << zeros << "\n";

    // Prueba 33
    int m33[MAX][MAX] = {
        {4, 8, 2},
        {7, 8, 5}
    };
    int r, col;
    if (searchMatrix(m33, 2, 3, 8, r, col)) {
        cout << "33. Encontrado en fila " << r << ", columna " << col << "\n";
    } else {
        cout << "33. No encontrado\n";
    }

    return 0;
}
