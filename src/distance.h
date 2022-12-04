#ifndef DISTANCE2_H
#define DISTANCE2_H

#include "includes.h"
#include "defines.h"
#include "structures.h"

int* creationTabAttributs(int nbAttributs);
void distance(int nbAttributs, logement* tableau, int tailleTableau, logement logementATester);
float somme(int nbAttributs,logement logementI,logement logementATester,int* tabAttributs);

#endif
