#include <iostream>
using namespace std;

// Auxiliar para 18: encontrar índice del mínimo desde start hasta n-1
int findMinIndex(int v[], int n, int start) {
    if (start == n - 1) return start;
    int minRest = findMinIndex(v, n, start + 1);
    return (v[start] < v[minRest]) ? start : minRest;
}

// 18. Ordenamiento por selección recursivo
void selectionSortRec(int v[], int n, int i = 0) {
    if (i >= n - 1) return;
    int minIdx = findMinIndex(v, n, i);
    if (minIdx != i) {
        int temp = v[i];
        v[i] = v[minIdx];
        v[minIdx] = temp;
    }
    selectionSortRec(v, n, i + 1);
}

// 19. Búsqueda binaria recursiva
int binarySearchRec(int v[], int low, int high, int x) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (v[mid] == x) return mid;
    if (v[mid] > x) return binarySearchRec(v, low, mid - 1, x);
    return binarySearchRec(v, mid + 1, high, x);
}

// Auxiliares para 20: verificar existencia previa y eliminar por posición
bool existsBefore(int v[], int limit, int val, int i = 0) {
    if (i == limit) return false;
    if (v[i] == val) return true;
    return existsBefore(v, limit, val, i + 1);
}

void shiftLeft(int v[], int &n, int p) {
    if (p == n - 1) {
        n--;
        return;
    }
    v[p] = v[p + 1];
    shiftLeft(v, n, p + 1);
}

// 20. Eliminar elementos duplicados (conservando primera aparición y orden)
void removeDuplicates(int v[], int &n, int i = 0) {
    if (i >= n) return;
    if (existsBefore(v, i, v[i])) {
        shiftLeft(v, n, i);
        removeDuplicates(v, n, i); // Revisar el mismo índice tras desplazar
    } else {
        removeDuplicates(v, n, i + 1);
    }
}

// Auxiliares para 21: buscar el último par desde el final
int findLastEven(int v[], int idx) {
    if (idx < 0) return -1;
    if (v[idx] % 2 == 0) return idx;
    return findLastEven(v, idx - 1);
}

// 21. Separar pares e impares (pares primero, impares después con intercambios)
void separateEvenOdd(int v[], int n, int i = 0) {
    if (i >= n - 1) return;
    if (v[i] % 2 != 0) {
        int evenIdx = findLastEven(v, n - 1);
        if (evenIdx > i) {
            int temp = v[i];
            v[i] = v[evenIdx];
            v[evenIdx] = temp;
        } else {
            return; // Ya no quedan pares a la derecha
        }
    }
    separateEvenOdd(v, n, i + 1);
}

// Auxiliar para imprimir
void printArray(int v[], int n, int i = 0) {
    if (i == n) return;
    cout << v[i] << " ";
    printArray(v, n, i + 1);
}

int main() {
    // Prueba 18
    int v18[] = {8, 1, 6, 3, 2, 5};
    selectionSortRec(v18, 6);
    cout << "18. Vector ordenado: ";
    printArray(v18, 6);
    cout << "\n";

    // Prueba 19
    int v19[] = {2, 4, 6, 8, 10, 12, 14};
    cout << "19. Indice encontrado (10): " << binarySearchRec(v19, 0, 6, 10) << "\n";

    // Prueba 20
    int v20[] = {4, 7, 4, 2, 7, 9, 2, 5};
    int n20 = 8;
    removeDuplicates(v20, n20);
    cout << "20. N nuevo: " << n20 << "; vector logico: ";
    printArray(v20, n20);
    cout << "\n";

    // Prueba 21
    int v21[] = {1, 2, 3, 4, 5, 6};
    separateEvenOdd(v21, 6);
    cout << "21. Pares e impares separados: ";
    printArray(v21, 6);
    cout << "\n";

    return 0;
}