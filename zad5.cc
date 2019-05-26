#include <omp.h>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int timesleep[] { 1000,2000,100,500,3000,1500,2800,30,2100,1100,2900,3000,1000,2000,10,3000 };

void fun( int i ) {
  this_thread::sleep_for(chrono::milliseconds( timesleep[i] ));
}

int main () {

    auto a1 = omp_get_wtime();

    // Przetestuj rozne strategie rozdzialu iteracji petli
    // pomiedzy watki i zostaw w kodzie taka, ktora daje
    // najkrotszy czas obliczen

  #pragma omp parallel for num_threads(16)
      for (int i=0; i<16; ++i) fun(i);

    auto a2 = omp_get_wtime();

    cout << "Czas: " << a2-a1 << endl;

}

