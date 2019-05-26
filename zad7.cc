include <omp.h>
#include <iostream>
#include <string>
using namespace std;

int main () {

string buf;
char c = 'a';

// Stworz i zainicjalizuj obiekt typu
// omp_lock_t
// Nastepnie zabezpiecz za jego pomoca
// operacje w sekcjach, na koniec
// zwolnij zasoby obiektu omp_lock_t

omp_lock_t locka, lockb;

omp_init_lock(&locka);
omp_init_lock(&lockb);

#pragma omp parallel num_threads(2)
{
    #pragma omp sections nowait
    {
       #pragma omp section
       {
	  omp_set_lock(&locka);
          buf += c++;
	  omp_unset_lock(&locka);
	  omp_set_lock(&lockb);
          buf += c++;
	  omp_unset_lock(&lockb);
       }

       #pragma omp section
       {
	  omp_set_lock(&locka);
          buf += c++;
	  omp_unset_lock(&locka);
	  omp_set_lock(&lockb);
          buf += c++;
	  omp_unset_lock(&lockb);
       }
    }
}

cout << buf << endl;
// abcd
}
