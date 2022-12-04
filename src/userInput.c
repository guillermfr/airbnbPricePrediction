#include "userInput.h"

/*
    Vide le buffer
*/
void viderBuffer() {
    int c = 0;
    while(c != '\n' && c != EOF) {
        c = getchar();
    }
}

/*
    Permet d'entrer un entier, avec la possiblité de donner un intervalle dans lequel l'entier doit être contenu
    @param x Première borne de l'intervalle
    @param y Seconde borne de l'intervalle
    @returns Retourne l'entier saisie, de type int. Il y a 5 types d'erreurs possibles : -1 si certains caractères entrés ne sont pas des entiers, 
    -2 si la chaîne entrée est trop longue, -3 si la chaîne entrée est vide, -4 si l'entier entrée est en dehors des bornes et -5 si la première 
    borne est plus grande que la seconde.
*/
int saisieEntier(int x, int y) {
    char numChar[10];
    fgets(numChar, 10, stdin);
    size_t length = strlen(numChar);
    int i;
    int retour;

    if(x > y) return -5;

    if(numChar[length-1] != '\n') {
        viderBuffer();
        return -2;
    }

    for(i = 0; i<length-1; i++) {
        if(!isdigit(numChar[i])) {
            return -1;
        }
    }
    if(i == 0) return -3;

    retour = atoi(numChar);

    if(x != y) {
        if(retour < x || retour > y) return -4;
    }

    return retour;
}