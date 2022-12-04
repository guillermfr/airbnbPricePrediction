#include "priceCalculation.h"

/*
    Demande à l'utilisateur le nombre de logements à comparer, puis le renvoie
    @param tailleTab Taille du tableau de logement
    @return Nombre de logement à comparer
*/
int inputNbLogementComp(int tailleTab) {
    int nbLogementComp = 0;

    printf("Veuiller entrer le nombre de logements avec lesquels vous voulez calculer le prix : ");
    nbLogementComp = saisieEntier(1, tailleTab);
    while(nbLogementComp < 1) {
        printf("La valeur entrée n'est pas correcte, veuillez réessayer : ");
        nbLogementComp = saisieEntier(1, tailleTab);
    }

    return nbLogementComp;
}

/*
    Calcule le prix en fonctions du nombre de logements à comparer
    @param tab Tableau des logements
    @param nbLogementComp Nombre de logements à comparer
    @return Moyenne des prix des nbLogementComp premiers logements entrés
*/
float priceCalculationAux(logement* tab, int nbLogementComp) {
    float price = 0;
    
    for(int i = 0; i<nbLogementComp; i++) {
        price+=tab[i].price;
    }
    
    return price/nbLogementComp;
}

/*
    Rassemble la fonction permettant de demander à l'utilisateur le nombre de logements à comparer et celle calculant la moyenne de prix
    @param tab Tableau des logements
    @param tailleTab Taille du tableau de logements
    @return Prix moyen prédit
*/
float priceCalculation(logement* tab, int tailleTab) {
    int nbLogementComp = inputNbLogementComp(tailleTab);
    float price = priceCalculationAux(tab, nbLogementComp);
    return price;
}