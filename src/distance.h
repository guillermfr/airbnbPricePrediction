#ifndef DISTANCE_H
#define DISTANCE_H

#include "includes.h"
#include "defines.h"
#include "structures.h"

float distance_aux(logement logementI,logement logementATester,int attribut);
void attribution_distance(logement* tableau, int tailleTableau, logement logementATester);
int attributComp();

#endif