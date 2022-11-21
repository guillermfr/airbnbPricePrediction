#include "distance.h"

void distance(int nbAttributs, logement* tableau, int tailleTableau, logement logementATester)
{
    int* tabAttributs = (int*) malloc(nbAttributs*sizeof(int));
    for(int i=0; i<nbAttributs; i++)
    {
        printf("Indiquer les éléments à comparer:\n");
        scanf("%d",tabAttributs[i]);
    }
    float somme;
    for (int i=0; i<tailleTableau; i++)
    {
        somme = 0;
        for (int j; j<nbAttributs; j++)
        {
            switch (tabAttributs[j])
            {
            case 1:
                somme += (logementATester.accommodates-tableau[i].accommodates)*(logementATester.accommodates-tableau[i].accommodates);
                break;
            case 2:
                somme += (logementATester.bedrooms-tableau[i].bedrooms)*(logementATester.bedrooms-tableau[i].bedrooms);
                break;
            case 3:
                somme += (logementATester.bathrooms-tableau[i].bathrooms)*(logementATester.bathrooms-tableau[i].bathrooms);
                break;
            case 4:
                somme += (logementATester.beds-tableau[i].beds)*(logementATester.beds-tableau[i].beds);
                break;
            case 5:
                somme += (logementATester.minimum_nights-tableau[i].minimum_nights)*(logementATester.minimum_nights-tableau[i].minimum_nights);
                break;
            case 6:
                somme += (logementATester.maximum_nights-tableau[i].maximum_nights)*(logementATester.maximum_nights-tableau[i].maximum_nights);
                break;
            case 7:
                somme += (logementATester.number_of_reviews-tableau[i].number_of_reviews)*(logementATester.number_of_reviews-tableau[i].number_of_reviews);
                break;
            default:
                printf("Erreur");
                break;
            }
        }
        tableau[i].distance = sqrt(somme);
    }
}
  