#include "createArrayFromFile.h"

int numberLines() {
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

logement* createArray(int* tailleTab) {
    *tailleTab = numberLines();
    logement* tableau = (logement*) malloc(*tailleTab * sizeof(logement));

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

            // voir s'il y a moyen de faire plus proprement ici
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

            tableau[numLigne].distance = -1;

            numLigne++;
        }
    }

    fclose(file);

    return tableau;
}