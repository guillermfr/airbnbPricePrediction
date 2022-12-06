#ifndef TRI_FUSION_H
#define TRI_FUSION_H

#include "includes.h"
#include "defines.h"
#include "structures.h"

// Déclaration du prototype des fonctions
void fusion(logement* tab, logement aux[], int tailleTab, int begin, int mid, int end);
void triFusionAux(logement* tab, logement aux[], int tailleTab, int begin, int end);
void triFusion(logement* tab, int tailleTab);
int verifTri(logement* tab, int tailleTab);

#endif