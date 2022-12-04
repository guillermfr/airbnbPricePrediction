#include "header.h"

int main(int argc, char** argv) {

    srand(time(NULL));
    CLEAR_CONSOLE

    int tailleTab;
    logement* tableau;

    tableau = createArray(&tailleTab);

    logement logementAComparer = inputAccomodation();

    distance(tableau, tailleTab, logementAComparer);

    randomizeArray(tableau, tailleTab);
    triFusion(tableau, tailleTab);

    printf("Le tableau a été trié par ordre de distance croissante.\n");

    float price = priceCalculation(tableau, tailleTab);

    printf("Le prix ainsi calculé est de %.2f€.\n", price);

    free(tableau);
    
    return 0;
}