#include <iostream>
#include <iomanip>
using namespace std;

// 05. Contar números pares
int countEvens(int v[], int n) {
    if (n == 0) return 0;
    int isEven = (v[n - 1] % 2 == 0) ? 1 : 0;
    return isEven + countEvens(v, n - 1);
}

// 06. Contar positivos, negativos y ceros
void countSigns(int v[], int n, int &pos, int &neg, int &zeros) {
    if (n == 0) return;
    if (v[n - 1] > 0) pos++;
    else if (v[n - 1] < 0) neg++;
    else zeros++;
    countSigns(v, n - 1, pos, neg, zeros);
}

// Función auxiliar de suma (del ejercicio 04) para el promedio
int sumArray(int v[], int n) {
    if (n == 0) return 0;
    return v[n - 1] + sumArray(v, n - 1);
}

// 07. Calcular el promedio (N > 0)
double calculateAverage(int v[], int n) {
    return (double)sumArray(v, n) / n;
}

// 08. Contar múltiplos de un número (K != 0)
int countMultiples(int v[], int n, int k) {
    if (n == 0) return 0;
    int isMultiple = (v[n - 1] % k == 0) ? 1 : 0;
    return isMultiple + countMultiples(v, n - 1, k);
}

int main() {
    // Prueba 05
    int v5[] = {3, 8, 10, 7, 2, 5, 6};
    cout << "05. Cantidad de pares: " << countEvens(v5, 7) << "\n";

    // Prueba 06
    int v6[] = {-2, 0, 5, -7, 3, 0, 1};
    int pos = 0, neg = 0, zeros = 0;
    countSigns(v6, 7, pos, neg, zeros);
    cout << "06. Positivos: " << pos << "; negativos: " << neg << "; ceros: " << zeros << "\n";

    // Prueba 07
    int v7[] = {12, 14, 16, 18};
    cout << fixed << setprecision(2);
    cout << "07. Promedio: " << calculateAverage(v7, 4) << "\n";

    // Prueba 08
    int v8[] = {6, 10, 12, 15, 18, 21};
    int k = 3;
    cout << "08. Multiplos de " << k << ": " << countMultiples(v8, 6, k) << "\n";

    return 0;
}
