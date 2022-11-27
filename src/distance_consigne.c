#include "distance.h"
/*Le programme demande à l'utlisateur de rentrer un entier correspondant à l'attribut qu'il souhaite comparé pour calculer la distance, 
il calcule ensuite cette distance et la rentre dans le champ distance de chaque logement du tableau*/

int attributComp()
/*Demande de l'attribut à comparer*/
{
    int attributComp;
    printf("Indiquer l'élément à comparer:\n");
    scanf("%d",&attributComp);
    return attributComp;
}

float distance_aux(logement logementI,logement logementATester,int attribut)
/*Calcul de la distance*/
{
    float dist = 0;
    switch (attribut)
    {
            case 1:
                dist += (logementATester.accommodates-logementI.accommodates)*(logementATester.accommodates-logementI.accommodates);
                break;
            case 2:
                dist += (logementATester.bedrooms-logementI.bedrooms)*(logementATester.bedrooms-logementI.bedrooms);
                break;
            case 3:
                dist += (logementATester.bathrooms-logementI.bathrooms)*(logementATester.bathrooms-logementI.bathrooms);
                break;
            case 4:
                dist += (logementATester.beds-logementI.beds)*(logementATester.beds-logementI.beds);
                break;
            case 5:
                dist += (logementATester.minimum_nights-logementI.minimum_nights)*(logementATester.minimum_nights-logementI.minimum_nights);
                break;
            case 6:
                dist += (logementATester.maximum_nights-logementI.maximum_nights)*(logementATester.maximum_nights-logementI.maximum_nights);
                break;
            case 7:
                dist += (logementATester.number_of_reviews-logementI.number_of_reviews)*(logementATester.number_of_reviews-logementI.number_of_reviews);
                break;
            default:
                printf("Erreur");
                break;
        }
        return sqrt(dist);
}


void attribution_distance(logement* tableau, int tailleTableau, logement logementATester)
/*Attribution des distances aux différents logements*/
{   
    int attribut = (int*) attributComp();
    for (int i=0; i<tailleTableau; i++)
    {
        logement logementI = tableau[i];
        tableau[i].distance = distance_aux(logementI,logementATester,attribut);
    }
}
  
