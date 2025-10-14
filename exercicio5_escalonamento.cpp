/*Exercício 5 — Escalonamento
Use novamente o cálculo de a[i] = x[i]^2 + y[i]^2 + z[i]^2, mas:
a) Execute com schedule(static) e schedule(dynamic, 1000).
b) Compare os tempos em diferentes quantidades de threads (2, 4, 8).
c) Explique em quais situações static e dynamic são mais adequados.*/

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

    int threads[3] = {2, 4, 8};

    for (int t : threads) {
        omp_set_num_threads(t);
        cout << "\nExecutando com " << t << " threads:" << endl;

        double inicio = omp_get_wtime();
        #pragma omp parallel for schedule(static)
        for (int i = 0; i < N; i++) {
            a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
        }
        double fim = omp_get_wtime();
        cout << "Tempo com schedule(static): " << fim - inicio << " segundos." << endl;

        inicio = omp_get_wtime();
        #pragma omp parallel for schedule(dynamic, 1000)
        for (int i = 0; i < N; i++) {
            a[i] = pow(x[i], 2) + pow(y[i], 2) + pow(z[i], 2);
        }
        fim = omp_get_wtime();
        cout << "Tempo com schedule(dynamic, 1000): " << fim - inicio << " segundos." << endl;
    }

    cout << "\nO escalonamento static é mais eficiente quando a carga de trabalho é uniforme entre as threads, "
            "enquanto o dynamic é melhor quando há desequilíbrio no processamento." << endl;

    delete[] x;
    delete[] y;
    delete[] z;
    delete[] a;

    return 0;
}
