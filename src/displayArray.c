#include "displayArray.h"

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

void display(logement* tableau, int index, int tailleTab) {
    if(index == -1) {
        for(int i = 0; i<tailleTab; i++) {
            displayElement(i, tableau[i]);
        }
    } else {
        displayElement(index, tableau[index]);
    }
}