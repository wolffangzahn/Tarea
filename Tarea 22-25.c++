#include <iostream>
using namespace std;

// Auxiliar para 22: invertir un tramo del vector
void reverseRange(int v[], int start, int end) {
    if (start >= end) return;
    int temp = v[start];
    v[start] = v[end];
    v[end] = temp;
    reverseRange(v, start + 1, end - 1);
}

// 22. Rotación circular del vector (K posiciones a la derecha sin vector auxiliar)
void rotateRight(int v[], int n, int k) {
    if (n <= 1) return;
    k = k % n;
    if (k == 0) return;
    reverseRange(v, 0, n - 1);
    reverseRange(v, 0, k - 1);
    reverseRange(v, k, n - 1);
}

// 23. Subsecuencia creciente consecutiva (longitud máxima)
int maxIncreasingSubarray(int v[], int n, int i = 1, int currentLen = 1, int maxLen = 1) {
    if (n == 0) return 0;
    if (i == n) return maxLen;
    if (v[i] > v[i - 1]) {
        currentLen++;
        if (currentLen > maxLen) maxLen = currentLen;
    } else {
        currentLen = 1;
    }
    return maxIncreasingSubarray(v, n, i + 1, currentLen, maxLen);
}

// Auxiliar para 24: obtener el máximo global
int getMax(int v[], int n) {
    if (n == 1) return v[0]; // Corregido: v[0]
    int maxRest = getMax(v, n - 1);
    return (v[n - 1] > maxRest) ? v[n - 1] : maxRest;
}

// 24. Segundo mayor distinto (sin variables globales)
void findSecondMax(int v[], int n, int maxVal, int i, int &secondMax, bool &found) {
    if (i == n) return;
    if (v[i] < maxVal) {
        if (!found || v[i] > secondMax) {
            secondMax = v[i];
            found = true;
        }
    }
    findSecondMax(v, n, maxVal, i + 1, secondMax, found);
}

// 25. Máxima suma de segmento consecutivo (Algoritmo de Kadane recursivo)
int maxSubarraySum(int v[], int n, int i = 1, int currentSum = 0, int maxSum = 0) {
    if (i == 1) {
        currentSum = v[0]; // Corregido: v[0]
        maxSum = v[0];     // Corregido: v[0]
    }
    if (i >= n) return maxSum;
    currentSum = (v[i] > currentSum + v[i]) ? v[i] : currentSum + v[i];
    if (currentSum > maxSum) maxSum = currentSum;
    return maxSubarraySum(v, n, i + 1, currentSum, maxSum);
}

// Auxiliar para imprimir
void printArray(int v[], int n, int i = 0) {
    if (i == n) return;
    cout << v[i] << " ";
    printArray(v, n, i + 1);
}

int main() {
    // Prueba 22
    int v22[] = {1, 2, 3, 4, 5};
    rotateRight(v22, 5, 2);
    cout << "22. Vector rotado: ";
    printArray(v22, 5);
    cout << "\n";

    // Prueba 23
    int v23[] = {2, 4, 7, 1, 3, 5, 6, 2, 4};
    cout << "23. Longitud maxima creciente: " << maxIncreasingSubarray(v23, 9) << "\n";

    // Prueba 24
    int v24[] = {8, 2, 8, 5, 7, 7, 1};
    int maxVal = getMax(v24, 7);
    int secondMax = 0;
    bool found = false;
    findSecondMax(v24, 7, maxVal, 0, secondMax, found);
    cout << "24. Mayor: " << maxVal << "; segundo mayor distinto: " << secondMax << "\n";

    // Prueba 25
    int v25[] = {-2, 1, -3, 4, -1, 2, 1, -5};
    cout << "25. Suma maxima de segmento: " << maxSubarraySum(v25, 8) << "\n";

    return 0;
}
