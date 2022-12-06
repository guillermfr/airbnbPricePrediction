#include "displayArray.h"

/*
    Affiche 1 élément de type logement
    @param index Index du l'élément dans le tableau
    @param element Logement à afficher
*/
void displayElement(int index, logement element) {
    printf("%d. number : %f, ", index, element.number);
    printf("accomodates : %f, ", element.accommodates);
    printf("bedrooms : %f, ", element.bedrooms);
    printf("baths : %f, ", element.bathrooms);
    printf("beds : %f, ", element.beds);
    printf("price : %f, ", element.price);
    printf("minNights : %f, ", element.minimum_nights);
    printf("maxNights : %f, ", element.maximum_nights);
    printf("nbReviews : %f, ", element.number_of_reviews);
    printf("distance : %f, ", element.distance);
    printf("\n");
}

/*
    Affiche des logements
    @param tableau Tableau des logements
    @param index Index du logement à afficher, -1 pour afficher tous les logements
    @param tailleTab Taille du tableau
*/
void display(logement* tableau, int index, int tailleTab) {
    if(index == -1) {
        for(int i = 0; i<tailleTab; i++) {
            displayElement(i, tableau[i]);
        }
    } else {
        // printf("index : %d\n", index);
        displayElement(index, tableau[index]);
    }
}