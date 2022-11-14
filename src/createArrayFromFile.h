#ifndef CREATE_ARRAY_FROM_FILE_H
#define CREATE_ARRAY_FROM_FILE_H

#include "includes.h"
#include "defines.h"
#include "structures.h"

int numberLines();
void initTabDistance(float tab[TAILLETABDISTANCE]);
logement* createArray(int* tailleTab);

#endif