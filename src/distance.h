#ifndef DISTANCE_H
#define DISTANCE_H

#include "includes.h"
#include "defines.h"
#include "structures.h"

#include "userInput.h"

// Déclaration du prototype des fonctions
int verifDoublonTabAttributs(int* tabAttributs, int i);
int* creationTabAttributs(int nbAttributs);
void distance(logement* tableau, int tailleTableau, logement logementATester);
float distance_aux(int* tabAttributs, int nbAttributs, logement logementI, logement logementATester);

#endif