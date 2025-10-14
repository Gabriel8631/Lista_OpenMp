#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    const int N = 100;
    int v[N];
    int soma_seq = 0, soma_par = 0;

    // Inicializo todos os elementos do vetor com 1
    for (int i = 0; i < N; i++) {
        v[i] = 1;
    }

    // Soma sequencial
    for (int i = 0; i < N; i++) {
        soma_seq += v[i];
    }

    // Soma paralela com reduction
    #pragma omp parallel for reduction(+:soma_par)
    for (int i = 0; i < N; i++) {
        soma_par += v[i];
    }

    cout << "Soma sequencial: " << soma_seq << endl;
    cout << "Soma paralela: " << soma_par << endl;
    cout << "A diretiva reduction é necessária para evitar condições de corrida." << endl;

    return 0;
}
