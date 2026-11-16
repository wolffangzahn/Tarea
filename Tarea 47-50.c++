#include <iostream>
using namespace std;

const int MAX = 50;

// 47. Sumar regiones triangulares (i <= j e i >= j; diagonal incluida en ambas)
void sumTriangularRegions(int m[][MAX], int n, int &upperSum, int &lowerSum, int i = 0, int j = 0) {
    if (i == n) return;
    if (j == n) {
        sumTriangularRegions(m, n, upperSum, lowerSum, i + 1, 0);
        return;
    }
    if (i <= j) upperSum += m[i][j];
    if (i >= j) lowerSum += m[i][j];
    sumTriangularRegions(m, n, upperSum, lowerSum, i, j + 1);
}

// Auxiliares para 48: mínimo en una fila y máximo en una columna
int getMinInRow(int m[][MAX], int row, int c, int j = 0) {
    if (j == c - 1) return m[row][j];
    int minRest = getMinInRow(m, row, c, j + 1);
    return (m[row][j] < minRest) ? m[row][j] : minRest;
}

int getMaxInCol(int m[][MAX], int f, int col, int i = 0) {
    if (i == f - 1) return m[i][col];
    int maxRest = getMaxInCol(m, f, col, i + 1);
    return (m[i][col] > maxRest) ? m[i][col] : maxRest;
}

// 48. Encontrar punto de silla (mínimo de su fila y máximo de su columna)
bool findSaddlePoint(int m[][MAX], int f, int c, int &val, int &sRow, int &sCol, int i = 0, int j = 0) {
    if (i == f) return false;
    if (j == c) return findSaddlePoint(m, f, c, val, sRow, sCol, i + 1, 0);
    
    int rowMin = getMinInRow(m, i, c);
    int colMax = getMaxInCol(m, f, j);
    if (m[i][j] == rowMin && m[i][j] == colMax) {
        val = m[i][j];
        sRow = i;
        sCol = j;
        return true;
    }
    return findSaddlePoint(m, f, c, val, sRow, sCol, i, j + 1);
}

// Auxiliar para 49: contar cuántos elementos iguales hay en dirección (dr, dc)
int countInDir(int m[][MAX], int f, int c, int i, int j, int dr, int dc, int target) {
    if (i < 0 || i >= f || j < 0 || j >= c || m[i][j] != target) return 0;
    return 1 + countInDir(m, f, c, i + dr, j + dc, dr, dc, target);
}

// 49. Buscar secuencias consecutivas de K elementos iguales (horizontal, vertical o diagonal)
bool hasConsecutiveK(int m[][MAX], int f, int c, int k, int &foundVal, int i = 0, int j = 0) {
    if (i == f) return false;
    if (j == c) return hasConsecutiveK(m, f, c, k, foundVal, i + 1, 0);

    int val = m[i][j];
    // Revisar derecha (0,1), abajo (1,0), diagonal principal (1,1) y diagonal secundaria (1,-1)
    if (countInDir(m, f, c, i, j, 0, 1, val) >= k ||
        countInDir(m, f, c, i, j, 1, 0, val) >= k ||
        countInDir(m, f, c, i, j, 1, 1, val) >= k ||
        countInDir(m, f, c, i, j, 1, -1, val) >= k) {
        foundVal = val;
        return true;
    }
    return hasConsecutiveK(m, f, c, k, foundVal, i, j + 1);
}

// 50. Camino de suma máxima desde (0,0) hasta (F-1, C-1) moviéndose solo derecha o abajo
int maxPathSum(int m[][MAX], int f, int c, int i = 0, int j = 0) {
    if (i == f - 1 && j == c - 1) return m[i][j];
    if (i == f - 1) return m[i][j] + maxPathSum(m, f, c, i, j + 1);
    if (j == c - 1) return m[i][j] + maxPathSum(m, f, c, i + 1, j);

    int rightSum = maxPathSum(m, f, c, i, j + 1);
    int downSum = maxPathSum(m, f, c, i + 1, j);
    return m[i][j] + ((rightSum > downSum) ? rightSum : downSum);
}

// Auxiliar para 50: reconstruir e imprimir el camino óptimo elegido
void printMaxPath(int m[][MAX], int f, int c, int i = 0, int j = 0) {
    cout << m[i][j];
    if (i == f - 1 && j == c - 1) return;
    cout << " -> ";

    if (i == f - 1) {
        printMaxPath(m, f, c, i, j + 1);
    } else if (j == c - 1) {
        printMaxPath(m, f, c, i + 1, j);
    } else {
        int rightSum = maxPathSum(m, f, c, i, j + 1);
        int downSum = maxPathSum(m, f, c, i + 1, j);
        if (rightSum >= downSum) printMaxPath(m, f, c, i, j + 1);
        else printMaxPath(m, f, c, i + 1, j);
    }
}

int main() {
    // Prueba 47
    int m47[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int upperSum = 0, lowerSum = 0;
    sumTriangularRegions(m47, 3, upperSum, lowerSum);
    cout << "47. Triangulo superior: " << upperSum << "; triangulo inferior: " << lowerSum << "\n";

    // Prueba 48
    int m48[MAX][MAX] = {
        {3, 1},
        {4, 2}
    };
    int sVal, sRow, sCol;
    if (findSaddlePoint(m48, 2, 2, sVal, sRow, sCol)) {
        cout << "48. Punto de silla: valor " << sVal << "; fila " << sRow << "; columna " << sCol << "\n";
    } else {
        cout << "48. No existe punto de silla\n";
    }

    // Prueba 49
    int m49[MAX][MAX] = {
        {5, 1, 2},
        {4, 5, 3},
        {7, 8, 5}
    };
    int foundVal;
    if (hasConsecutiveK(m49, 3, 3, 3, foundVal)) {
        cout << "49. Si existe secuencia consecutiva con valor: " << foundVal << "\n";
    } else {
        cout << "49. No existe secuencia\n";
    }

    // Prueba 50
    int m50[MAX][MAX] = {
        {5, 1, 2},
        {4, 8, 3},
        {1, 9, 6}
    };
    cout << "50. Suma maxima: " << maxPathSum(m50, 3, 3) << "; camino: ";
    printMaxPath(m50, 3, 3);
    cout << "\n";

    return 0;
}
