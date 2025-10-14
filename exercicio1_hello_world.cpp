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