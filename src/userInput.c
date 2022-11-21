#include "userInput.h"

void viderBuffer() {
    int c = 0;
    while(c != '\n' && c != EOF) {
        c = getchar();
    }
}

int saisieEntier1to8() {
    char numChar[3];
    int erreur;

    do {
        erreur = 0;
        printf("Veuillez saisir un entier : ");        
        fgets(numChar, 3, stdin);
        if(!((numChar[0]>='1') && (numChar[0]<='8')) || numChar[1] != '\n') {
            if(numChar[0] == '\n') erreur = 2;
            else if(numChar[1] != '\n') erreur = 1;
            else erreur = 2;
        }
        if(erreur != 0) {
            printf("La valeur entrée n'est pas un entier !\n");
            if(erreur == 1) viderBuffer();
        }
    } while(erreur != 0);
    return(atoi(numChar));
}