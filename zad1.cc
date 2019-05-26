include <omp.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Najpierw skompiluj i uruchom ponizszy kod.
// Tak zmodyfikuj blok rownolegly, zeby wczytana
// z pliku test.txt zawartosc byla poprawna.

int main () {

    fstream plik("test.txt");
    string tmp, buf;

#pragma omp parallel num_threads(4)
{
    while ( getline( plik, tmp ) ) {
        buf += tmp + '\n';
    }
}

cout << buf << endl;

}

