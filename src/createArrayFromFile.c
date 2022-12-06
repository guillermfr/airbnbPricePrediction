#include "createArrayFromFile.h"

/*
    Détermine le nombre de ligne du fichier
    @return Nombre de lignes du fichier
*/
int numberLines() {

    // Ouverture du fichier et vérification 
    FILE* file = fopen(FILE_NAME, "r");
    if(file == NULL) {
        printf("Erreur lors de l'ouverture du fichier, fin du programme.\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation des variables nécessaires
    char* line;
    size_t len = 0;
    ssize_t nbCharLigne;
    int nbLigne = 0;

    // On compte le nombre de lignes qu'il y a dans le fichier
    while((nbCharLigne = getline(&line, &len, file)) != -1) {
        nbLigne++;
    }

    // Fermeture du fichier
    fclose(file);

    // On renvoie le nombre de lignes moins 1, pour la première ligne que l'on ne compte pas
    return nbLigne-1;
}

/*
    Créer le tableau contenant les logements du fichier correspondant
    @param tailleTab Taille du tableau de logements, ici entré en pointeur car on veut le récupérer
    @return Tableau de logements
*/
logement* createArray(int* tailleTab) {

    // On récupère le nombre de lignes du fichier et on alloue de la mémoire pour le tableau de logements, en fonction du nombre de lignes
    *tailleTab = numberLines();
    logement* tableau = (logement*) malloc(*tailleTab * sizeof(logement));

    // Ouverture du fichier et vérification
    FILE* file = fopen(FILE_NAME, "r");
    if(file == NULL) {
        printf("Erreur lors de l'ouverture du fichier, fin du programme.\n");
        exit(EXIT_FAILURE);
    }

    // Initialisation des variables nécessaires
    char* line;
    size_t len = 0;
    ssize_t nbCharLigne;
    int numLigne = 0;

    char* buf;
    char** bp;
    char* strToken;

    // Lecture du fichier ligne par ligne
    // Chaque ligne est stockée dans la variable line
    nbCharLigne = getline(&line, &len, file);
    if(nbCharLigne != -1) {
        while((nbCharLigne = getline(&line, &len, file)) != -1) {

            // On doit dupliquer la ligne lue, on vérifie si la fonction s'est bien exécutée
            buf = strdup(line);
            if(buf == NULL) {
                printf("ERROR\n");
                exit(EXIT_FAILURE);
            }
            bp = &buf;

            // On lit chaque champs 1 par 1 et on les stocks dans la structure logement

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