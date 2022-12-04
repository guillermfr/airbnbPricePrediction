#include "distance.h"

/*
    Crée un tableau contenant les indices des attributs que l'utilisateur veut utiliser dans le calcul de distance
    @return Tableau contenant ces indices
*/
int* creationTabAttributs(int nbAttributs)
{
    int* tabAttributs = (int*) malloc(nbAttributs*sizeof(int));
    printf("Indiquer les éléments à comparer:\n");
    for(int i=0; i<nbAttributs; i++)
    {
        tabAttributs[i] = saisieEntier(1,7);
    }
    return tabAttributs;
}

/*
    Fait le calcul de distance quadratique entre le logement de l'utilisateur et un logement du tableau de données
    @return Valeur de la distance
*/

float distance_aux(int nbAttributs,logement logementI,logement logementATester,int* tabAttributs)
{
        float sum = 0;
        for (int j; j<nbAttributs; j++)
        {
            switch (tabAttributs[j])
            {
                case 1:
                    sum += (logementATester.accommodates-logementI.accommodates)*(logementATester.accommodates-logementI.accommodates);
                    break;
                case 2:
                    sum += (logementATester.bedrooms-logementI.bedrooms)*(logementATester.bedrooms-logementI.bedrooms);
                    break;
                case 3:
                    sum += (logementATester.bathrooms-logementI.bathrooms)*(logementATester.bathrooms-logementI.bathrooms);
                    break;
                case 4:
                    sum += (logementATester.beds-logementI.beds)*(logementATester.beds-logementI.beds);
                    break;
                case 5:
                    sum += (logementATester.minimum_nights-logementI.minimum_nights)*(logementATester.minimum_nights-logementI.minimum_nights);
                    break;
                case 6:
                    sum += (logementATester.maximum_nights-logementI.maximum_nights)*(logementATester.maximum_nights-logementI.maximum_nights);
                    break;
                case 7:
                    sum += (logementATester.number_of_reviews-logementI.number_of_reviews)*(logementATester.number_of_reviews-logementI.number_of_reviews);
                    break;
                default:
                    printf("Erreur");
                    exit(0);
                    break;
            }
        }
        return sqrtf(sum);
}

/*
    Attribue à chaque logement du tableau la distance entre ce logement et celui de l'utilisateur
*/

void distance(int nbAttributs,logement* tableau, int tailleTableau, logement logementATester)
{
    int* tabAttributs = creationTabAttributs(nbAttributs);
    for (int i=0; i<tailleTableau; i++)
    {
        logementI.distance = distance_aux(nbAttributs, tableau[i], logementATester, tabAttributs);
    }
}
  
