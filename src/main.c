#include "header.h"

int nombreLignes() {
    FILE* file = fopen(FILE_NAME, "r");

    if(file == NULL) {
        printf("Error handling\n");
    }

    char* line;
    size_t len = 0;
    ssize_t nbCharLigne;
    int nbLigne = 0;

    while((nbCharLigne = getline(&line, &len, file)) != -1) {
        nbLigne++;
    }

    fclose(file);

    return nbLigne-1;
}

void afficherElement(logement* tableau, int index, int tailleTab) {
    if(index == -1) {
        for(int i = 0; i<tailleTab; i++) {
            printf("%d. number : %f, ", i, tableau[i].number);
            printf("accomodates : %f, ", tableau[i].accommodates);
            printf("bedrooms : %f, ", tableau[i].bedrooms);
            printf("baths : %f, ", tableau[i].bathrooms);
            printf("beds : %f, ", tableau[i].beds);
            printf("price : %f, ", tableau[i].price);
            printf("minNights : %f, ", tableau[i].minimum_nights);
            printf("maxNights : %f, ", tableau[i].maximum_nights);
            printf("nbReviews : %f, ", tableau[i].number_of_reviews);
            printf("\n");
        }
    } else {
        printf("%d. number : %f, ", index, tableau[index].number);
        printf("accomodates : %f, ", tableau[index].accommodates);
        printf("bedrooms : %f, ", tableau[index].bedrooms);
        printf("baths : %f, ", tableau[index].bathrooms);
        printf("beds : %f, ", tableau[index].beds);
        printf("price : %f, ", tableau[index].price);
        printf("minNights : %f, ", tableau[index].minimum_nights);
        printf("maxNights : %f, ", tableau[index].maximum_nights);
        printf("nbReviews : %f, ", tableau[index].number_of_reviews);
        printf("\n");
    }
}

int main(int argc, char** argv) {

    int tailleTab = nombreLignes();
    logement* tableau = (logement*) malloc(tailleTab * sizeof(logement));

    FILE* file = fopen(FILE_NAME, "r");

    if(file == NULL) {
        printf("Error handling\n");
    } else printf("File opened correctly !\n");

    char* line;
    size_t len = 0;
    ssize_t nbCharLigne;
    int numLigne = 0;

    char* buf;
    char** bp;
    char* strToken;

    nbCharLigne = getline(&line, &len, file);
    if(nbCharLigne != -1) {
        while((nbCharLigne = getline(&line, &len, file)) != -1) {

            buf = strdup(line);
            if(buf == NULL) {
                printf("ERROR\n");
                exit(EXIT_FAILURE);
            }
            bp = &buf;

            strToken = strsep(bp, ",");
            tableau[numLigne].number = strtof(strToken, NULL);

            strToken = strsep(bp, ",");
            tableau[numLigne].accommodates = strtof(strToken, NULL);

            strToken = strsep(bp, ",");
            tableau[numLigne].bedrooms = strtof(strToken, NULL);

            strToken = strsep(bp, ",");
            tableau[numLigne].bathrooms = strtof(strToken, NULL);

            strToken = strsep(bp, ",");
            tableau[numLigne].beds = strtof(strToken, NULL);

            strToken = strsep(bp, ",");
            tableau[numLigne].price = strtof(strToken, NULL);

            strToken = strsep(bp, ",");
            tableau[numLigne].minimum_nights = strtof(strToken, NULL);

            strToken = strsep(bp, ",");
            tableau[numLigne].maximum_nights = strtof(strToken, NULL);

            strToken = strsep(bp, ",");
            tableau[numLigne].number_of_reviews = strtof(strToken, NULL);

            numLigne++;
        }
    }

    afficherElement(tableau, -1, tailleTab);

    fclose(file);

    return 0;
}