#include "distance.h"

int* creationTabAttributs(int nbAttributs)
{
    int* tabAttributs = (int*) malloc(nbAttributs*sizeof(int));
    for(int i=0; i<nbAttributs; i++)
    {
        printf("Indiquer les éléments à comparer:\n");
        scanf("%d",tabAttributs[i]);
    }
    return tabAttributs;
}

float somme(int nbAttributs,logement logementI,logement logementATester,int* tabAttributs)
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
                    sum  += (logementATester.bathrooms-logementI.bathrooms)*(logementATester.bathrooms-logementI.bathrooms);
                    break;
                case 4:
                    sum  += (logementATester.beds-logementI.beds)*(logementATester.beds-logementI.beds);
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
                    break;
            }
        }
        return sum;
}



void distance(int nbAttributs,logement* tableau, int tailleTableau, logement logementATester)
{
    int* tabAttributs = creationTabAttributs(nbAttributs);
    for (int i=0; i<tailleTableau; i++)
    {
        logement logementI = tableau[i];
        float sum = somme(nbAttributs, logementI, logementATester, tabAttributs);
        tableau[i].distance = sqrtf(sum);
    }
}
  
