#include "triFusion.h"

void fusion(logement* tab, logement aux[], int tailleTab, int begin, int mid, int end) {

    int i;
    int j;

    for(i=0; i<tailleTab; i++) {
        aux[i] = tab[i];
    }

    i = begin;
    j = mid+1;
    
    for(int k = begin; k<end+1; k++) {
        if(i>mid) {
            tab[k] = aux[j];
            j++;
        } else if (j>end) {
            tab[k] = aux[i];
            i++;            
        } else if (aux[i].distance < aux[j].distance) {
            tab[k] = aux[i];
            i++;
        } else {
            tab[k] = aux[j];
            j++;
        }        
    }
}

void triFusionAux(logement* tab, logement aux[], int tailleTab, int begin, int end) {
    if(begin<end) {
        int mid = (begin+end)/2;
        triFusionAux(tab, aux, tailleTab, begin, mid);
        triFusionAux(tab, aux, tailleTab, mid+1, end);
        fusion(tab, aux, tailleTab, begin, mid, end);
    }
}

void triFusion(logement* tab, int tailleTab) {
    logement aux[tailleTab];

    triFusionAux(tab, aux, tailleTab, 0, tailleTab-1);
}

int verifTri(logement* tab, int tailleTab) {
    int verif = 0;
    for(int i = 0; i<tailleTab-1; i++) {
        if(tab[i].distance > tab[i+1].distance) verif++;
    }
    return verif;
}