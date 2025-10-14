/*Exercício 4 — Medindo tempo por thread
Adapte o código do exercício anterior para:
a) Medir e exibir o tempo total de execução.
b) Medir e exibir o tempo gasto por cada thread.
c) Mostrar quantas threads foram utilizadas no cálculo.*/

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

    for (int i = 0; i < N; i++) {
        x[i] = i * 0.001;
        y[i] = i * 0.002;
        z[i] = i * 0.003;
    }

    double inicio_total = omp_get_wtime();

    #pragma omp parallel
    {
        double inicio = omp_get_wtime();
        #pragma omp for
        for (int i = 0; i < N; i++) {
            a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
        }
        double fim = omp_get_wtime();
        int id = omp_get_thread_num();
        cout << "Thread " << id << " executou em " << fim - inicio << " segundos." << endl;
    }

    double fim_total = omp_get_wtime();
    cout << "Tempo total de execução: " << fim_total - inicio_total << " segundos." << endl;

    delete[] x;
    delete[] y;
    delete[] z;
    delete[] a;

    return 0;
}
