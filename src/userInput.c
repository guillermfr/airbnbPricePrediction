#include "userInput.h"

// REVOIR LES PRINTF ICI
/*
    Vide le buffer
*/
void viderBuffer() {
    int c = 0;
    while(c != '\n' && c != EOF) {
        c = getchar();
    }
}

// a revoir
// à utiliser seulement pour les nombres à 1 chiffre
/*
    Permet d'entrer un nombre entier composé d'un seul chiffre, sur un intervalle donné
    @param x Première borne de l'intervalle
    @param y Seconde borne de l'intervalle
    @return Entier entré
*/
int saisieEntierXtoY(int x, int y) {

    if(!(x>=0 && y>=0 && x<=9 && y<=9)) {
        return -1;
    }

    char X = x + '0';
    char Y = y + '0';

    char numChar[3];
    int erreur;

    do {
        erreur = 0;
        printf("Veuillez saisir un entier : ");        
        fgets(numChar, 3, stdin);
        if(!((numChar[0]>=X) && (numChar[0]<=Y)) || numChar[1] != '\n') {
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
/*
    Permet d'entrer un nombre entier
    @param nomAttribut[] Nom de l'attribut demandé en entrée, si la valeur entrée est égale à NULL, il n'y aura pas de demande à l'utilisateur pour entrer le nombre
    @return Entier entré
*/
int saisieEntier(char nomAttribut[]) {
    char numChar[10];
    int erreur;

    do {
        erreur = 0;
        if(nomAttribut != NULL) printf("Veuillez saisir la valeur de l'attribut \"%s\" : ", nomAttribut);        
        fgets(numChar, 10, stdin);

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