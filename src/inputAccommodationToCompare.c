#include "inputAccommodationToCompare.h"

/*
    Lit les informations sur le logement à comparer
    @return Logement contenant les informations entrées
*/
logement inputAccomodation() {
    logement accommodationToCompare;

    printf("Veuillez entrer les informations liées au logement à comparer :\n");

    printf("Nombre de logements : ");
    accommodationToCompare.accommodates = saisieEntier(0, 0);
    while(accommodationToCompare.accommodates < 1) {
        printf("La valeur entrée n'est pas correcte, veuillez réessayer : ");
        accommodationToCompare.accommodates = saisieEntier(0, 0);
    }

    printf("\e[1;1H\e[2J");

    printf("Nombre de chambres : ");
    accommodationToCompare.bedrooms = saisieEntier(0, 0);
    while(accommodationToCompare.bedrooms < 1) {
        printf("La valeur entrée n'est pas correcte, veuillez réessayer : ");
        accommodationToCompare.bedrooms = saisieEntier(0, 0);
    }

    printf("Nombre de salles de bain : ");
    accommodationToCompare.bathrooms = saisieEntier(0, 0);
    while(accommodationToCompare.bathrooms < 1) {
        printf("La valeur entrée n'est pas correcte, veuillez réessayer : ");
        accommodationToCompare.bathrooms = saisieEntier(0, 0);
    }
    
    printf("Nombre de lits : ");
    accommodationToCompare.beds = saisieEntier(0, 0);
    while(accommodationToCompare.beds < 1) {
        printf("La valeur entrée n'est pas correcte, veuillez réessayer : ");
        accommodationToCompare.beds = saisieEntier(0, 0);
    }

    printf("Nombre minimum de nuits : ");
    accommodationToCompare.minimum_nights = saisieEntier(0, 0);
    while(accommodationToCompare.minimum_nights < 1) {
        printf("La valeur entrée n'est pas correcte, veuillez réessayer : ");
        accommodationToCompare.minimum_nights = saisieEntier(0, 0);
    }

    printf("Nombre maximum de nuits : ");
    accommodationToCompare.maximum_nights = saisieEntier(0, 0);
    while(accommodationToCompare.maximum_nights < 1 || accommodationToCompare.maximum_nights < accommodationToCompare.minimum_nights) {
        if(accommodationToCompare.maximum_nights < accommodationToCompare.minimum_nights) printf("Le nombre maximal de nuits doit être supérieur au nombre minimal de nuits, veuillez réessayer : ");
        else printf("La valeur entrée n'est pas correcte, veuillez réessayer : ");
        accommodationToCompare.maximum_nights = saisieEntier(0, 0);
    }

    accommodationToCompare.number = -1;
    accommodationToCompare.price = -1;
    accommodationToCompare.number_of_reviews = -1;
    accommodationToCompare.distance = -1;
    for(int i = 0; i<3; i++) {
        accommodationToCompare.tabDistances[i] = -1;
    }

    return accommodationToCompare;
}