#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "includes.h"
#include "defines.h"

typedef struct logement logement;
struct logement
{
    float number;
    float accommodates;
    float bedrooms;
    float bathrooms;
    float beds;
    float price;
    float minimum_nights;
    float maximum_nights;
    float number_of_reviews;
    float tabDistance[TAILLETABDISTANCE];
};

#endif