#ifndef PRICE_CALCULATION_H
#define PRICE_CALCULATION_H

#include "includes.h"
#include "defines.h"
#include "structures.h"

#include "userInput.h"

int inputNbLogementComp(int tailleTab);
float priceCalculationAux(logement* tab, int nbLogementComp);
float priceCalculation(logement* tab, int tailleTab);

#endif