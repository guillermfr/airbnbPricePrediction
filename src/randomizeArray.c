#include "randomizeArray.h"

/*
    Mélange le tableau de logements
    @param tableau Tableau des logements
    @param tailleTab Taille du tableau
*/
void randomizeArray(logement* tableau, int tailleTab) {
    int j = 0;

    for(int i = 0; i<tailleTab; i++) {
        j = i + rand() / (RAND_MAX / (tailleTab-i)+1);
        logement t = tableau[j];
        tableau[j] = tableau[i];
        tableau[i] = t;
    }
}