#include <iostream>
#include <omp.h>
#include <cmath>
using namespace std;

int main() {
    const int N = 1000000;
    double *x = new double[N];
    double *y = new double[N];
    double *z = new double[N];
    double *a = new double[N];

    // Inicializo os vetores
    for (int i = 0; i < N; i++) {
        x[i] = i * 0.001;
        y[i] = i * 0.002;
        z[i] = i * 0.003;
    }

    double inicio = omp_get_wtime();
    // Versão sequencial
    for (int i = 0; i < N; i++) {
        a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
    }
    double fim = omp_get_wtime();
    cout << "Tempo sequencial: " << fim - inicio << " segundos." << endl;

    inicio = omp_get_wtime();
    // Versão paralela
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) {
        a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
    }
    fim = omp_get_wtime();
    cout << "Tempo paralelo: " << fim - inicio << " segundos." << endl;

    delete[] x;
    delete[] y;
    delete[] z;
    delete[] a;

    return 0;
}