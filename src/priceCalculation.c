#include "priceCalculation.h"

int inputNbLogementComp() {
    int nbLogementComp = 0;

    printf("Veuiller entrer le nombre de logement(s) avec lesquels vous voulez calculer le prix : ");
    nbLogementComp = saisieEntier(NULL);

    return nbLogementComp;
}

float priceCalculationAux(logement* tab, int nbLogementComp) {
    float price = 0;
    
    for(int i = 0; i<nbLogementComp; i++) {
        price+=tab[i].price;
    }
    
    return price/nbLogementComp;
}

float priceCalculation(logement* tab, int tailleTab) {
    int nbLogementComp = inputNbLogementComp();
    float price = priceCalculationAux(tab, nbLogementComp);
    return price;
}