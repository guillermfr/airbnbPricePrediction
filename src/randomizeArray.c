#include "randomizeArray.h"

void randomizeArray(logement* tableau, int tailleTab) {
    int j = 0;

    for(int i = 0; i<tailleTab; i++) {
        j = i + rand() / (RAND_MAX / (tailleTab-i)+1);
        logement t = tableau[j];
        tableau[j] = tableau[i];
        tableau[i] = t;
    }
}