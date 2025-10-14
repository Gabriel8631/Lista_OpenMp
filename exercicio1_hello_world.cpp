/*Exercício 1 — “Hello World” Paralelo
a) Crie uma região paralela com #pragma omp parallel.
b) Cada thread deve imprimir uma mensagem indicando seu número (omp_get_thread_num()) e o total de threads (omp_get_num_threads()).
c) Configure o programa para rodar com 4 threads.*/

#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    // Configuro o número de threads para 4
    omp_set_num_threads(4);

    // Crio uma região paralela
    #pragma omp parallel
    {
        // Cada thread obtém seu número e o total de threads
        int id = omp_get_thread_num();
        int total = omp_get_num_threads();

        // Cada thread imprime uma mensagem indicando seu número
        cout << "Olá do thread " << id << " de " << total << " threads." << endl;
    }
    return 0;
}
