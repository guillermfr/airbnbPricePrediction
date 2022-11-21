#include "userInput.h"

// REVOIR LES PRINTF ICI

void viderBuffer() {
    int c = 0;
    while(c != '\n' && c != EOF) {
        c = getchar();
    }
}

// a revoir
int saisieEntier1to7() {
    char numChar[3];
    int erreur;

    do {
        erreur = 0;
        printf("Veuillez saisir un entier : ");        
        fgets(numChar, 3, stdin);
        if(!((numChar[0]>='1') && (numChar[0]<='7')) || numChar[1] != '\n') {
            if(numChar[0] == '\n') erreur = 2;
            else if(numChar[1] != '\n') erreur = 1;
            else erreur = 2;
        }
        if(erreur != 0) {
            printf("La valeur entrée n'est pas un entier correct !\n");
            if(erreur == 1) viderBuffer();
        }
    } while(erreur != 0);
    return(atoi(numChar));
}

// Ajouter une gestion erreur
int saisieEntier(char nomAttribut[]) {
    char numChar[10];
    int erreur;

    do {
        erreur = 0;
        printf("Veuillez saisir la valeur de l'attribut \"%s\" : ", nomAttribut);        
        fgets(numChar, 10, stdin);

        // printf("chaine : %s, taille : %ld\n", numChar, strlen(numChar));

        for(int i = 0; i<strlen(numChar)-1; i++) {
            if(!((numChar[i]>='0') && (numChar[i]<='9'))) {
                erreur = 2;
            }
        }
        if(numChar[strlen(numChar)-1] != '\n') {
            if(getchar() != '\n') erreur = 1;
        }
        else if(numChar[0] == '\n') erreur = 2;

        if(erreur != 0) {
            printf("La valeur entrée n'est pas un entier correct !\n");
            if(erreur == 1) viderBuffer();
        }
    } while(erreur != 0);

    return(atoi(numChar));
}