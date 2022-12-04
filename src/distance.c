#include "distance.h"

/*
    Permet de vérifier si un attribut entré est déjà dans le tableau ou non
    @param tabAttributs Tableau contenant les attributs à comparer déjà entrés
    @param i Index de l'élément ajouté le plus récent, pour lequel il faut vérifier s'il est déjà dans le tableau
    @return 1 si l'attribut est déjà dans le tableau, 0 sinon
*/
int verifDoublonTabAttributs(int* tabAttributs, int i) {
    for(int j = 0; j<i; j++) {
        if(tabAttributs[i] == tabAttributs[j]) return 1;
    }
    return 0;
}

/*
    Crée un tableau contenant les indices des attributs que l'utilisateur veut utiliser dans le calcul de distance
    @return Tableau contenant les indices des attributs à comparer
*/
int* creationTabAttributs(int nbAttributs)
{
    int* tabAttributs = (int*) malloc(nbAttributs*sizeof(int));

    if(nbAttributs == 6) {
        for(int i = 0; i<6; i++) {
            tabAttributs[i] = i+1;
        }
    } else {
        for(int i=0; i<nbAttributs; i++) {
            CLEAR_CONSOLE
            AFFICHAGE_ATTRIBUTS_COMPARER
            printf("\nIndiquer les éléments à comparer :\n\n");

            printf("Attribut n°%d : ", i+1);
            tabAttributs[i] = saisieEntier(1,6);
            while(tabAttributs[i] < 1 || verifDoublonTabAttributs(tabAttributs, i)) {
                printf("La valeur entrée n'est pas correcte, veuillez réessayer, attribut n°%d : ", i+1);
                tabAttributs[i] = saisieEntier(1, 6);
            }
        }
    }

    return tabAttributs;
}

/*
    Fait le calcul de distance quadratique entre le logement de l'utilisateur et un logement du tableau de données
    @param tabAttributs Tableau des attributs à comparer
    @param nbAttributs Nombre d'attributs à comparer
    @param logementI Logement à la position i dans le tableau de logements
    @param logementATester Logement à comparer entré par l'utilisateur
    @return Valeur de la distance
*/

float distance_aux(int* tabAttributs, int nbAttributs, logement logementI, logement logementATester)
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
    @param tableau Tableau des logements venant du fichier
    @param tailleTableau Taille du tableau
    @param logementATester Logement entré par l'utilisateur
*/
void distance(logement* tableau, int tailleTableau, logement logementATester)
{

    int nbAttributs;
    CLEAR_CONSOLE
    AFFICHAGE_ATTRIBUTS_COMPARER
    printf("\nVeuillez entrer le nombre d'attributs que vous voulez comparer : ");
    nbAttributs = saisieEntier(1, 6);
    while(nbAttributs < 1) {
        printf("La valeur entrée n'est pas correcte, veuillez réessayer : ");
        nbAttributs = saisieEntier(1, 6);
    }

    int* tabAttributs = creationTabAttributs(nbAttributs);

    for (int i=0; i<tailleTableau; i++)
    {
        tableau[i].distance = distance_aux(tabAttributs, nbAttributs, tableau[i], logementATester);
        printf("%d. %f\n", i, tableau[i].distance);
    }

    CLEAR_CONSOLE

    free(tabAttributs);

}
  