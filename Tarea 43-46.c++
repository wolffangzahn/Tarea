#include <iostream>
using namespace std;

const int MAX = 50;

// 43. Verificar matriz simétrica (M[i][j] == M[j][i] en matriz cuadrada N x N)
bool isSymmetric(int m[][MAX], int n, int i = 0, int j = 1) {
    if (i >= n - 1) return true;
    if (j >= n) return isSymmetric(m, n, i + 1, i + 2);
    if (m[i][j] != m[j][i]) return false;
    return isSymmetric(m, n, i, j + 1);
}

// Auxiliar para 44: imprimir una columna desde abajo hacia arriba (fila n-1 hasta 0)
void printColBottomUp(int m[][MAX], int col, int i) {
    if (i < 0) return;
    cout << m[i][col] << " ";
    printColBottomUp(m, col, i - 1);
}

// 44. Rotar 90 grados en sentido horario (mostrar matriz rotada)
void printRotated90(int m[][MAX], int n, int j = 0) {
    if (j == n) return;
    printColBottomUp(m, j, n - 1);
    cout << "\n";
    printRotated90(m, n, j + 1);
}

// Auxiliares para 45: imprimir cada borde de un anillo en espiral
void printTopRow(int m[][MAX], int row, int col, int endCol) {
    if (col > endCol) return;
    cout << m[row][col] << " ";
    printTopRow(m, row, col + 1, endCol);
}

void printRightCol(int m[][MAX], int col, int row, int endRow) {
    if (row > endRow) return;
    cout << m[row][col] << " ";
    printRightCol(m, col, row + 1, endRow);
}

void printBottomRow(int m[][MAX], int row, int col, int startCol) {
    if (col < startCol) return;
    cout << m[row][col] << " ";
    printBottomRow(m, row, col - 1, startCol);
}

void printLeftCol(int m[][MAX], int col, int row, int startRow) {
    if (row < startRow) return;
    cout << m[row][col] << " ";
    printLeftCol(m, col, row - 1, startRow);
}

// 45. Recorrido en espiral (desde esquina superior izquierda hacia la derecha)
void printSpiral(int m[][MAX], int top, int bottom, int left, int right) {
    if (top > bottom || left > right) return;

    printTopRow(m, top, left, right);
    printRightCol(m, right, top + 1, bottom);

    if (top < bottom) {
        printBottomRow(m, bottom, right - 1, left);
    }
    if (left < right) {
        printLeftCol(m, left, bottom - 1, top + 1);
    }

    printSpiral(m, top + 1, bottom - 1, left + 1, right - 1);
}

// 46. Matriz triangular superior (elementos debajo de la diagonal principal son cero)
bool isUpperTriangular(int m[][MAX], int n, int i = 1, int j = 0) {
    if (i == n) return true;
    if (j == i) return isUpperTriangular(m, n, i + 1, 0);
    if (m[i][j] != 0) return false;
    return isUpperTriangular(m, n, i, j + 1);
}

int main() {
    // Prueba 43
    int m43[MAX][MAX] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    cout << "43. Es simetrica?: " << (isSymmetric(m43, 3) ? "Si" : "No") << "\n";

    // Prueba 44
    int m44[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "\n44. Rotada 90 grados:\n";
    printRotated90(m44, 3);

    // Prueba 45
    int m45[MAX][MAX] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    cout << "\n45. Recorrido en espiral:\n";
    printSpiral(m45, 0, 3, 0, 3);
    cout << "\n";

    // Prueba 46
    int m46[MAX][MAX] = {
        {2, 3, 4},
        {0, 5, 6},
        {0, 0, 7}
    };
    cout << "\n46. Triangular superior?: " << (isUpperTriangular(m46, 3) ? "Si" : "No") << "\n";

    return 0;
}
