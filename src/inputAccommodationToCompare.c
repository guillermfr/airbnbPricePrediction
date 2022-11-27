#include "inputAccommodationToCompare.h"

/*
    Lit les informations sur le logement à comparer
    @return Logement contenant les informations entrées
*/
logement inputAccomodation() {
    logement accommodationToCompare;

    printf("Veuillez entrer les informations liées au logement à comparer :\n");
    accommodationToCompare.accommodates = saisieEntier("accommodates");
    accommodationToCompare.bedrooms = saisieEntier("bedrooms");
    accommodationToCompare.bathrooms = saisieEntier("bathrooms");
    accommodationToCompare.beds = saisieEntier("beds");
    accommodationToCompare.minimum_nights = saisieEntier("minimum_nights");
    accommodationToCompare.maximum_nights = saisieEntier("maximum_nights");

    accommodationToCompare.number = -1;
    accommodationToCompare.price = -1;
    accommodationToCompare.number_of_reviews = -1;
    accommodationToCompare.distance = -1;
    for(int i = 0; i<3; i++) {
        accommodationToCompare.tabDistances[i] = -1;
    }

    return accommodationToCompare;
}