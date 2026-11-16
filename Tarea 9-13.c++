#include <iostream>
using namespace std;

// 09. Encontrar el mayor (N > 0, sin variables globales)
int findMax(int v[], int n) {
    if (n == 1) return v[0];
    int maxRest = findMax(v, n - 1);
    return (v[n - 1] > maxRest) ? v[n - 1] : maxRest;
}

// 10. Encontrar el menor y su posición (primera aparición)
void findMinAndPos(int v[], int n, int i, int &minVal, int &minIdx) {
    if (i == n) return;
    if (i == 0 || v[i] < minVal) {
        minVal = v[i];
        minIdx = i;
    }
    findMinAndPos(v, n, i + 1, minVal, minIdx);
}

// 11. Buscar un elemento (devuelve primera posición o -1)
int findElement(int v[], int n, int x, int i = 0) {
    if (i == n) return -1;
    if (v[i] == x) return i;
    return findElement(v, n, x, i + 1);
}

// 12. Contar repeticiones de X
int countOccurrences(int v[], int n, int x) {
    if (n == 0) return 0;
    int match = (v[n - 1] == x) ? 1 : 0;
    return match + countOccurrences(v, n - 1, x);
}

// 13. Reemplazar elementos (cambiar X por Y)
void replaceElement(int v[], int n, int x, int y, int i = 0) {
    if (i == n) return;
    if (v[i] == x) v[i] = y;
    replaceElement(v, n, x, y, i + 1);
}

// Función auxiliar para mostrar el vector modificado en la prueba 13
void printArray(int v[], int n, int i = 0) {
    if (i == n) return;
    cout << v[i] << " ";
    printArray(v, n, i + 1);
}

int main() {
    // Prueba 09
    int v9[] = {-8, -2, -11, -5, -3};
    cout << "09. Mayor: " << findMax(v9, 5) << "\n";

    // Prueba 10
    int v10[] = {8, 3, 6, 3, 9, 4};
    int minVal, minIdx;
    findMinAndPos(v10, 6, 0, minVal, minIdx);
    cout << "10. Menor: " << minVal << "; indice: " << minIdx << "\n";

    // Prueba 11
    int v11[] = {2, 9, 4, 9, 7, 1};
    cout << "11. Primera posicion de 9: " << findElement(v11, 6, 9) << "\n";

    // Prueba 12
    int v12[] = {3, 5, 3, 1, 3, 8, 5, 3};
    cout << "12. Apariciones de 3: " << countOccurrences(v12, 8, 3) << "\n";

    // Prueba 13
    int v13[] = {4, 2, 4, 7, 4, 1};
    replaceElement(v13, 6, 4, 0);
    cout << "13. Vector final: ";
    printArray(v13, 6);
    cout << "\n";

    return 0;
}